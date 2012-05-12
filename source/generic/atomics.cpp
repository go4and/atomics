/*
Generic implementation of the atomics extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include <s3eEdk.h>

#include "atomics_internal.h"
s3eResult atomicsInit()
{
    return S3E_RESULT_SUCCESS;
}

void atomicsTerminate()
{
}

namespace {

int atomic_add(volatile int *x, int a)
{
    return __sync_fetch_and_add(x, a);
}

int atomic_cas(volatile int *x, int o, int n)
{
    return __sync_val_compare_and_swap(x, o, n);
}

}

extern void puts_wrap(const char *);

void atomicsGetTable(AtomicFunctions & out)
{
    out.add = atomic_add;
    out.cas = atomic_cas;
    out.nanosleep = nanosleep;
    out.sched_yield = sched_yield;
}
