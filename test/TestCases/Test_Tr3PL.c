/** \file
*   \brief ThingRendevous's Test Tr3PL file.
*
* Priority List tester.
* Create a 6 element list.
* Verify empty inits by direct observation.
* Insert 2,2; 8,8; 5,5
* Verify by direct observation.
* Remove hi.
* Verify by direct obersation, both result and list.
* Remove lo.
* Verify by direct obersation, both result and list.
* Remaining is 5,5.
* Insert 3,3; 7,8 (note pri); 2,2; 8,8; 5,5 is in there too.
* Verify by direct observation (7, then 8!)
* Find 3.
* Remove 3.
* Verify by direct observation.
* Find 8.
* Remove 8.
* Verify by direct observation.
* Remaining is 5, 7, 2.
* Remove lo.
* Verify by direct observation that 7 is gone.
* Remove hi.
* Verify by direct observation that 2 is gone.
* Verify only 5 by direct observation.
*
* \author Alfred O Fingulin FinguPublic@gmail.com
*/
/* 
 * MIT License
 *
 * Copyright (c) 2023, 2021 Alfred O Fingulin  FinguPublic@gmail.com
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

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/* 
 * ===============================================================
 */

/** Unit under test
*/
#include "Tr3PL.c"              /* Note the .c */

/* 
 * ===============================================================
 */

/* Variables I need. */

#define TEST_TR3PL_LIST_UUT_LEN 6U
struct Tr3PL_Lst_s Test_Tr3PL_list_UUT[TEST_TR3PL_LIST_UUT_LEN];
struct Tr3PL_RootEle_s Test_Tr3PL_re_UUT;

struct Tr3PL_Lst_s Test_Tr3PL_list_refInit[TEST_TR3PL_LIST_UUT_LEN] = {
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY}
};
struct Tr3PL_RootEle_s Test_Tr3PL_re_refInit =
    { TR3B_EMPTY, TR3B_EMPTY, TEST_TR3PL_LIST_UUT_LEN };

struct Tr3PL_Lst_s Test_Tr3PL_list_refInsert285[TEST_TR3PL_LIST_UUT_LEN] = {
    {2, 2, 2, TR3B_EMPTY},
    {8, 8, TR3B_EMPTY, 2},
    {5, 5, 1, 0},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY}
};
struct Tr3PL_RootEle_s Test_Tr3PL_re_refInsert285 =
    { 1, 0, TEST_TR3PL_LIST_UUT_LEN };

struct Tr3PL_Lst_s Test_Tr3PL_list_refRemoveHi[TEST_TR3PL_LIST_UUT_LEN] = {
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {8, 8, TR3B_EMPTY, 2},
    {5, 5, 1, 0},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY}
};
struct Tr3PL_RootEle_s Test_Tr3PL_re_refRemoveHi =
    { 1, 2, TEST_TR3PL_LIST_UUT_LEN };

struct Tr3PL_Lst_s Test_Tr3PL_list_refRemoveLo[TEST_TR3PL_LIST_UUT_LEN] = {
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {5, 5, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY}
};
struct Tr3PL_RootEle_s Test_Tr3PL_re_refRemoveLo =
    { 2, 2, TEST_TR3PL_LIST_UUT_LEN };

struct Tr3PL_Lst_s Test_Tr3PL_list_refInsert3728[TEST_TR3PL_LIST_UUT_LEN] = {
    {3, 3, 2, 3},
    {7, 8, 4, 2},
    {5, 5, 1, 0},
    {2, 2, 0, TR3B_EMPTY},
    {8, 8, TR3B_EMPTY, 1},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY}
};
struct Tr3PL_RootEle_s Test_Tr3PL_re_refInsert3728 =
    { 4, 3, TEST_TR3PL_LIST_UUT_LEN };

struct Tr3PL_Lst_s Test_Tr3PL_list_refVer572[TEST_TR3PL_LIST_UUT_LEN] = {
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {7, 8, TR3B_EMPTY, 2},
    {5, 5, 1, 3},
    {2, 2, 2, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY},
    {TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY, TR3B_EMPTY}
};
struct Tr3PL_RootEle_s Test_Tr3PL_re_refVer572 =
    { 1, 3, TEST_TR3PL_LIST_UUT_LEN };


/* 
 * ===============================================================
 */

