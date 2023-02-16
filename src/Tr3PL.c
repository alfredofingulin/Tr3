/** \file
*   \brief ThingRendevous's Priority List implementation
*
* In reality, implements a linked list built by priority
* and ordered numerically from high to low (by priority from low to high).
* The head is the lowest priority item; the tail the highest priority item.
*
* \author Alfred O Fingulin FinguPublic@gmail.com
*/
/* 
 * MIT License
 *
 * Copyright (c) 2023, 2017 Alfred O Fingulin  FinguPublic@gmail.com
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
#include <stddef.h>
#include "Tr3B.h"
#include "Tr3PL.h"

/** Move to the previous element in the list, if possible (a lower priority element).
*
* 
* Does not conduct bounds checking.
*
* \retval true - there is a previous element and the index updated.
* \retval false - we're at the beginning of the list and the index indicates it.
*/
bool Tr3PL_prev(uint8_t * present_idx_p,
                /**< Where we currently are in the list. */
                struct Tr3PL_Lst_s *a_lst_p
                /**< Where the list it. */
    )
{
    bool retval = false;
    if (a_lst_p[*present_idx_p].prev != TR3B_EMPTY)
    {
        *present_idx_p = a_lst_p[*present_idx_p].prev;
        retval = true;
    }
    else
    {
        /* use entry default index unchanged */
    }
    return retval;
}

