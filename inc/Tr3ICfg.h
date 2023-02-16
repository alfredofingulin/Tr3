/** \file
*   \brief ThingRendevous's Internals Config.
*
* This details internal task configuration.
* You may want to change the stack or input queue sizes,
* but you shouldn't change anything else.
* 
* Reference Spec08_IDPriorities.md
* An example for TN02_TaskSteps.md
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

#ifndef TR3ICFG_H_INCLUDED
#define TR3ICFG_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

void Tr3PrivSec_phoney(void *the_task_data_p);
#define TR3_TASKNAME_TR3PRIVSEC_PHONEY #Tr3PrivSec_phoney
#define TR3_TASKID_TR3PRIVSEC_PHONEY 1U
#define TR3_TASKSTACK_TR3PRIVSEC_PHONEY 8U   /* Uses MSP, and is highest priority exception.  Config'd with linker directives. */
/* Will be forced by config gen.  #define TR3_TASKPRIORITY_TR3PRIVSEC_PHONEY 1U */
#define TR3_TASKMSGQLEN_TR3PRIVSEC_PHONEY 0U /* Does not queue messages, but executes atomically. */
/* Not used; config gen will default to FIFO.  #define TR3_TASKMSGQORDERING_TR3PRIVSEC_PHONEY 0 */
/* No init data; config gen default to null.  #define TR3_TASKINITDATA_TR3PRIVSEC_PHONEY NULL */

void Tr3ExpIntTask_phoney(void *the_task_data_p);
#define TR3_TASKNAME_TR3EXPINTTASK_PHONEY #Tr3ExpIntTask_phoney
#define TR3_TASKID_TR3EXPINTTASK_PHONEY 5U
#define TR3_TASKSTACK_TR3EXPINTTASK_PHONEY 8U    /* Uses MSP.  Config'd with linker directives. */
/* Will be forced by config gen.  #define TR3_TASKPRIORITY_TR3EXPINTTASK_PHONEY 5U */
#define TR3_TASKMSGQLEN_TR3EXPINTTASK_PHONEY 0  /* Really re-enterant kernel running on MSP */
/* Not used; config gen will default to FIFO.  #define TR3_TASKMSGQORDERING_TR3EXPINTTASK_PHONEY 0 */
/* No init data; config gen default to null.  #define TR3_TASKINITDATA_TR3EXPINTTASK_PHONEY NULL */

void Tr3KernTask_itself(void *the_task_data_p);
#define TR3_TASKNAME_TR3KERNTASK_ITSELF #Tr3KernTask_itself
#define TR3_TASKID_TR3KERNTASK_ITSELF 9U
#define TR3_TASKSTACK_TR3KERNTASK_ITSELF 2048U   /* Has it's own thread.  May grow/shrink due to changing capabilities. */
/* Will be forced by config gen.  #define TR3_TASKPRIORITY_TR3KERNTASK_ITSELF 9U */
#define TR3_TASKMSGQLEN_TR3KERNTASK_ITSELF 16U   /* How many kernel requests to queue up. */
/* May want to change this in the future; config gen will default to FIFO.  #define TR3_TASKMSGQORDERING_TR3KERNTASK_ITSELF 0 */
/* No init data; config gen default to null.  #define TR3_TASKINITDATA_TR3KERNTASK_ITSELF NULL */

void Tr3SysClkTask_itself(void *the_task_data_p);
#define TR3_TASKNAME_TR3SYSCLKTASK_ITSELF #Tr3SysClkTask_itself
#define TR3_TASKID_TR3SYSCLKTASK_ITSELF 13U
#define TR3_TASKSTACK_TR3SYSCLKTASK_ITSELF 2048U /* Has it's own thread.  May grow/shrink due to changing capabilities. */
/* Will be forced by config gen.  #define TR3_TASKPRIORITY_TR3SYSCLKTASK_ITSELF 13U */
#define TR3_TASKMSGQLEN_TR3SYSCLKTASK_ITSELF 4U  /* Queuing up clock ticks can be a problem, but sometimes necessary. */
/* May want to change this in the future; config gen will default to FIFO.  #define TR3_TASKMSGQORDERING_TR3SYSCLKTASK_ITSELF 0 */
/* No init data; config gen default to null.  #define TR3_TASKINITDATA_TR3SYSCLKTASK_ITSELF NULL */

void Tr3MemManTask_itself(void *the_task_data_p);
#define TR3_TASKNAME_TR3MEMMANTASK_ITSELF #Tr3MemManTask_itself
#define TR3_TASKID_TR3MEMMANTASK_ITSELF 17U
#define TR3_TASKSTACK_TR3MEMMANTASK_ITSELF 2048U /* Has it's own thread.  May grow/shrink due to changing capabilities. */
/* Will be forced by config gen.  #define TR3_TASKPRIORITY_TR3MEMMANTASK_ITSELF 17U */
#define TR3_TASKMSGQLEN_TR3MEMMANTASK_ITSELF 4U  /* Do we even need this task? */
/* May want to change this in the future; config gen will default to FIFO.  #define TR3_TASKMSGQORDERING_TR3MEMMANTASK_ITSELF 0 */
/* No init data; config gen default to null.  #define TR3_TASKINITDATA_TR3MEMMANTASK_ITSELF NULL */

#endif
