// [2021y-03m-19d][14:33:03] Idrisov Denis R. 100
// [2021y-03m-22d][94:30:36] Idrisov Denis R. 100
// [2021y-05m-14d][22:20:01] Idrisov Denis R. 101
// [2021y-05m-15d][03:13:54] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_CONFBUILD_USED_
#define dTOOLS_CONFBUILD_USED_ 101
//==============================================================================
//==============================================================================

#if !defined(dX64) && !defined(dX32)
    #ifdef _WIN32
        #ifdef _WIN64
            #define dX64 1
        #else
            #define dX32 1
        #endif
    #else
        #if defined(__LP64__) || defined(_M_IA64)
            #define dX64 1
        #else
            #define dX32 1
        #endif
    #endif
#endif

#if defined(dX64)
    #define dTXT_AMODEL "x64"
#elif defined(dX32)
    #define dTXT_AMODEL "x86"
#endif

#ifdef NDEBUG
    #define dTXT_CONFIG "release"
    #ifdef _DLL
        #define dTXT_CRT "MD"
    #else
        #define dTXT_CRT "MT"
    #endif
#else
    #define dTXT_CONFIG "debug"
    #ifdef _DLL
        #define dTXT_CRT "MDd"
    #else
        #define dTXT_CRT "MTd"
    #endif
#endif

#ifdef STABLE_RELEASE
    #define dTXT_STABLE "stable"
#else
    #define dTXT_STABLE "unstable"
#endif

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

#define dBASIC_VERSION_NUM(MAJOR, MINOR, PATCH) \
    MAJOR * 100 + MINOR * 10 + PATCH

#define dBASIC_VERSION_STR(MAJOR, MINOR, PATCH) \
    dSSTRINGIZE(MAJOR.MINOR.PATCH)

#define dGET_BASIC_VERSION(NAME) \
    dBASIC_VERSION_STR(NAME##_MAJOR, NAME##_MINOR, NAME##_PATCH)   

#define dABOUT_ME \
    dTXT_AMODEL "-" dTXT_CONFIG "-" dTXT_CRT ", " dTXT_STABLE 

#define dFULL_ABOUT_ME(NAME) dGET_BASIC_VERSION(NAME) ", " dABOUT_ME

//==============================================================================
//==============================================================================
#endif // !dTOOLS_CONFBUILD_USED_

// example extract: 
// #define dGET_MAJOR(value)  value / 100
// #define dGET_MINOR(value) (value % 100)/10
// #define dGET_PATHS(value)  value % 10
