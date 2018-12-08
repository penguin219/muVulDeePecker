/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_82_bad.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_82.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_82
{

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_82_bad::action(int data)
{
    {
        size_t i;
        int *intPointer;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}

}
#endif /* OMITBAD */