/** \file
*   \brief ThingRendevous's Task Info interface.
*
* Defines task info data expected.
* .c file is gen'd by tool Tr3Gen.
*
* Detailed in unDN02_TaskERD.md and unDN03_MemManERD.md.
*
* \note WHY DOES indent HATE THIS FILE SO GODDAMN MUCH?
*
* \author Alfred O Fingulin FinguPublic@gmail.com
*/  
/* 
 * MIT License
 *
 * Copyright (c) 2023, 2021, 2018, 2017 Alfred O Fingulin  FinguPublic@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TR3TI_H_INCLUDED
#define TR3TI_H_INCLUDED
    
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "Tr3PL.h"


/* ========================================================== */ 


/* Task Management */


/* ========================================================== */ 


/* Defines generated here. */


/* ========================================================== */


/* Bounding constants. */


extern const uint8_t Tr3Ti_num_Of_Tasks_Possible;
extern const uint8_t Tr3Ti_configd_Num_Of_Tasks;


/* ========================================================== */


/* Constructed blocks. */


struct Tr3Ti_TaskInfoBlk_s {
    const uint8_t the_ID; 
    const uint8_t the_Pri;
    const uint16_t the_Stk_Size;
    const uint8_t the_Msg_Q_Len;
    const uint64_t the_Msg_Q_Entries_Avail_bits;
    const uint8_t the_More_Details;
    const void (*const the_Task_Func_p)(void *the_task_data_p);
    const void *const the_Task_Data_p;
};

struct Tr3Ti_TaskDataBlk_s {
    uint8_t *const the_Stk_Blk_p;
    uint64_t *const the_Msg_Q_Entries_Used_bits_p;
    struct Tr3PL_RootEle_s *const the_RE_p;
    struct Tr3PL_Lst_s *const the_PL_p;
};

struct Tr3Ti_TaskCtrlBlk_s {
    uint8_t state_Is;  /* \todo will change when state object defined */
    uint16_t delay_Setting;
    uint16_t delay_Remaining_Is;
    int8_t priority_Offset_Is;
};


/** All registers not saved during an interrupt or exception.
*/
__attribute__((packed, aligned(8))) struct Tr3Ti_UnSaved_s {
    uint32_t r4;      /**< aka v1 */
    uint32_t r5;      /**< aka v2 */
    uint32_t r6;      /**< aka v3 */
    uint32_t r7;      /**< aka v4 */
    uint32_t r8;      /**< aka v5 */
    uint32_t r9;      /**< aka v6/rfp */
    uint32_t r10;      /**< aka sl */
    uint32_t r11;      /**< aka fp */
};

/** Here's what's stacked during a interrupt or exception.
*/
__attribute__((packed, aligned(8))) struct Tr3Ti_ExcepStkFrm_s {
    uint32_t r0;      /**< aka a1 scratch */
    uint32_t r1;      /**< aka a2 scratch */
    uint32_t r2;      /**< aka a3 scratch */
    uint32_t r3;      /**< aka a4 scratch */
    uint32_t r12;      /**< aka ip temporary */
    uint32_t r14_lr;      /**< r14 link register */
    uint32_t r15_pc;      /**< program counter */
    uint32_t xPSR;      /**< program status register */
};

__attribute__((packed, aligned(8))) struct Tr3Ti_TaskCntxtBlk_s {
    struct Tr3Ti_UnSaved_s the_Un_Saved;
    struct Tr3Ti_ExcepStkFrm_s the_Excep_Stk_Frm;
};


/* ========================================================== */


/* Entries from blocks. */


struct Tr3Ti_TaskTblEntry_s {
    const struct Tr3Ti_TaskInfoBlk_s *const the_Info_Blk_p;
    const struct Tr3Ti_TaskDataBlk_s *const the_Data_Blk_p;
    struct Tr3Ti_TaskCtrlBlk_s *const the_Ctrl_Blk_p;
    struct Tr3Ti_TaskCntxtBlk_s *const the_Cntxt_Blk_p;
};


