/** \file
*   \brief ThingRendevous's Application Program Interface Explicit Interrupt for ARM Cortex M4
*
* Doxygen and Indent don't cope too well with this source code.
*
* It implements a macro to:
*
* - define an ARM Cortext M4 exception/interrupt handler with a name from startup.s
* - tie your handler that does the actual work
* - use ARM Cortex M4 equivelents for enter/leave.
*
* \todo lots of items open
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

#ifndef TR3APIEI_H_INCLUDED
#define TR3APIEI_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

/** Identifies your function that handles an exception/interrupt, ties it to a handler entry, binds it with enter/leave.
*
* \param handler_name - from startup.s
* \param actual_handler - a void function without parameters to implement handler_name
*
* Creates a naked handler_name function that calls actual_handler,
* wrapped in enter/leave/assembler majic.
*
* It assumes the stack pointer might be misaligned.
*
* Copypasta-s the explicit interrupt enter/leave macros
* because it makes things obvious
* and we have to clean up r7 anyway.
*/
#define TR3APIEI_FOR_AND_BY(handler_name,actual_handler) \
void actual_handler ( void ); \
void __attribute__((naked)) handler_name ( void ) \
{ \
    __asm__ __volatile__ ( \
        "mov    r0, sp \n\t" \
        "bic    r1, r0, #7 \n\t" \
        "mov    sp, r1 \n\t" \
    "\n\t" \
        "push   {r0, r7, lr} \n\t" \
        "add    r7, sp, #0 \n\t" \
    "\n\t" \
    " ; \todo interrupt enter        movw   r0, #21 \n\t" \
    " ; \todo interrupt enter        svc    $255 \n\t" \
    " ; \todo interrupt enter        cmp    r3, #0 \n\t" \
    " ; \todo interrupt enter        ittt   ne \n\t" \
    " ; \todo interrupt enter        stmne  r3, {r4-r11} \n\t" \
    " ; \todo interrupt enter        ldrne  r1, [sp, #4] \n\t" \
    " ; \todo interrupt enter        strne  r1, [r3, #12] \n\t" \
    "\n\t" \
        : \
        : \
        : \
        ); \
    \
    actual_handler(); \
    \
    __asm__ __volatile__ ( \
    "\n\t" \
    " ; \todo interrupt exit        movw   r0, #22 \n\t" \
    " ; \todo interrupt exit        svc    $255 \n\t" \
    "\n\t" \
        "mov    sp, r7 \n\t" \
        "pop    {r0, r7, lr} \n\t" \
        "mov    sp, r0 \n\t" \
    "\n\t" \
    " ; \todo interrupt exit        cmp    r2, #0 \n\t" \
    " ; \todo interrupt exit        it     ne \n\t" \
    " ; \todo interrupt exit        ldmne  r2, {r4-r11} \n\t" \
    "\n\t" \
        "bx lr \n\t" \
        : \
        : \
        : \
        ); \
}

#endif
