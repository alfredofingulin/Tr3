/** \file
*   \brief ThingRendevous's Application Program Interface Return data values.
*
* Defines data and return values.
* Done in a seperate header 'cause some Tr3 internals just need to know the return
* value and not the whole API.
*
* This is an interface only; there is no implementation.
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

#ifndef TR3APIRET_H_INCLUDED
#define TR3APIRET_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

enum Tr3APIRet_Val_e
{
    Tr3APIRet_OK = 0,

    Tr3APIRet_ShakeLoose = 0xFAU,
    Tr3APIRet_WTF = 0xFBU,
    Tr3APIRet_TODO = 0xFCU,

    Tr3APIRet_NoReturnExpected = 0xFDU,
    Tr3APIRet_InProcess = 0xFEU,
    Tr3APIRet_Undefined = 0xFFU
};

/** Helpful logical checker.
*/
#define TR3APIRET_ISOK(a_ret_val) (((uint8_t) a_ret_val) == 0)

/** Helpful logical checker.
*/
#define TR3APIRET_NOTOK(a_ret_val) (((uint8_t) a_ret_val) > 0 )

/** The data returned by a message status call.
*/
struct Tr3APIRet_MsgStatus_s
{
    uint8_t rms_Task_ID;      /**< The message queue's unique task ID number. */
    uint8_t rms_Max_Len;      /**< Max message queue length in messages. */
    uint8_t rms_Len_Used;      /**< Messages in the queue at this moment. */
};

/** The data returned by a task status call.
*/
struct Tr3APIRet_TaskStatus_s
{
    uint8_t rts_Task_ID;      /**< The task's unique ID number. */
    uint8_t rts_Nominal_Priority;      /**< The nominal priority at which the task runs.  Remember: Low values indicate high priority and high values indicate low priority.  That is: priority 17 runs before priority 177. */
    int8_t rts_Priority_Offset;      /**< Any offset to the nominal priority.  0 means none; task is at nominal priority.  Negative values indicate the task's priority has been raised by this amount (remember: lower number means higher priority).  Positive values should never occur. */
    uint16_t rts_Task_Delay_Remaining;      /**< If the task is blocked by another task and a timeout is pending, how long remains.  Always in units of system clock ticks.  In any other case, the value is stale and has no meaning. */
};

#endif