/** Test unique helpers.
*/

void Helper_dump(void)
{
    printf("\n");
    printf("h %d t %d l %d \n", Test_Tr3PL_re_UUT.head, Test_Tr3PL_re_UUT.tail,
           Test_Tr3PL_re_UUT.leng);
    for (uint8_t i = 0; i < TEST_TR3PL_LIST_UUT_LEN; i++)
    {
        printf("%d : k %d p %d e %d n %d \n", i, Test_Tr3PL_list_UUT[i].key,
               Test_Tr3PL_list_UUT[i].pri, Test_Tr3PL_list_UUT[i].prev,
               Test_Tr3PL_list_UUT[i].next);

    }
    printf("\n");
}

int Helper_cmpLst(struct Tr3PL_Lst_s *ref, struct Tr3PL_Lst_s *targ,
                  struct Tr3PL_RootEle_s *for_leng)
{
    int ret_Val = EXIT_SUCCESS;
    uint8_t i;

    for (i = 0; (i < for_leng->leng) && (ret_Val == EXIT_SUCCESS); i++)
    {
        if ((targ->key != ref->key) || (targ->pri != ref->pri)
            || (targ->prev != ref->prev) || (targ->next != ref->next))
        {
            ret_Val = EXIT_FAILURE;
        }
    }

    return ret_Val;
}

int Helper_cmpRe(struct Tr3PL_RootEle_s *ref, struct Tr3PL_RootEle_s *targ)
{
    int ret_Val = EXIT_SUCCESS;

    if ((targ->head != ref->head)
        || (targ->tail != ref->tail) || (targ->leng != ref->leng))
    {
        ret_Val = EXIT_FAILURE;
    }

    return ret_Val;
}

/* 
 * ===============================================================
 */

/** Mocks for all unresolved externals.
*/

void Tr3SomethingWeRelyUponFromTr3UsingSameName(void)
{
    /* code */
}

/* 
 * ===============================================================
 */

/* Actual TestSteps. * Return an exit code. * Vocalize only on error. */

int TestStep_verifyInitByDirectObservation(void)
{
    int ret_Val = EXIT_SUCCESS;

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpRe(&Test_Tr3PL_re_refInit,
                          &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf
                ("TestStep_verifyInitByDirectObservation: root element init fail.\n");
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpLst(&Test_Tr3PL_list_refInit[0],
                           &Test_Tr3PL_list_UUT[0],
                           &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_verifyInitByDirectObservation: list init fail.\n");
        }
    }

    return ret_Val;
}

