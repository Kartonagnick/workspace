// [2021y-04m-29d][14:27:04] Idrisov Denis R. 100
// [2021y-05m-08d][23:54:07] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_COMPILERS_USED_ 
#define dTOOLS_COMPILERS_USED_ 101
//==============================================================================
//=== dMESSAGE =================================================================

#ifdef _MSC_VER
    #define dMESSAGE(...)  __pragma(message(__VA_ARGS__))
#else
    #define dMESSAGE(...) 
#endif

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

//==============================================================================
//==============================================================================

    #if defined(__cplusplus) && __cplusplus >= 201103L
        dMESSAGE("c++11: enabled") 
    #endif
    #if defined(__cplusplus) && __cplusplus >= 201402L
        dMESSAGE("c++14: enabled") 
    #endif
    #if defined(__cplusplus) && __cplusplus >= 201703L
        dMESSAGE("c++17: enabled") 
    #endif
    #if defined(__cplusplus) && __cplusplus >= 202002L
        dMESSAGE("c++20: enabled") 
    #endif

    #if defined(__GNUC__) 
        dMESSAGE("gnu: enabled") 
    #endif

    #if defined(__MINGW__) || defined(__MINGW32__)
        dMESSAGE("mingw: enabled") 
    #endif

    #if defined(_MSC_VER)

        #ifdef _MSVC_LANG
            #pragma message("msvc: lang : " dSSTRINGIZE(_MSVC_LANG))
        #else
            #pragma message("msvc: _MSVC_LANG : not specified")
        #endif

        #pragma message("msvc: full version: " dSSTRINGIZE(_MSC_FULL_VER))

        #if defined(_MSC_EXTENSIONS) && _MSC_EXTENSIONS != 0
            #pragma message("msvc: extension: enabled")
        #else
            #pragma message("msvc: extension: disabled")
        #endif

        #if _MSC_VER >= 1929 
            #pragma message("msvc2019: 16.10") 
        #elif _MSC_VER == 1928 
            #pragma message("msvc2019: 16.8, 16.9") 
        #elif _MSC_VER == 1927 
            #pragma message("msvc2019: 16.7") 
        #elif _MSC_VER == 1926 
            #pragma message("msvc2019: 16.6") 
        #elif _MSC_VER == 1925 
            #pragma message("msvc2019: 16.5") 
        #elif _MSC_VER == 1924 
            #pragma message("msvc2019: 16.4") 
        #elif _MSC_VER == 1923 
            #pragma message("msvc2019: 16.3") 
        #elif _MSC_VER == 1921 
            #pragma message("msvc2019: 16.1") 
        #elif _MSC_VER == 1920 
            #pragma message("msvc2019: RTW-16.0") 

        #elif _MSC_VER == 1916 
            #pragma message("msvc2017: 15.9") 
        #elif _MSC_VER == 1915 
            #pragma message("msvc2017: 15.8") 
        #elif _MSC_VER == 1914 
            #pragma message("msvc2017: 15.7") 
        #elif _MSC_VER == 1913 
            #pragma message("msvc2017: 15.6") 
        #elif _MSC_VER == 1912 
            #pragma message("msvc2017: 15.5") 
        #elif _MSC_VER == 1911 
            #pragma message("msvc2017: 15.3") 
        #elif _MSC_VER == 1919 
            #pragma message("msvc2017: RTW-15.0") 

        #elif _MSC_VER == 1900 
            #pragma message("msvc2015: 14.0") 
        #elif _MSC_VER == 1800 
            #pragma message("msvc2013: 12.0") 
        #elif _MSC_VER == 1700 
            #pragma message("msvc2012: 11.0") 
        #elif _MSC_VER == 1600 
            #pragma message("msvc2010: 10.0") 
        #elif _MSC_VER == 1500 
            #pragma message("msvc2008: 9.0") 

        #elif _MSC_VER == 1400 
            // msvc2005 8.0
            #pragma message("msvc2005: 8.0") 
        #elif _MSC_VER == 1310 
            // msvc2003 .NET 7.1
            #pragma message("msvc2017: RTW-15.0") 
        #elif _MSC_VER == 1300 
            // msvc2002 .NET 7.0
            #pragma message("msvc2017: RTW-15.0") 
        #elif _MSC_VER == 1200 
            // msvc6 6.0
            #pragma message("msvc2017: RTW-15.0") 
        #else
            #error too old msvc not support
        #endif
    #endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMPILERS_USED_
