/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84_goodG2B.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84.h"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84
{
CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84_goodG2B::CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84_goodG2B(int * dataCopy)
{
    data = dataCopy;
    /* FIX: Allocate memory using sizeof(int) */
    data = (int *)ALLOCA(10*sizeof(int));
}

CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84_goodG2B::~CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_84_goodG2B()
{
    {
        int source[10] = {0};
        size_t i;
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
    }
}
}
#endif /* OMITGOOD */