int TestStep_insert285(void)
{
    int ret_Val = EXIT_SUCCESS;

    if (ret_Val == EXIT_SUCCESS)
    {
        Tr3PL_insert(2, 2, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
        Tr3PL_insert(8, 8, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
        Tr3PL_insert(5, 5, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpRe(&Test_Tr3PL_re_refInsert285,
                          &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_insert285: root element fail.\n");
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpLst(&Test_Tr3PL_list_refInsert285[0],
                           &Test_Tr3PL_list_UUT[0],
                           &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_insert285: list fail.\n");
        }
    }

    return ret_Val;
}

int TestStep_removeHi(void)
{
    int ret_Val = EXIT_SUCCESS;
    uint8_t kf;
    uint8_t pf;

    if (ret_Val == EXIT_SUCCESS)
    {
        Tr3PL_removeHi(&Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT, &kf, &pf);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((kf != 2) || (pf != 2))
        {
            printf("TestStep_removeHi: key or pri fail.\n");
            ret_Val = EXIT_FAILURE;
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpRe(&Test_Tr3PL_re_refRemoveHi,
                          &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_removeHi: root element fail.\n");
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpLst(&Test_Tr3PL_list_refRemoveHi[0],
                           &Test_Tr3PL_list_UUT[0],
                           &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_removeHi: list fail.\n");
        }
    }

    return ret_Val;
}

int TestStep_removeLo(void)
{
    int ret_Val = EXIT_SUCCESS;
    uint8_t kf;
    uint8_t pf;

    if (ret_Val == EXIT_SUCCESS)
    {
        Tr3PL_removeLo(&Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT, &kf, &pf);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((kf != 8) || (pf != 8))
        {
            printf("TestStep_removeLo: key or pri fail.\n");
            ret_Val = EXIT_FAILURE;
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpRe(&Test_Tr3PL_re_refRemoveLo,
                          &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_removeLo: root element fail.\n");
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpLst(&Test_Tr3PL_list_refRemoveLo[0],
                           &Test_Tr3PL_list_UUT[0],
                           &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_removeLo: list fail.\n");
        }
    }

    return ret_Val;
}

int TestStep_insert3728(void)
{
    int ret_Val = EXIT_SUCCESS;

    if (ret_Val == EXIT_SUCCESS)
    {
        Tr3PL_insert(3, 3, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
        Tr3PL_insert(7, 8, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
        Tr3PL_insert(2, 2, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
        Tr3PL_insert(8, 8, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpRe(&Test_Tr3PL_re_refInsert3728,
                          &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_insert3728: root element fail.\n");
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpLst(&Test_Tr3PL_list_refInsert3728[0],
                           &Test_Tr3PL_list_UUT[0],
                           &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_insert3728: list fail.\n");
        }
    }

    return ret_Val;
}

int TestStep_fndRmv38(void)
{
    int ret_Val = EXIT_SUCCESS;
    uint8_t i3;
    uint8_t k3;
    uint8_t p3;
    uint8_t i8;
    uint8_t k8;
    uint8_t p8;

    if (ret_Val == EXIT_SUCCESS)
    {
        i3 = Tr3PL_find(3, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
        i8 = Tr3PL_find(8, &Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((i3 != 0) || (i8 != 4))
        {
            printf("TestStep_fndRmv38: index find fail.\n");
            ret_Val = EXIT_FAILURE;
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        Tr3PL_removeAt(&Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT, i3, &k3,
                       &p3);
        Tr3PL_removeAt(&Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT, i8, &k8,
                       &p8);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((k3 != 3) || (p3 != 3) || (k8 != 8) || (k8 != 8))
        {
            printf("TestStep_fndRmv38: remove at key or pri fail.\n");
            ret_Val = EXIT_FAILURE;
        }
    }

    return ret_Val;
}

int TestStep_ver572(void)
{
    int ret_Val = EXIT_SUCCESS;

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpRe(&Test_Tr3PL_re_refVer572,
                          &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_ver572: root element fail.\n");
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((ret_Val =
             Helper_cmpLst(&Test_Tr3PL_list_refVer572[0],
                           &Test_Tr3PL_list_UUT[0],
                           &Test_Tr3PL_re_UUT)) != EXIT_SUCCESS)
        {
            printf("TestStep_ver572: list fail.\n");
        }
    }

    return ret_Val;
}

int TestStep_remLoHi(void)
{
    int ret_Val = EXIT_SUCCESS;
    uint8_t lok;
    uint8_t lop;
    uint8_t hik;
    uint8_t hip;

    if (ret_Val == EXIT_SUCCESS)
    {
        Tr3PL_removeLo(&Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT, &lok, &lop);
        Tr3PL_removeHi(&Test_Tr3PL_list_UUT[0], &Test_Tr3PL_re_UUT, &hik, &hip);
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((lok != 7) || (lop != 8))
        {
            printf("TestStep_remLoHi: lo fail.\n");
            ret_Val = EXIT_FAILURE;
        }
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        if ((hik != 2) || (hip != 2))
        {
            printf("TestStep_remLoHi: hi fail.\n");
            ret_Val = EXIT_FAILURE;
        }
    }

    return ret_Val;
}

/* 
 * ===============================================================
 */

/* setUp and tearDown. * For a specific step, name it setUp_MeaningfulName, and so on. */

void setUp(void)
{
    Tr3PL_init(&Test_Tr3PL_list_UUT[0], TEST_TR3PL_LIST_UUT_LEN,
               &Test_Tr3PL_re_UUT);
}

void tearDown(void)
{
    /* code */
}

/* 
 * ===============================================================
 */

int main(int argc, char const *argv[])
{
    int ret_Val = 0;

    printf("Test_Tr3PL\n");

    setUp();

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_verifyInitByDirectObservation();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_insert285();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_removeHi();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_removeLo();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_insert3728();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_fndRmv38();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_ver572();
    }

    if (ret_Val == EXIT_SUCCESS)
    {
        ret_Val = TestStep_remLoHi();
    }

    tearDown();

    exit(ret_Val);
}