/** Move to the next element in the list, if possible (a higher priority element).
*
* Does not conduct bounds checking.
*
* \retval true - there is a next element and the index updated.
* \retval false - we're at the end of the list and index so indicates.
*/
bool Tr3PL_next(uint8_t * present_idx_p,
                /**< Where we currently are in the list. */
                struct Tr3PL_Lst_s *a_lst_p
                /**< Where the list it. */
    )
{
    bool retval = false;
    if (a_lst_p[*present_idx_p].next != TR3B_EMPTY)
    {
        *present_idx_p = a_lst_p[*present_idx_p].next;
        retval = true;
    }
    else
    {
        /* use entry default index unchanged */
    }
    return retval;
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_getPri(uint8_t an_idx,
                  /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p,
                  /**< Where the list it. */
                  uint8_t * pri_found_p
                  /**< Where to put the priority found. */
    )
{
    *pri_found_p = a_lst_p[an_idx].pri;
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_setPri(uint8_t an_idx,
                  /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p,
                  /**< Where the list it. */
                  uint8_t to_pri
                  /**< The priority value to fill-in.*/
    )
{
    a_lst_p[an_idx].pri = to_pri;
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_getKey(uint8_t an_idx,
                  /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p,
                  /**< Where the list it. */
                  uint8_t * key_found_p
                  /**< Where to put the key found */
    )
{
    *key_found_p = a_lst_p[an_idx].key;
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_setKey(uint8_t an_idx,
                 /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p,
                 /**< Where the list it. */
                  uint8_t to_key
                 /**< Value for the key */
    )
{
    a_lst_p[an_idx].key = to_key;
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_getAll(uint8_t an_idx,
                  /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p,
                  /**< Where the list it. */
                  uint8_t * pri_found_p,
                  /**< Where to put the priority found. */
                  uint8_t * key_found_p
                  /**< Where to put the key found */
    )
{
    Tr3PL_getPri(an_idx, a_lst_p, pri_found_p);
    Tr3PL_getKey(an_idx, a_lst_p, key_found_p);
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_setAll(uint8_t an_idx,
                  /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p,
                  /**< Where the list it. */
                  uint8_t to_pri,
                  /**< The priority value to fill-in.*/
                  uint8_t to_key
                  /**< Value for the key */
    )
{
    Tr3PL_setPri(an_idx, a_lst_p, to_pri);
    Tr3PL_setKey(an_idx, a_lst_p, to_key);
}

/** Obvious.
*
* Does not conduct bounds checking.
*
*/
void Tr3PL_freeUp(uint8_t i,
                  /**< From this index in the list */
                  struct Tr3PL_Lst_s *a_lst_p
                  /**< Where the list it. */
    )
{
    a_lst_p[i].key = a_lst_p[i].pri = a_lst_p[i].prev = a_lst_p[i].next =
        TR3B_EMPTY;
}

/** Find a free element in a priority list using a brutarian linear search.
*
* Looks for the first item where key is empty.
*
* \retval - The index of the empty spot or empty for no space.
*/
uint8_t Tr3PL_findFree(struct Tr3PL_Lst_s *a_lst_p,
                       /**< Which priority list to use. */
                       struct Tr3PL_RootEle_s *the_root_ele_p
                       /**< Where to find how many elements are in the priority list. */
    )
{
    uint8_t i;
    for (i = 0; (i < the_root_ele_p->leng) && (a_lst_p[i].key != TR3B_EMPTY);
         i++)
    {
        /* Just count. */
    }
    if (i >= the_root_ele_p->leng)
    {
        i = TR3B_EMPTY;
    }
    return i;
}

/** Init a priority list to empty.
*
*/
void Tr3PL_init(struct Tr3PL_Lst_s *a_lst_p,
                /**< Where to find the priority list. */
                uint8_t a_Lst_len,
                /**< How many elements are in the priority list. */
                struct Tr3PL_RootEle_s *a_root_ele_p
                /**< Where the root element resides. */
    )
{
    uint8_t i;
    for (i = 0; i < a_Lst_len; i++)
    {
        Tr3PL_freeUp(i, a_lst_p);
    }
    a_root_ele_p->head = a_root_ele_p->tail = TR3B_EMPTY;
    a_root_ele_p->leng = a_Lst_len;
}

/** Insert a key into the priority list.
*
* Inserts the key
* after all items of higher or equal priority
* and before all items of lesser priority.
*
* Fails silently.
* Does not check to see if key exists.
*/
void Tr3PL_insert(uint8_t a_key,
                  /**< The key value. */
                  uint8_t a_pri,
                  /**< The priority to use. */
                  struct Tr3PL_Lst_s *a_lst_p,
                  /**< Which priority list to use. */
                  struct Tr3PL_RootEle_s *the_root_ele_p
                  /**< The root element (head & tail & esp leng) for this list. */
    )
{
    uint8_t i = the_root_ele_p->head;
    bool more = true;
    uint8_t fe = Tr3PL_findFree(a_lst_p, the_root_ele_p);

    if (fe != TR3B_EMPTY)
    {
        if ((the_root_ele_p->head & the_root_ele_p->tail) == TR3B_EMPTY)
        {
            /* empty list first item */
            Tr3PL_setAll(fe, a_lst_p, a_pri, a_key);
            the_root_ele_p->head = the_root_ele_p->tail = fe;

        }
        else
        {
            /* list is non-empty; will have to iterate * moving from head, biggest number, lowest priority * to tail, smallest number, highest priority */

            do
            {
                if (a_pri >= a_lst_p[i].pri)
                {
                    /* element to insert has lower or equal priority to this one * insert the one presented before the one we're at */
                    Tr3PL_setAll(fe, a_lst_p, a_pri, a_key);

                    a_lst_p[fe].prev = a_lst_p[i].prev;
                    a_lst_p[fe].next = i;
                    if (a_lst_p[i].prev != TR3B_EMPTY)
                    {
                        a_lst_p[a_lst_p[i].prev].next = fe;
                    }
                    a_lst_p[i].prev = fe;
                    if (a_lst_p[fe].prev == TR3B_EMPTY)
                    {
                        the_root_ele_p->head = fe;
                    }

                    more = false;   /* we're done */
                }
                else
                {
                    /* element to insert has higher priority than this one * let's iterate to the next element. * go examine the next element, * or if at the
                       end, * then insert the one presented after that next one. */

                    more = Tr3PL_next(&i, a_lst_p);

                    if (!more)
                    {
                        Tr3PL_setAll(fe, a_lst_p, a_pri, a_key);

                        a_lst_p[fe].prev = i;
                        a_lst_p[fe].next = a_lst_p[i].next;
                        if (a_lst_p[i].next != TR3B_EMPTY)
                        {
                            a_lst_p[a_lst_p[i].next].prev = fe;
                        }
                        a_lst_p[i].next = fe;
                        if (a_lst_p[fe].next == TR3B_EMPTY)
                        {
                            the_root_ele_p->tail = fe;
                        }
                    }
                    else
                    {
                        /* next element is in i */
                    }

                    /* may not be done; next iteration; else done. */
                }

            }
            while (more);

        }
    }
    else
    {
        /* no free elements so do nothing */
    }
}

/** Removes the highest priority item in the list.
*
* The list entry is destroyed.
*/
void Tr3PL_removeHi(struct Tr3PL_Lst_s *a_lst_p,
                    /**< Which priority list to use. */
                    struct Tr3PL_RootEle_s *the_root_ele_p,
                    /**< The root element (head & tail) for this list. */
                    uint8_t * key_found_p,
                    /**< Where to put the key found; could be empty. */
                    uint8_t * pri_found_p
                    /**< Where to put the pri found; could be empty. */
    )
{
    uint8_t i = the_root_ele_p->tail;

    *pri_found_p = *key_found_p = TR3B_EMPTY;

    if (i != TR3B_EMPTY)
    {
        Tr3PL_getAll(i, a_lst_p, pri_found_p, key_found_p);

        if (a_lst_p[i].prev != TR3B_EMPTY)
        {
            a_lst_p[a_lst_p[i].prev].next = TR3B_EMPTY;
            the_root_ele_p->tail = a_lst_p[i].prev;
        }
        else
        {
            the_root_ele_p->tail = the_root_ele_p->head = TR3B_EMPTY;
        }
        Tr3PL_freeUp(i, a_lst_p);
    }
}

/** Removes the lowest priority item in the list.
*
* The list entry is destroyed.
*/
void Tr3PL_removeLo(struct Tr3PL_Lst_s *a_lst_p,
                    /**< Which priority list to use. */
                    struct Tr3PL_RootEle_s *the_root_ele_p,
                    /**< The root element (head & tail) for this list. */
                    uint8_t * key_found_p,
                    /**< Where to put the key found; could be empty. */
                    uint8_t * pri_found_p
                    /**< Where to put the pri found; could be empty. */
    )
{
    uint8_t i = the_root_ele_p->head;

    *pri_found_p = *key_found_p = TR3B_EMPTY;

    if (i != TR3B_EMPTY)
    {
        Tr3PL_getAll(i, a_lst_p, pri_found_p, key_found_p);

        if (a_lst_p[i].next != TR3B_EMPTY)
        {
            a_lst_p[a_lst_p[i].next].prev = TR3B_EMPTY;
            the_root_ele_p->head = a_lst_p[i].next;
        }
        else
        {
            the_root_ele_p->head = the_root_ele_p->tail = TR3B_EMPTY;
        }
        Tr3PL_freeUp(i, a_lst_p);
    }
}

/** Find the index into the list having a_key.
* 
* \retval - 0..(the_root_ele_p->leng - 1), else empty.
*/
uint8_t Tr3PL_find(uint8_t a_key,
                   /**< ...we're trying to find. */
                   struct Tr3PL_Lst_s *a_lst_p,
                   /**< List in memory. */
                   struct Tr3PL_RootEle_s *the_root_ele_p
                   /**< Root ele for this list.*/
    )
{
    uint8_t i = the_root_ele_p->head;   /* may be empty */
    bool key_Fnd = false;
    bool more = true;

    if (i != TR3B_EMPTY)
    {
        while (!key_Fnd && more)
        {
            if (a_lst_p[i].key == a_key)
            {
                key_Fnd = true;
            }
            else
            {
                more = Tr3PL_next(&i, a_lst_p);
            }
        }
        if (!key_Fnd)
        {
            i = TR3B_EMPTY;
        }
        else
        {
            /* i contains index to key element */
        }
    }
    else
    {
        /* list is empty, so is i */
    }

    return i;
}

/** Remove an item at an index.
*
* Tells you what was there, then sets fields to empty.
*
* Presumes the index is part of the priority list.  
* If not, strange things will happen.
*
* If you try to remove a free element, strange things will happen.
* It might empty the list without free-ing anything.
*/
void Tr3PL_removeAt(struct Tr3PL_Lst_s *a_lst_p,
                    /**< List in memory. */
                    struct Tr3PL_RootEle_s *the_root_ele_p,
                    /**< Root ele for this list.*/
                    uint8_t at_idx,
                    /**< Where in the list; you ensure it's a valid index. */
                    uint8_t * key_found_p,
                    /**< Where to put the key found. */
                    uint8_t * pri_found_p
                    /**< Where to put the priority found. */
    )
{
    uint8_t at_Prev = a_lst_p[at_idx].prev;
    uint8_t at_Next = a_lst_p[at_idx].next;
    *pri_found_p = a_lst_p[at_idx].pri;
    *key_found_p = a_lst_p[at_idx].key;

    if ((at_Prev != TR3B_EMPTY) && (at_Next != TR3B_EMPTY))
    {
        /* Middle of the list.  Drop it out. */
        /* previous next is my next */
        /* next previous is my previous */

        a_lst_p[at_Prev].next = a_lst_p[at_idx].next;
        a_lst_p[at_Next].prev = a_lst_p[at_idx].prev;
    }
    else if ((at_Prev == TR3B_EMPTY) && (at_Next != TR3B_EMPTY))
    {
        /* First item in list.  Next replaces. */
        /* no previous next */
        /* next previous is now empty */
        /* next item is head */
        a_lst_p[at_Next].prev = TR3B_EMPTY;
        the_root_ele_p->head = at_Next;
    }
    else if ((at_Prev != TR3B_EMPTY) && (at_Next == TR3B_EMPTY))
    {
        /* Last item in list.  Previous replaces. */
        /* previous next is now empty * previous item is tail */
        /* no next previous */
        a_lst_p[at_Prev].next = TR3B_EMPTY;
        the_root_ele_p->tail = at_Prev;
    }
    else                        /* ((at_Prev == TR3B_EMPTY) && (at_Next == TR3B_EMPTY)) */
    {
        /* Only item in list.  List now empty. */
        /* head and tail both empty */
        the_root_ele_p->head = TR3B_EMPTY;
        the_root_ele_p->tail = TR3B_EMPTY;
    }

    Tr3PL_freeUp(at_idx, a_lst_p);
}
