/** \file
*   \brief ThingRendevous's System Clock Task.
*
* Home to the system clock task and entry methods.
*
* The primary job is using knowledge of internal data structures
* to manage ready task lists
* with every clock tick.
*
* Tr3ICfg.h exposes the task and it's configuration.
* Tr3SysClkTask.h exposes the entry methods.
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
#include "Tr3SysClkTask.h"


/** Just what it says.
* \todo implement
*/
void Tr3SysClkTask_itself(void *the_task_data_p)
{
    while (1)
    {
        ;
    }
}


/** "Constructor"
* \todo implement
*/
void Tr3SysClkTask_init(void)
{
    ;
}
