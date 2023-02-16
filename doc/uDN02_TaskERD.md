# DesNote02: Task Entity Relationship Diagram

Or rather: a structured list.

This bounds the task table.

~~~~~

num_Of_Tasks_Possible, NUM_OF_TASKS_POSSIBLE : const uint8_t
  // length of the task table

configd_Num_Of_Tasks, CONFIGD_NUM_OF_TASKS : const uint8_t
  // ...task table entries filled in.

~~~~~

The task table has an entry for each task.
Each task has:

* info block in flash 
* data block, with flash resident pointers to fifos and lists in RAM
* control block, in RAM, denoting the state of the task 
* context block, containing processor-specific info ie register, in RAM.

~~~~~

task_Tbl : NULL or TaskTblEntry, const pointer, const array [0..num_Of_Tasks_Possible]
  // index is the key
  // key is task ID number 

  NULL 
    // no entry for this task ID
      
  TaskTblEntry
    // instance naming convention is task_Entry_4_SOMENAME

    the_Info_Blk_p : TaskInfoBlk, const pointer

      TaskInfoBlk
        // instance naming convention is task_Info_Blk_4_SOMENAME and is const

        the_ID : const uint8_t 
          // TR3_TASKID_SOMENAME

        the_Pri : const uint8_t
          // TR3_TASKPRIORITY_SOMENAME

        the_Stk_Size : const uint16_t
          // TR3_TASKSTACK_SOMENAME

        the_Msg_Q_Len : const uint8_t
          // TR3_TASKMSGQLEN_SOMENAME

        the_Msg_Q_Entries_Avail_bits : const uint64_t
          // Derived from TR3_TASKMSGQLEN_SOMENAME
          // See entries used below

        the_More_Details : const uint8_t
          // bit map which includes TR3_TASKMSGQORDERING_SOMENAME

        the_Task_Data_p : void *const X
          // TR3_TASKINITDATA_SOMENAME
          // \todo what about instance-ing and extern-ing?

        the_Task_Func_p : void (*const X)(void *the_task_data_p)
          // TR3_TASKNAME_SOMENAME
          // instanced and prototyped as void (*const someFunction)(void *the_task_data_p);

    the_Data_Blk_p : TaskDataBlk, const pointer

      TaskDataBlk
        // instance naming convention is task_Data_Blk_4_SOMENAME

        the_Stk_Blk_p : uint8_t, const pointer to an array
          // instanced as uint8_t task_Stk_Blk_4_SOMENAME[TR3_TASKSTACK_SOMENAME]
          // aka the_Stk_Size
          // be sure to handle alignment on eight byte boundaries, packing

        the_Msg_Q_Entries_Used_bits_p : const uint64_t pointer
          // instanced as uint64_t task_Msg_Q_Entries_Used_bits_4_SOMENAME;
          // set bit : entry is not available 
          // clear bit : entry is available
          // most significant clear bit offset + 1 is the the message queue length
          // bits must be contiguous
          // ex:
          // bits 63..2 are set; these are not available.
          // bits 1, 0 are clear; two entries are available.
          // all bits clear; 64 entries are available.

        the_RE_p : Tr3PL_RootEle_s, const pointer
          // instanced as Tr3PL_RootEle_s task_RE_4_SOMENAME;
          // head and tail to q entries

        the_PL_p : Tr3PL_Lst_s, const pointer to array element zero
          // instanced as Tr3PL_Lst_s task_PL_4_SOMENAME[TR3_TASKMSGQLEN_SOMENAME]
          // the pri is the posting task's (priority) or same value (FIFO)
          // key is the index into the message queue

    the_Ctrl_Blk_p : TaskCtrlBlk, const pointer

      TaskCtrlBlk
        // instance naming convention is task_Ctrl_Blk_4_SOMENAME

        state_Is : Tr3S_State
          // somewhat obvious from uDN01_TaskMgmtMdl.md

        delay_Setting : uint16_t
          // see Spec04_TaskControl.md

        delay_Remaining_Is : uint16_t
          // down counter; zero is ready to run

        priority_Offset_Is : int8_t (not uint8_t)
          // zero for now; not presently used
          // negative value raise priority, positive values lower 

    the_Cntxt_Blk_p : TaskCntxtBlk, const pointer

      TaskCntxtBlk
        // instance naming convention is task_Cntxt_Blk_4_SOMENAME 

          the_Un_Saved : Tr3Ti_UnSaved
            // unsaved registers

          the_Excep_Stk_Frm : Tr3Ti_ExcepStkFrm
            // saved registers from exception or interrupt.

~~~~~

These lists are used to prioritize tasks.

~~~~~

task_Ready_RE : Tr3PL_RootEle_s
task_Ready_Lst : Tr3PL_Lst_s, array [0..configd_Num_Of_Tasks]
  // key is task ID
  // prioritized list of ready to run tasks 

task_Waiting_RE : Tr3PL_RootEle_s
task_Waiting_Lst : Tr3PL_Lst_s, array [0..configd_Num_Of_Tasks]
  // key is task ID
  // prioritized list of waiting tasks 

~~~~~

There are for reference.

~~~~~

task_ID_PrivSec : const uint8_t
task_ID_ExpInt : const uint8_t
task_ID_Kernel : const uint8_t
task_ID_SysClk : const uint8_t
task_ID_MemMan : const uint8_t
  // from Tr3ICfg.h

~~~~~

So this ends.
