/** \file
*   \brief ThingRendevous's Private Section.
*
* Entry methods for getting to SVC and other "atomic" action exceptions.
*
* \todo add entry methods
*
* Configurable by Tr3ICfg.h
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

#ifndef TR3PRIVSEC_H_INCLUDED
#define TR3PRIVSEC_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
/* #include "../inc/Tr3ICfg.h" for task and config. */

void Tr3PrivSec_init(void);

#endif
