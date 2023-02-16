/** \file
*   \brief ThingRendevous's Application Program Interface.
*
* Connects the the API to the internal private sections and tasks.
* Those do the real work.
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


#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "Tr3APIRet.h"

#include "Tr3API.h"

/** Start Tr.
* 
* No return is expected.
* Last thing to call after all inits are complete.
*
* \todo implement
*/
void Tr3API_start(void)
{
    ;
}

/** Notify Tr that a system clock tick has occured.
* 
* Callable from an interrupt or a task.
* It does cause rescheduling to occur.
* It does not preempt the current interrupt or task.
*
* If an interrupt, returns directly to the calling interrupt.
* Rescheduling and preemption will occur
* on interrupt conclusion, as usual.
*
* If a task, returns directly to the calling task,
* Rescheduling and preemption will occur
* on the task's next snd/rcv message or delay,
* and only if requested.
*
* You need to know how often a tick occurs.
* You are responsible for handling hardware and such.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_sysClkTickHappened(void)
{
    return Tr3APIRet_TODO;
}

/** Report the number of system clock ticks.
* 
* Always returns to the calling interrupt or task.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_getSysClkTick(uint32_t * tick_p
                                          /**< Where to put the number of system clock ticks since start was invoked. */
    )
{
    return Tr3APIRet_TODO;
}

/** Report status of the target task.
* 
* It can cause rescheduling
* but it does not preempt the calling interrupt or task.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_taskStatus(uint8_t target,
                                       /**< Task we're inquiring about. */
                                       struct Tr3APIRet_TaskStatus_s *stat_p
                                       /**< Pointer where task status will be filled in. */
    )
{
    return Tr3APIRet_TODO;
}

/** Report message queue status of the target task.
* 
* It can cause rescheduling
* but it does not preempt the calling interrupt or task.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_msgStatus(uint8_t target,
                                      /**< Task we're inquiring about. */
                                      struct Tr3APIRet_MsgStatus_s *stat_p
                                      /**< Pointer where task's message queue status will be filled in. */
    )
{
    return Tr3APIRet_TODO;
}

/** Send a pointer to a message block in memory.
* 
* If flags CANPREEMPT, then 
* the pointer to the message block will be queued
* to the target task, success/fail noted,
* and then rescheduling will be conducted.
* The caller may be preempted.
* The caller will not get control again
* until the caller is the highest priority task in the system.
*
* Otherwise,
* the pointer to the message block will be queued
* to the target task, success/fail noted,
* and then rescheduling will be conducted.
* The caller will not be preempted
* and will retain control.
*
* The pointer is queued, not the message block.
*
* It is an error to use CANPREEMPT within an interrupt.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_sndMsg(uint8_t flags,
                                   /**< Where or not to preempt after sending a message. */
                                   uint8_t target,
                                   /**< Task ID.  Self is valid. */
                                   void *msg_2_snd_p
                                   /**< Pointer to the message block.  Only the pointer is passed; the block must remain unaltered. */
    )
{
    return Tr3APIRet_TODO;
}

/** Receive a pointer to a message block in memory.
* 
* If flags CANPREEMPT, then
* rescheduling will be conducted.
* The caller may be preempted.
* The caller will (may) not get control again
* until a message is present
* and the caller is the highest priority task in the system.
* When the caller gets control,
* the pointer to the message block will be dequeued
* and presented.
*
* Otherwise,
* rescheduling will be conducted.
* The caller will not be preempted.
* The call will get control again,
* whether or not a message is present.
* When the caller gets control,
* the pointer to the message block will be dequeued,
* if one is present,
* and presented.
*
* The pointer is dequeued, not the message block.
*
* Recall that TR3_TASKMSGQORDERING_SOMENAME determines
* how the message pointer is dequeued:
*
* * 0: the oldest message will be dequeued.
* * 1:  the highest priority sending task, regardless of age.
*
* It is an error to use CANPREEMPT within an interrupt.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_rcvMsg(uint8_t flags,
                                   /**< Where or not to preempt and wait, and whether to get oldest msg or msg from highest priority sending task. */
                                   void **rcv_msg_here_pp
                                   /**< Points to where to put the pointer to the received msg. */
    )
{
    return Tr3APIRet_TODO;
}

/** Task control, or cause self or another task to delay the specified ticks.
* 
* Operation depends on target.
*
* target is self:
* * flags is irrelevant; rescheduling and preemption will occur 
* * how_long 0 says "I relinquish control for now" 
*   and you may get it right back 
* * how_long SHAKELOOSE is \todo hell I dunno
* * how_long WAIT4EVER sleeps yourself
*   until someone else delays otherwise
* * other how_long-s sleep yourself for at least that duration.
*
* target is some other task, then flags is used:
* * flags CANPREEMPT will determine whether or not to give up control
* * how_long 0 will make the target ready to run, 
*   but last on the list of ready to run tasks in it's priority group
* * how_long SHAKELOOSE will 0 the delay
*   if not delayed, and the task is waiting, 
*   the task is moved to the ready list
*   and will get return code ShakeLoose.
*   (you're shaking loose the task).
* * how_long WAIT4EVER puts the target asleep 
*   until somebody delays with a non-WAIT4EVER value
* * other how_long-s reset the target's delay
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_delay(uint8_t flags,
                                  /**< Control preempt, but see details. */
                                  uint8_t target,
                                  /**< Task to effect.  Self is valid. */
                                  uint16_t how_long
                                  /**< In system clock ticks.  Some values are special. */
    )
{
    return Tr3APIRet_TODO;
}

/** Allocate a block of memory.
* 
* If flags CANPREEMPT, then
* rescheduling will be conducted.
* The caller may be preempted.
* The caller will (may) not get control again.
* Prior to getting control, 
* an attempt to allocate the requested memory will be made.
*
* Otherwise,
* rescheduling will be conducted.
* The caller will not be preempted.
* An attempt to allocate the requested memory will be made,
* and the caller will get control again.
*
* It is an error to use CANPREEMPT within an interrupt.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_alloc(uint8_t flags,
                                  /**< Allow preemption or not. */
                                  size_t mem_sz,
                                  /**< As specified using sizeof() operator. */
                                  void **mem_here_pp
                                  /**< Pointer to where to put the pointer to memory allocated. */
    )
{
    return Tr3APIRet_TODO;
}

/** Free a block of memory.
* 
* Always frees the block presented.
*
* If flags CANPREEMPT, then
* rescheduling will be conducted.
* The caller may be preempted.
*
* Otherwise,
* rescheduling will be conducted.
* The caller will not be preempted
* and will get control again.
*
* It is an error to use CANPREEMPT within an interrupt.
*
* \todo implement
* 
* \retval - Success/fail as described by Tr3APIRet_Val_e.
*/
enum Tr3APIRet_Val_e Tr3API_free(uint8_t flags,
                                  /**< Allow preemption or not. */
                                 void *mem_blk_p
                                 /**< The previously allocated memory to be returned. */
    )
{
    return Tr3APIRet_TODO;
}
