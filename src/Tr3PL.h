/** \file
*   \brief ThingRendevous's Priority List interface
*
* This is a generalized priority list
* as an array of keys, priorities 
* and index links within the list.
*
* The list is doubly linked from head to tail
* by lowest priority (priority value is a big number)
* to highest priority (priority value is a small number).
*
* \author Alfred O Fingulin FinguPublic@gmail.com
*/
/* 
 * MIT License
 *
 * Copyright (c) 2023, 2021, 2017 Alfred O Fingulin  FinguPublic@gmail.com
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

#ifndef TR3PL_H_INCLUDED
#define TR3PL_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "Tr3B.h"

/** Priority list elements can be indexed from 0...to this.
*
*/
#define TR3PL_LST_IDX_LAST 0xFDU

/** Note maximum list length is last + 1 and must be < uint8_t max.
*
* Further, empty is uint8_t max.
*
*/
#define TR3PL_LST_LEN_MAX TR3PL_LST_IDX_LAST+1

/** Tr3PL uses an array of linked-list elements.  Here's each array element..
*
* Indexes 0...(max_num_of_eles - 1) store
*
* * a priority field
* * an eight bit key to whatever you want.
* * link to the previous element
* * link to the next element
*
* The priority field is obvious.  
* It's suggested that priority be empty when an element is free.
*
* The key is obvious.
* The key must be empty when an element is free.
*
* If a previous list element exists, the previous link index field will not be empty.
* If the element is the head of the list, it will be empty.
*
* If a next list element exists, the next link index field will not be empty.
* If the element is the tail of the list, it will be empty.
*
* If both previous and next are empty, it may be the only element in the list.
*/
struct Tr3PL_Lst_s
{
    uint8_t key;      /**< Some key, whatever you want it to represent.  Duplicates should not be used. */
    uint8_t pri;      /**< The priority of the element.  Duplicates are allowed. */
    uint8_t prev;      /**< Index link to the previous element in the list.  Empty if the head. */
    uint8_t next;      /**< Index link to the next element in the list.  Empty if the tail. */
};

/** Tr3PL expects a seperate root element holding the list's head and tail and len.
*
* The head is the lowest priority item in the list (the priority value is a big number).
*
* The tail is the highest priority item in the list (the priority value is a small number).
*/
struct Tr3PL_RootEle_s
{
    uint8_t head;      /**< Index to the head of the list. */
    uint8_t tail;      /**< Index to the tail of the list. */
    uint8_t leng;      /**< The length of the Lst. */
};

void Tr3PL_init(struct Tr3PL_Lst_s *a_lst_p, uint8_t a_lst_len,
                struct Tr3PL_RootEle_s *a_root_ele_p);

void Tr3PL_insert(uint8_t a_key, uint8_t a_pri, struct Tr3PL_Lst_s *a_lst_p,
                  struct Tr3PL_RootEle_s *the_root_ele_p);

void Tr3PL_removeHi(struct Tr3PL_Lst_s *a_lst_p,
                    struct Tr3PL_RootEle_s *the_root_ele_p,
                    uint8_t * key_found_p, uint8_t * pri_found_p);
void Tr3PL_removeLo(struct Tr3PL_Lst_s *a_lst_p,
                    struct Tr3PL_RootEle_s *the_root_ele_p,
                    uint8_t * key_found_p, uint8_t * pri_found_p);

uint8_t Tr3PL_find(uint8_t a_key, struct Tr3PL_Lst_s *a_lst_p,
                   struct Tr3PL_RootEle_s *the_root_ele_p);
void Tr3PL_removeAt(struct Tr3PL_Lst_s *a_lst_p,
                    struct Tr3PL_RootEle_s *the_root_ele_p,
                    uint8_t at_idx,
                    uint8_t * key_found_p, uint8_t * pri_found_p);

bool Tr3PL_prev(uint8_t * present_idx_p, struct Tr3PL_Lst_s *a_lst_p);
bool Tr3PL_next(uint8_t * present_idx_p, struct Tr3PL_Lst_s *a_lst_p);

#endif
