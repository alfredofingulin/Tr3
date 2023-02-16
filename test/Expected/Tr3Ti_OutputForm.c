/* template for testing construction not actually used */  
/* \note WHY DOES indent HATE THIS FILE SO GODDAMN MUCH? */ 
    
 
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "Tr3PL.h"
#include "Tr3ICfg.h"

#include "Tr3Ti.h"


/* ========================================================== */ 


/* Task Management */


/* ========================================================== */ 


/* Defines generated here. */


#define TR3_TASKID_SOMENAME_0 97
#define TR3_TASKPRIORITY_SOMENAME_0 98
#define TR3_TASKSTACK_SOMENAME_0 1024
#define TR3_TASKMSGQLEN_SOMENAME_0 4
#define TR3_TASKMSGQITEMS_SOMENAME_0 0xFFFFFFFFFFFFFFF0ULL
#define TR3_TASKMSGQORDERING_SOMENAME_0 1

#define TR3_TASKID_SOMENAME_1 99
#define TR3_TASKPRIORITY_SOMENAME_1 100
#define TR3_TASKSTACK_SOMENAME_1 2048
#define TR3_TASKMSGQLEN_SOMENAME_1 5
#define TR3_TASKMSGQITEMS_SOMENAME_1 0xFFFFFFFFFFFFFFE0ULL
#define TR3_TASKMSGQORDERING_SOMENAME_1 0
    
#define TR3TI_NUM_OF_TASKS_POSSIBLE 3U
#define TR3TI_CONFIGD_NUM_OF_TASKS 2U


/* ========================================================== */


/* Bounding constants. */


const uint8_t Tr3Ti_num_Of_Tasks_Possible = TR3TI_NUM_OF_TASKS_POSSIBLE;
const uint8_t Tr3Ti_configd_Num_Of_Tasks = TR3TI_CONFIGD_NUM_OF_TASKS;


/* ========================================================== */ 


/* Constructed blocks. */


void func_4_SOMENAME_0(void *the_task_data_p);
extern const void *const init_data_4_SOMENAME_0;
const struct Tr3Ti_TaskInfoBlk_s task_Info_Blk_4_SOMENAME_0 = {
    TR3_TASKID_SOMENAME_0,
    TR3_TASKPRIORITY_SOMENAME_0,
    TR3_TASKSTACK_SOMENAME_0,
    TR3_TASKMSGQLEN_SOMENAME_0,
    TR3_TASKMSGQITEMS_SOMENAME_0,
    TR3_TASKMSGQORDERING_SOMENAME_0,
    func_4_SOMENAME_0,
    &init_data_4_SOMENAME_0
};

__attribute__((/* ignored: packed, */ aligned(8))) uint8_t task_Stk_Blk_4_SOMENAME_0[TR3_TASKSTACK_SOMENAME_0];
uint64_t task_Msg_Q_Entries_Used_bits_4_SOMENAME_0;
struct Tr3PL_RootEle_s task_RE_4_SOMENAME_0;
struct Tr3PL_Lst_s task_PL_4_SOMENAME_0[TR3_TASKMSGQLEN_SOMENAME_0];
const struct Tr3Ti_TaskDataBlk_s task_Data_Blk_4_SOMEONE_0 = { 
    &task_Stk_Blk_4_SOMENAME_0[0],
    &task_Msg_Q_Entries_Used_bits_4_SOMENAME_0, 
    &task_RE_4_SOMENAME_0, 
    &task_PL_4_SOMENAME_0[0] 
};

struct Tr3Ti_TaskCtrlBlk_s task_Ctrl_Blk_4_SOMENAME_0;

struct Tr3Ti_TaskCntxtBlk_s task_Cntxt_Blk_4_SOMENAME_0;


void func_4_SOMENAME_1(void *the_task_data_p);
/* NULL external data */
const struct Tr3Ti_TaskInfoBlk_s task_Info_Blk_4_SOMENAME_1 = {
    TR3_TASKID_SOMENAME_1,
    TR3_TASKPRIORITY_SOMENAME_1,
    TR3_TASKSTACK_SOMENAME_1,
    TR3_TASKMSGQLEN_SOMENAME_1,
    TR3_TASKMSGQITEMS_SOMENAME_1,
    TR3_TASKMSGQORDERING_SOMENAME_1,
    func_4_SOMENAME_1,
    NULL
};

__attribute__((/* ignored: packed, */ aligned(8))) uint8_t task_Stk_Blk_4_SOMENAME_1[TR3_TASKSTACK_SOMENAME_1];
uint64_t task_Msg_Q_Entries_Used_bits_4_SOMENAME_1;
struct Tr3PL_RootEle_s task_RE_4_SOMENAME_1;
struct Tr3PL_Lst_s task_PL_4_SOMENAME_1[TR3_TASKMSGQLEN_SOMENAME_1];
const struct Tr3Ti_TaskDataBlk_s task_Data_Blk_4_SOMEONE_1 = { 
    &task_Stk_Blk_4_SOMENAME_1[0],
    &task_Msg_Q_Entries_Used_bits_4_SOMENAME_1, 
    &task_RE_4_SOMENAME_1, 
    &task_PL_4_SOMENAME_1[0] 
};

struct Tr3Ti_TaskCtrlBlk_s task_Ctrl_Blk_4_SOMENAME_1;

struct Tr3Ti_TaskCntxtBlk_s task_Cntxt_Blk_4_SOMENAME_1;


/* ========================================================== */


/* Entries from blocks. */


const struct Tr3Ti_TaskTblEntry_s task_Entry_4_SOMENAME_0 = { 
        &task_Info_Blk_4_SOMENAME_0,
        &task_Data_Blk_4_SOMEONE_0, 
        &task_Ctrl_Blk_4_SOMENAME_0, 
        &task_Cntxt_Blk_4_SOMENAME_0 
};


