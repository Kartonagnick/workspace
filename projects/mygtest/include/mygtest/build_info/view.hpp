// [2021y-02m-16d][16:14:09] Idrisov Denis R.
// [2021y-03m-19d][14:51:27] Idrisov Denis R.
// [2021y-03m-22d][08:56:37] Idrisov Denis R.
// [2021y-03m-29d][14:48:27] Idrisov Denis R. 102
// [2021y-05m-14d][22:33:10] Idrisov Denis R. 103
// [2021y-05m-15d][03:14:37] Idrisov Denis R. 103
#pragma once
#ifndef dTOOLS_VIEW_BUILD_USED_
#define dTOOLS_VIEW_BUILD_USED_ 103
//================================================================================
//================================================================================

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

#include "compilers.hpp"
#include "confbuild.hpp"

#ifdef _MSC_VER

    #define dVIEW_VERSION(x,n) __pragma(message(x " " dFULL_ABOUT_ME(n)))

    #ifdef dPCH_USED
        #define dVIEW_PCH(x) __pragma(message(x " enabled -> pch"))
    #else
        #define dVIEW_PCH(x) __pragma(message(x " disabled -> pch"))
    #endif

    #ifdef STABLE_RELEASE
        #ifdef NDEBUG
            #define dVIEW_STABLE(x) __pragma(message(x " STABLE-RELEASE"))
        #else
            #define dVIEW_STABLE(x) __pragma(message(x " STABLE-DEBUG"))
        #endif
    #else
        #ifdef NDEBUG
            #define dVIEW_STABLE(x) __pragma(message(x " UNSTABLE-RELEASE"))
        #else
            #define dVIEW_STABLE(x) __pragma(message(x " UNSTABLE-DEBUG"))
        #endif
    #endif

    #ifdef _DLL
        #ifdef _DEBUG
            #define dVIEW_CRT(x) __pragma(message(x " MDd (debug-dynamic runtime c++)"))
        #else
            #define dVIEW_CRT(x) __pragma(message(x " MD (release-dynamic runtime c++)"))
        #endif
    #else
        #ifdef _DEBUG
            #define dVIEW_CRT(x) __pragma(message(x " MTd (debug-static runtime c++)"))
        #else
            #define dVIEW_CRT(x) __pragma(message(x " MT (release-static runtime c++)"))
        #endif
    #endif

    #define dVIEW_BUILD(title, name) \
        dVIEW_PCH(title)             \
        dVIEW_STABLE(title)          \
        dVIEW_CRT(title)             \
        dVIEW_VERSION(title, name)
#else
    // gcc not support
    #define dVIEW_BUILD(title, name)
#endif

//================================================================================
//================================================================================
#endif // !dTOOLS_VIEW_BUILD_USED_