# TechNote02: Tasks, Step By Step

Here's how to do it.

# Use The Usual .h/.c File Scheme

You already know how to do this.

# Define The Task's Function In .c File

Details can come later, but t must be of the form:

~~~~~{.c}
void someTaskFunction (void *the_task_data_p)
{
   // perform initialization
   while ( some condition is true, usually forever )
   {
      // do whatever the task does
      // send a message to a task 
      // receive a message
      // delay 
      // whatever is right
   }
}
~~~~~

# Prototype The Task's Function In .h File

~~~~~{.c}
void someTaskFunction (void *the_task_data_p);
~~~~~

# There's A Configuration Tool; Gets Info From .h Files

That tool is a Python script named Tr3Gen.
It scans your .h files looking for keywords.

# Some Examples

See inc/Tr3ICfg.h.  These are tasks internal to Tr3.

# Task Name: #define TR3_TASKNAME_SOMENAME #someFunction

* "#define TR3_TASKNAME_" is case-sensitive and required.
* Associates SOMENAME with someFunction.
* SOMENAME is case-sensitive; can also be someNamE.
* SOMENAME must not be reserved
  * see TN01_ArchOvrView.md
  * Tr3KernTask
  * Tr3ExpIntTask
  * Tr3SysClkTask
  * Tr3MemManTask
  * Tr3PrivSec 
  * Tr3Gen will reject reserved names.

# Task ID: #define TR3_TASKID_SOMENAME a_number 

* "#define TR3_TASKID_" is case-sensitive and required.
* Associates SOMENAME with a_number used as shorthand to ID a task.
* The value must be 1..253 and not be a reserved value.
  * see Spec08_IDPriorities.md
  * Tr3Gen will reject reserved IDs.

# Task Stack: #define TR3_TASKSTACK_SOMENAME a_number

* "#define TR3_TASKSTACK_" is case-sensitive and required.
* Associates SOMENAME with a_number specifing task's stack size.
* The value must be 8..64k
* The value must be a multiple of 8 bytes.
  * If not, will be forced to an 8 byte boundary.
* If TR3_TASKSTACK_SOMENAME is not specified, then Tr3Gen will default to 1024.

# Task Priority: #define TR3_TASKPRIORITY_SOMENAME a_number

* "#define TR3_TASKPRIORITY_" is case-sensitive and required.
* Associates SOMENAME with a_number specifing task's priority 

How Tr3Gen deals with priorities is a bit non-obvious.

* The default priority is always 96.
* If the task ID is one where ID equals priority, ie ID 1..31:
  * the priority is forced to equal the task ID
  * any priority re-definition will be ignored.
* If the task ID can accept any priority, ie ID 31..254
  * that priority is used 
  * any subsequent priority redefinition 1..31 is ignored
  * any subsequent priority redefinition 32..254 is accepted.

# Task Message Queue Length: #define TR3_TASKMSGQLEN_SOMENAME a_number 

* "#define TR3_TASKMSGQLEN_" is case-sensitive and required.
* Associates SOMENAME with a_number specifing task's max number of entries in the message queue.
* Values may be 0..64.
* The default is 1.

# Task Message Queue Ordering: #define TR3_TASKMSGQORDERING_SOMENAME 0_or_1 

* 0: present messages FIFO; the default
* 1: present messages by sending task priority, highest priority dequeued first
* any other value: forced to 0.

# Task Init Data: #define TR3_TASKINITDATA_SOMENAME #some_variable 

* "#define TR3_TASKINITDATA_" is case-sensitive and required.
* Associates SOMENAME with some_variable in memory containing task initialization data.
* At task start, will be passed as "(void *) &some_variable" to the task.
* The default is NULL pointer.

This is a bit tricky, because there's no good way pass-along types.
The suggested solution is:

~~~~~
struct MyBunchOfData {
    uint8_t a;
    uint8_t b;
};
struct MyBunchOfData the_Data_To_Pass = {
    2,
    3
};

const void *const ptr23 = &the_Data_To_Pass;

#define TR3_TASKINITDATA_THISEXAMPLE #ptr23 
~~~~~

Tr will:

~~~~~
/* assume this form */
extern const void *const ptr23;

/* store it as */
    &p23

/* pass the dereferenced pointer at start up */
thisExampe((void *) *ptr23);
~~~~~

# Inflict Tr3Gen 

It builds a data structure file needed by Tr3.

# Build and Run Your App

Watch the stuff come out.