/* ========================================================== */


/* Task table. */


extern const struct Tr3Ti_TaskTblEntry_s (*const (task_Tbl[]));


/* ========================================================== */


/* Helpful macros. */


#define TR3TI_TASK_GET_INFO_BLK_P(TASK_ID) ((task_Tbl[TASK_ID])->the_Info_Blk_p)

#define TR3TI_TASK_GET_DATA_BLK_P(TASK_ID) ((task_Tbl[TASK_ID])->the_Data_Blk_p)

#define TR3TI_TASK_GET_CTRL_BLK_P(TASK_ID) ((task_Tbl[TASK_ID])->the_Ctrl_Blk_p)

#define TR3TI_TASK_GET_CNTXT_BLK_P(TASK_ID) ((task_Tbl[TASK_ID])->the_Cntxt_Blk_p)
#define TR3TI_TASK_GET_UN_SAVED_P(TASK_ID) (&((((task_Tbl[TASK_ID])->the_Cntxt_Blk_p)->the_Un_Saved).r0))
#define TR3TI_TASK_GET_EXCEP_STK_FRM_P(TASK_ID) (&((((task_Tbl[TASK_ID])->the_Cntxt_Blk_p)->the_Excep_Stk_Frm).r4))


/* ========================================================== */


/* Task management lists. */


extern struct Tr3PL_RootEle_s Tr3Ti_task_Ready_RE;
extern struct Tr3PL_Lst_s Tr3Ti_task_Ready_Lst[];

extern struct Tr3PL_RootEle_s Tr3Ti_task_Waiting_RE;
extern struct Tr3PL_Lst_s Tr3Ti_task_Waiting_Lst[];


/* ========================================================== */


/* Tr usual tasks. */


extern const uint8_t Tr3Ti_task_ID_PrivSec;
extern const uint8_t Tr3Ti_task_ID_ExpInt;
extern const uint8_t Tr3Ti_task_ID_Kernel;
extern const uint8_t Tr3Ti_task_ID_SysClk;
extern const uint8_t Tr3Ti_task_ID_MemMan;


/* ========================================================== */


/* Memory Management */


/* ========================================================== */ 


/* Defines generated here. */


/* ========================================================== */


/* Bounding constants. */


extern const uint8_t configd_Num_Of_MM_Areas;


/* ========================================================== */


/* Constructed blocks. */


struct Tr3Ti_MMInfoBlk_s {
    const uint32_t the_Blk_Size;
    const uint32_t the_Num_of_Blks;
    const uint64_t the_Blks_Avail_bits;
};

struct Tr3Ti_MMDataBlk_s {
    const uint8_t *starting_Loc_p;
    const uint8_t *ending_Loc_p;
};

struct Tr3Ti_MMCtrlBlk_s {
    uint64_t the_Blks_Used_bits;
};


/* ========================================================== */


/* Entries from blocks. */


struct Tr3Ti_MMTblEntry_s {
    const struct Tr3Ti_MMInfoBlk_s *const the_Info_Blk_p;
    const struct Tr3Ti_MMDataBlk_s *const the_Data_Blk_p;
    struct Tr3Ti_MMCtrlBlk_s *const the_Ctrl_Blk_p;
};


/* ========================================================== */


/* Memory Management table. */


extern const struct Tr3Ti_MMTblEntry_s (*const (mm_Tbl[]));


/* ========================================================== */


/* Helpful macros. */


#define TR3TI_MM_GET_INFO_BLK_P(IDX) ((mm_Tbl[IDX])->the_Info_Blk_p)

#define TR3TI_MM_GET_DATA_BLK_P(IDX) ((mm_Tbl[IDX])->the_Data_Blk_p)

#define TR3TI_MM_GET_CTRL_BLK_P(IDX) ((mm_Tbl[IDX])->the_Ctrl_Blk_p)


/* ========================================================== */


#endif
