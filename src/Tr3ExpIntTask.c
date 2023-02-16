/** \file
*   \brief ThingRendevous's Explicit Interrupt Task.
*
* Home to the explicit interrupt "phoney" task and entry methods.
*
* The primary job is being a placeholder.
* This task is really any interrupt
* that runs on the main stack;
* it invokes kernal task services directly.
* It acts like a copy of the kernel task.
*
* Tr3ICfg.h exposes the task and it's configuration.
* Tr3ExpIntTask.h exposes the entry methods.
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

#include <stdint.h>
#include <stdbool.h>
#include "Tr3ICfg.h"
#include "Tr3ExpIntTask.h"


/** Just what it says.
* \todo implement
*/
void Tr3ExpIntTask_phoney(void *the_task_data_p)
{
    while (1)
    {
        ;
    }
}


/** "Constructor"
* \todo implement
*/
void Tr3ExpIntTask_init(void)
{
    ;
}
