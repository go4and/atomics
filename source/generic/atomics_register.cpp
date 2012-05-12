/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "atomics_autodefs.h"
#include "s3eEdk.h"
#include "atomics.h"
//Declarations of Init and Term functions
extern s3eResult atomicsInit();
extern void atomicsTerminate();


void atomicsRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[1];
    funcPtrs[0] = (void*)atomicsGetTable;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[1] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("atomics", funcPtrs, sizeof(funcPtrs), flags, atomicsInit, atomicsTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int atomicsStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&atomicsRegisterExt;
    return 0;
}

int g_atomicsVal = atomicsStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    atomicsRegisterExt();
}
#endif

#endif
