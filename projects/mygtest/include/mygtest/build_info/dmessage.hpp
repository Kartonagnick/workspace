// [2021y-05m-21d][22:24:50] Idrisov Denis R. 001 PRE
#pragma once
#ifndef dTOOLS_DMESSAGE_USED_ 
#define dTOOLS_DMESSAGE_USED_ 001 PRE

//==============================================================================
//=== dSTRINGIZE ===============================================================

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

//==============================================================================
//=== dCOMPILR =================================================================

#if defined(_MSC_VER)
    #define dMSVC_COMPILER 1

#elif defined(__MINGW__) || defined(__MINGW32__)
    #define dMINGW_COMPILER 1

#elif defined(__GNUC__) || defined(__GNUG__)
    #define dGCC_COMPILER 1

#else
    #define dUNKNOWN_COMPILER

#endif

//==============================================================================
//=== dMESSAGE =================================================================

#if defined(dMSVC_COMPILER)
    #ifdef dHIDE_MSVC_MESSAGE
        #define dMESSAGE(...)
    #else
        #define dMESSAGE(...)  __pragma(message(__VA_ARGS__))
    #endif

#elif defined(dMINGW_COMPILER)
    #ifdef dHIDE_MINGW_MESSAGE
        #define dMESSAGE(...)
    #else
        #define dMESSAGE(...)  _Pragma(dSTRINGIZE(message __VA_ARGS__))
    #endif

#elif defined(dGCC_COMPILER)
    #ifdef dHIDE_GCC_MESSAGE
        #define dMESSAGE(...)
    #else
        #define dMESSAGE(...)  _Pragma(dSTRINGIZE(message __VA_ARGS__))
    #endif

#else
    #define dMESSAGE(...) 
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DMESSAGE_USED_