const struct Tr3Ti_TaskTblEntry_s task_Entry_4_SOMENAME_1 = { 
        &task_Info_Blk_4_SOMENAME_1,
        &task_Data_Blk_4_SOMEONE_1, 
        &task_Ctrl_Blk_4_SOMENAME_1, 
        &task_Cntxt_Blk_4_SOMENAME_1 
};


/* ========================================================== */ 


/* Task table. */


const struct Tr3Ti_TaskTblEntry_s (*const (task_Tbl[TR3TI_CONFIGD_NUM_OF_TASKS])) = {
    &task_Entry_4_SOMENAME_0,
    &task_Entry_4_SOMENAME_1
};


/* ========================================================== */


/* Helpful macros. */


/* No additional ones. */


/* ========================================================== */ 


/* Task management lists. */

 
struct Tr3PL_RootEle_s Tr3Ti_task_Ready_RE;
struct Tr3PL_Lst_s Tr3Ti_task_Ready_Lst[TR3TI_CONFIGD_NUM_OF_TASKS];
 
struct Tr3PL_RootEle_s Tr3Ti_task_Waiting_RE;
struct Tr3PL_Lst_s Tr3Ti_task_Waiting_Lst[TR3TI_CONFIGD_NUM_OF_TASKS];


/* ========================================================== */


/* Tr usual tasks. */


const uint8_t Tr3Ti_task_ID_PrivSec = TR3_TASKID_TR3PRIVSEC_PHONEY;
const uint8_t Tr3Ti_task_ID_ExpInt = TR3_TASKID_TR3EXPINTTASK_PHONEY;
const uint8_t Tr3Ti_task_ID_Kernel = TR3_TASKID_TR3KERNTASK_ITSELF;
const uint8_t Tr3Ti_task_ID_SysClk = TR3_TASKID_TR3SYSCLKTASK_ITSELF;
const uint8_t Tr3Ti_task_ID_MemMan = TR3_TASKID_TR3MEMMANTASK_ITSELF;


/* ========================================================== */


/* Memory Management */


/* ========================================================== */ 


/* Defines generated here. */

#define TR3_MMBLK_16 16
#define TR3_MMBLK_64 32
#define TR3_MMBLK_256 64
    
#define TR3TI_CONFIGD_NUM_OF_MM_AREAS 3U


/* ========================================================== */


/* Bounding constants. */


const uint8_t Tr3Ti_configd_Num_Of_MM_Areas = TR3TI_CONFIGD_NUM_OF_MM_AREAS;


/* ========================================================== */ 


/* Constructed blocks. */


struct Tr3Ti_MMInfoBlk_s mm_Info_Blk_4_16 = {
    16U,
    TR3_MMBLK_16,
    0xFFFFFFFFFFFF0000ULL
};
 
__attribute__((/* ignored: packed, */ aligned(8))) uint8_t mm_Loc_4_16[(16U * TR3_MMBLK_16)];

struct Tr3Ti_MMDataBlk_s mm_Data_Blk_4_16 = {
    &mm_Loc_4_16[0],
    &mm_Loc_4_16[(16U * TR3_MMBLK_16) - 1U]
};
struct Tr3Ti_MMCtrlBlk_s mm_Ctrl_Blk_4_16;

 
struct Tr3Ti_MMInfoBlk_s mm_Info_Blk_4_64 = {
    64U,
    TR3_MMBLK_64,
    0xFFFFFFFF00000000ULL
};
 
__attribute__((/* ignored: packed, */ aligned(8))) uint8_t mm_Loc_4_64[(64U * TR3_MMBLK_64)];

struct Tr3Ti_MMDataBlk_s mm_Data_Blk_4_64 = {
    &mm_Loc_4_64[0],
    &mm_Loc_4_64[(64U * TR3_MMBLK_64) - 1U]
};
struct Tr3Ti_MMCtrlBlk_s mm_Ctrl_Blk_4_64;

 
struct Tr3Ti_MMInfoBlk_s mm_Info_Blk_4_256 = {
    256U,
    TR3_MMBLK_256,
    0x0000000000000000ULL
};
 
__attribute__((/* ignored: packed, */ aligned(8))) uint8_t mm_Loc_4_256[(256U * TR3_MMBLK_256)];

struct Tr3Ti_MMDataBlk_s mm_Data_Blk_4_256 = {
    &mm_Loc_4_256[0],
    &mm_Loc_4_256[(256U * TR3_MMBLK_256) - 1U]
};
struct Tr3Ti_MMCtrlBlk_s mm_Ctrl_Blk_4_256;

 
 /* ========================================================== */


/* Entries from blocks. */


struct Tr3Ti_MMTblEntry_s mm_Entry_4_16 = {
    &mm_Info_Blk_4_16,
    &mm_Data_Blk_4_16,
    &mm_Ctrl_Blk_4_16
};

struct Tr3Ti_MMTblEntry_s mm_Entry_4_64 = {
    &mm_Info_Blk_4_64,
    &mm_Data_Blk_4_64,
    &mm_Ctrl_Blk_4_64
};

struct Tr3Ti_MMTblEntry_s mm_Entry_4_256 = {
    &mm_Info_Blk_4_256,
    &mm_Data_Blk_4_256,
    &mm_Ctrl_Blk_4_256
};


/* ========================================================== */


/* Memory Management table. */


const struct Tr3Ti_MMTblEntry_s (*const (mm_Tbl[TR3TI_CONFIGD_NUM_OF_MM_AREAS])) = {
    &mm_Entry_4_16,
    &mm_Entry_4_64,
    &mm_Entry_4_256,
};


/* ========================================================== */


/* Helpful macros. */


/* No additional ones. */


/* ========================================================== */

