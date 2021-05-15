// [2021y-04m-29d][14:27:04] Idrisov Denis R. 100
// [2021y-05m-15d][23:54:07] Idrisov Denis R. 101
// [2021y-05m-15d][21:39:59] Idrisov Denis R. 101
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

    #ifdef __cplusplus
        dMESSAGE("__cplusplus: " dSSTRINGIZE(__cplusplus)) 

        #if __cplusplus >= 201103L
            dMESSAGE("c++11: enabled") 
        #endif

        #if __cplusplus >= 201402L
            dMESSAGE("c++14: enabled") 
        #endif

        #if __cplusplus >= 201703L
            dMESSAGE("c++17: enabled") 
        #endif

        #if __cplusplus >= 202002L
            dMESSAGE("c++20: enabled") 
        #endif

        #if __cplusplus < 202002L
            dMESSAGE("c++old: enabled") 
        #endif

    #else
        dMESSAGE("__cplusplus: not specified") 
    #endif

//==============================================================================
//==============================================================================

    #if defined(__GNUC__) 
        dMESSAGE("gnu: enabled") 
    #endif

    #if defined(__MINGW__) || defined(__MINGW32__)
        dMESSAGE("mingw: enabled") 
    #endif

//==============================================================================
//==============================================================================

    #if defined(_MSC_VER)

        #pragma message("_MSC_FULL_VER ..... " dSSTRINGIZE(_MSC_FULL_VER))

        #ifdef _MSVC_LANG
            #pragma message("_MSVC_LANG ........ " dSSTRINGIZE(_MSVC_LANG))
        #else
            #pragma message("_MSVC_LANG ........  not specified")
        #endif

        #if defined(_MSC_EXTENSIONS) && _MSC_EXTENSIONS != 0
            #pragma message("_MSC_EXTENSIONS ... enabled")
        #else
            #pragma message("_MSC_EXTENSIONS ... disabled")
        #endif

        #if _MSC_VER >= 1929 
            #pragma message("msvc2019: 16.10") 

        #elif _MSC_VER == 1928 
            #if _MSC_FULL_VER == 192829915
                #pragma message("msvc2019: 16.9.5") 
            #elif _MSC_FULL_VER == 192829913
                #pragma message("msvc2019: 16.9.2") 
            #elif _MSC_FULL_VER == 192829334
                #pragma message("msvc2019: 16.8.2") 
            #elif _MSC_FULL_VER == 192829333
                #pragma message("msvc2019: 16.8.1") 
            #else
                #pragma message("[WARNING] msvc2019: 16.8 or 16.9") 
            #endif

        #elif _MSC_VER == 1927 
            #if _MSC_FULL_VER == 192729112
                #pragma message("msvc2019: 16.7") 
            #else
                #pragma message("[WARNING] msvc2019: 16.7") 
            #endif

        #elif _MSC_VER == 1926 
            #if _MSC_FULL_VER == 192628806
                #pragma message("msvc2019: 16.6.2") 
            #else
                #pragma message("[WARNING] msvc2019: 16.6.2") 
            #endif

        #elif _MSC_VER == 1925 
            #if _MSC_FULL_VER == 192528611
                #pragma message("msvc2019: 16.5.1") 
            #else
                #pragma message("[WARNING] msvc2019: 16.5.1") 
            #endif

        #elif _MSC_VER == 1924 
            #if _MSC_FULL_VER == 192428314
                #pragma message("msvc2019: 16.4.0") 
            #else
                #pragma message("[WARNING] msvc2019: 16.4.0") 
            #endif

        #elif _MSC_VER == 1923 
            #if _MSC_FULL_VER == 192328105
                #pragma message("msvc2019: 16.3.2") 
            #else
                #pragma message("[WARNING] msvc2019: 16.3.2") 
            #endif

        #elif _MSC_VER == 1922 
            #if _MSC_FULL_VER == 192227905
                #pragma message("msvc2019: 16.2.3") 
            #else
                #pragma message("[WARNING] msvc2019: 16.2.3") 
            #endif

        #elif _MSC_VER == 1921 
            #if _MSC_FULL_VER == 192127702
                #pragma message("msvc2019: 16.1.2") 
            #else
                #pragma message("[WARNING] msvc2019: 16.1.2") 
            #endif

        #elif _MSC_VER == 1920 
            #if _MSC_FULL_VER == 192027508
                #pragma message("msvc2019: RTW-16.0.0") 
            #else
                #pragma message("[WARNING] msvc2019: RTW-16.0.0") 
            #endif

        #elif _MSC_VER == 1916 
            #if _MSC_FULL_VER == 191627045
                #pragma message("msvc2017: 15.9.35 (36)") 
            #elif _MSC_FULL_VER == 191627030
                #pragma message("msvc2017: 15.9.11") 
            #elif _MSC_FULL_VER == 191627027
                #pragma message("msvc2017: 15.9.7") 
            #elif _MSC_FULL_VER == 191627026
                #pragma message("msvc2017: 15.9.5") 
            #elif _MSC_FULL_VER == 191627025
                #pragma message("msvc2017: 15.9.4") 
            #elif _MSC_FULL_VER == 191627023
                #pragma message("msvc2017: 15.9.1") 
            #else
                #pragma message("[WARNING] msvc2017: 15.9.?") 
            #endif

        #elif _MSC_VER == 1915 
            #pragma message("msvc2017: 15.8") 
        #elif _MSC_VER == 1914 
            #if _MSC_FULL_VER == 191426433
                #pragma message("msvc2017: 15.7.5") 
            #elif _MSC_FULL_VER == 191426429
                #pragma message("msvc2017: 15.7.2") 
            #elif _MSC_FULL_VER == 191426428
                #pragma message("msvc2017: 15.7.1") 
            #elif _MSC_FULL_VER == 191426428
                #pragma message("msvc2017: 15.7.1") 
            #else
                #pragma message("[WARNING] msvc2017: 15.7.?") 
            #endif

        #elif _MSC_VER == 1913 
            #if _MSC_FULL_VER == 191326132
                #pragma message("msvc2017: 15.6.7") 
            #elif _MSC_FULL_VER == 191326131
                #pragma message("msvc2017: 15.6.6") 
            #elif _MSC_FULL_VER == 191326129
                #pragma message("msvc2017: 15.6.4") 
            #elif _MSC_FULL_VER == 191326128
                #pragma message("msvc2017: 15.6.0") 
            #else
                #pragma message("[WARNING] msvc2017: 15.6.?") 
            #endif

        #elif _MSC_VER == 1912 
            #if _MSC_FULL_VER == 191225835
                #pragma message("msvc2017: 15.5.7") 
            #elif _MSC_FULL_VER == 191225834
                #pragma message("msvc2017: 15.5.3") 
            #elif _MSC_FULL_VER == 191225831
                #pragma message("msvc2017: 15.5.2") 
            #else
                #pragma message("[WARNING] msvc2017: 15.5.?") 
            #endif

        #elif _MSC_VER == 1911 
            #if _MSC_FULL_VER == 191125547
                #pragma message("msvc2017: 15.4.5") 
            #elif _MSC_FULL_VER == 191125542
                #pragma message("msvc2017: 15.4.4") 
            #elif _MSC_FULL_VER == 191125507
                #pragma message("msvc2017: 15.3.3") 
            #else
                #pragma message("[WARNING] msvc2017: 15.3.?") 
            #endif

        #elif _MSC_VER == 1910 
            #if _MSC_FULL_VER == 191025017
                #pragma message("msvc2017: 15.2") 
            #else
                #pragma message("[WARNING] msvc2017: 15.0.?") 
            #endif

        #elif _MSC_VER == 1900 
            #if _MSC_FULL_VER == 190024215
                #pragma message("msvc2015: Update 3 [14.0][1]") 
            #elif _MSC_FULL_VER == 190024210
                #pragma message("msvc2015: Update 3 [14.0]") 
            #elif _MSC_FULL_VER == 190023918
                #pragma message("msvc2015: Update 2 [14.0]") 
            #elif _MSC_FULL_VER == 190023506
                #pragma message("msvc2015: Update 1 [14.0]") 
            #elif _MSC_FULL_VER == 190023026
                #pragma message("msvc2015: [14.0]") 
            #else
                #pragma message("[WARNING] msvc2015: 14.0.?") 
            #endif

        #elif _MSC_VER == 1800 
            #if _MSC_FULL_VER == 180021114
                #pragma message("msvc2013: Nobemver CTP [12.0]") 
            #elif _MSC_FULL_VER == 180040629
                #pragma message("msvc2013: Update 5 [12.0]") 
            #elif _MSC_FULL_VER == 180031101
                #pragma message("msvc2013: Update 4 [12.0]") 
            #elif _MSC_FULL_VER == 180030723
                #pragma message("msvc2013: Update 3 [12.0]") 
            #elif _MSC_FULL_VER == 180030501
                #pragma message("msvc2013: Update 2 [12.0]") 
            #elif _MSC_FULL_VER == 180030324
                #pragma message("msvc2013: Update2 RC [12.0]") 
            #elif _MSC_FULL_VER == 180021005
                #pragma message("msvc2013: [12.0]") 
            #elif _MSC_FULL_VER == 180020827
                #pragma message("msvc2013: RC [12.0]") 
            #elif _MSC_FULL_VER == 180020617
                #pragma message("msvc2013: Preview [12.0]") 
            #else
                #pragma message("[WARNING] msvc2013: 12.0.?") 
            #endif

        #elif _MSC_VER == 1700 
            #if _MSC_FULL_VER == 170051025
                #pragma message("msvc2012: November CTP [11.0]") 
            #elif _MSC_FULL_VER == 170061030
                #pragma message("msvc2012: Update 4 [11.0]") 
            #elif _MSC_FULL_VER == 170060610
                #pragma message("msvc2012: Update 3 [11.0]") 
            #elif _MSC_FULL_VER == 170060315
                #pragma message("msvc2012: Update 2 [11.0]") 
            #elif _MSC_FULL_VER == 170051106
                #pragma message("msvc2012: Update 1 [11.0]") 
            #elif _MSC_FULL_VER == 170050727
                #pragma message("msvc2012: [11.0]") 
            #else
                #pragma message("[WARNING] msvc2012: 11.0.?") 
            #endif
        #elif _MSC_VER == 1600 
            #if _MSC_FULL_VER == 160040219
                #pragma message("msvc2010: SP1 [10.0]") 
            #elif _MSC_FULL_VER == 160030319
                #pragma message("msvc2010: [10.0]") 
            #elif _MSC_FULL_VER == 160021003
                #pragma message("msvc2010: Beta 2 [10.0]") 
            #elif _MSC_FULL_VER == 160020506
                #pragma message("msvc2010: Beta 1 [10.0]") 
            #else
                #pragma message("[WARNING] msvc2010: 10.0.?") 
            #endif

        #elif _MSC_VER == 1500 
            #if _MSC_FULL_VER == 150030729
                #pragma message("msvc2008: SP1 [9.0]") 
            #elif _MSC_FULL_VER == 150021022
                #pragma message("msvc2008: [9.0]") 
            #elif _MSC_FULL_VER == 150020706
                #pragma message("msvc2008: Beta 2 [9.0]") 
            #else
                #pragma message("[WARNING] msvc2008: 9.0.?") 
            #endif

        #elif _MSC_VER == 1400 
            #if _MSC_FULL_VER == 140050727
                #pragma message("msvc2005: SP1 [8.0]") 
            #elif _MSC_FULL_VER == 140050320
                #pragma message("msvc2005: [8.0]") 
            #elif _MSC_FULL_VER == 140050215
                #pragma message("msvc2005: Beta 2 [8.0]") 
            #elif _MSC_FULL_VER == 140040607
                #pragma message("msvc2005: Beta 1 [8.0]") 
            #elif _MSC_FULL_VER == 140040310
                #pragma message("msvc2005: 2003 SP1 DDK (for AMD64)") 
            #else
                #pragma message("[WARNING] msvc2005: 8.0.?") 
            #endif

        #elif _MSC_VER == 1310 
            #if _MSC_FULL_VER == 13106030
                #pragma message("msvc2003: 2003 SP1 [7.1]") 
            #elif _MSC_FULL_VER == 13104035
                #pragma message("msvc2003: Windows Server 2003 SP1 DDK") 
            #elif _MSC_FULL_VER == 13103077
                #pragma message("msvc2003: 2003 [7.1]") 
            #elif _MSC_FULL_VER == 13103052
                #pragma message("msvc2003: Toolkit 2003 [7.1]") 
            #elif _MSC_FULL_VER == 13102292
                #pragma message("msvc2003: 2003 Beta [7.1]") 
            #elif _MSC_FULL_VER == 13102179
                #pragma message("msvc2003: 2003 DDK") 
            #else
                #pragma message("[WARNING] msvc2003: .NET 7.1.?") 
            #endif

        #elif _MSC_VER == 1300 
            #if _MSC_FULL_VER == 13009466
                #pragma message("msvc2002: 2002 [7.0]") 
            #elif _MSC_FULL_VER == 13009176
                #pragma message("msvc2002: SP1 DDK") 
            #else
                #pragma message("msvc2002: 7.0.?") 
            #endif

        #elif _MSC_VER == 1200 
            #if _MSC_FULL_VER == 12008804
                #pragma message("msvc60: 6.0 SP5") 
            #else
                #pragma message("[WARNING] msvc60: 6.0.?") 
            #endif

        #elif _MSC_VER == 1100 
            // msvc5.0 5.0
            #pragma message("msvc50: 5.0") 
        #elif _MSC_VER == 1020 
            // msvc42 4.2
            #pragma message("msvc42 4.2") 
        #elif _MSC_VER == 1010 
            // msvc41 4.1
            #pragma message("msvc41 4.1") 
        #elif _MSC_VER == 1000 
            // msvc41 4.0
            #pragma message("msvc40 4.0") 
        #elif _MSC_VER == 900 
            // msvc41 2.0
            #pragma message("msvc20 2.0") 
        #elif _MSC_VER == 800 
            // msvc10 1.0
            #pragma message("msvc10 1.0") 
        #elif _MSC_VER == 700 
            // msvc7 7.0
            #pragma message("msvc7") 
        #elif _MSC_VER == 600 
            // msvc6 6.0 (pure-c only)
            #pragma message("msvc6") 
        #else
            #error too old msvc not support
        #endif
    #endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMPILERS_USED_
