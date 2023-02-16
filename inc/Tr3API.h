/** \file
*   \brief ThingRendevous's Application Program Interface.
*
* Just what it says it is.
*
* Returns types and values delegated to Tr3APIRet.h.
*
* Note explicit interrupt enter/leave are not defined here;
* use Tr3APIEI.h.
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

#ifndef TR3API_H_INCLUDED
#define TR3API_H_INCLUDED

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "Tr3APIRet.h"

void Tr3API_start(void);

enum Tr3APIRet_Val_e Tr3API_sysClkTickHappened(void);
enum Tr3APIRet_Val_e Tr3API_getSysClkTick(uint32_t * tick_p);

#define TR3API_TASKID_SELF 0U
#define TR3API_TASKID_NONE 0xFFU

enum Tr3APIRet_Val_e Tr3API_taskStatus(uint8_t target,
                                       struct Tr3APIRet_TaskStatus_s *stat_p);

enum Tr3APIRet_Val_e Tr3API_msgStatus(uint8_t target,
                                      struct Tr3APIRet_MsgStatus_s *stat_p);

#define TR3API_PREEMPT_BITFLAG 0x01U

#define TR3API_CANPREEMPT 0U
#define TR3API_DONOTPREEMPT 0x01U

#define TR3API_PLSPREEMPT(some_flags) ((some_flags & TR3API_PREEMPT_BITFLAG) == TR3API_CANPREEMPT)
#define TR3API_NOPREEMPT(some_flags) ((some_flags & TR3API_PREEMPT_BITFLAG) == TR3API_DONOTPREEMPT)

enum Tr3APIRet_Val_e Tr3API_sndMsg(uint8_t flags, uint8_t target,
                                   void *msg_2_snd_p);

enum Tr3APIRet_Val_e Tr3API_rcvMsg(uint8_t flags, void **rcv_msg_here_pp);

#define TR3API_DELAY4EVER 0xFFFFU
#define TR3API_SHAKELOOSE 0xFFFEU

enum Tr3APIRet_Val_e Tr3API_delay(uint8_t flags, uint8_t target,
                                  uint16_t how_long);

enum Tr3APIRet_Val_e Tr3API_alloc(uint8_t flags, size_t mem_sz,
                                  void **mem_here_pp);

enum Tr3APIRet_Val_e Tr3API_free(uint8_t flags, void *mem_blk_p);

#endif
