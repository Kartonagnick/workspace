// [2020y-12m-05d] Idrisov Denis R.
// [2021y-01m-20d] Idrisov Denis R.
// [2021y-05m-15d][00:42:36] Idrisov Denis R.
// [2021y-15m-21d][23:10:07] Idrisov Denis R. 206 (PRE)
// [2021y-15m-21d][23:58:59] Idrisov Denis R. 206
//==============================================================================
//==============================================================================

#pragma once
#ifndef dMYGTEST_USED_ 
#define dMYGTEST_USED_ 206

#if defined(__GNUC__)
    #pragma GCC system_header
#endif

//==============================================================================
//==============================================================================

#ifdef _MSC_VER
    #if defined(dGMOCK_LIBRARY_USED_)
        #pragma message("InitGoogleMock...")

    #elif defined(dGTEST_LIBRARY_USED_)
        #pragma message("InitGoogleTest...")

    #else
        #pragma message("[WARNING] InitGoogleTest by default...")
    #endif
#endif

//==============================================================================
//==============================================================================

#if defined(dGMOCK_LIBRARY_USED_)
    #include <gtest/gtest.h>
    #include <gmock/gmock.h>

#elif defined(dGTEST_LIBRARY_USED_)
    #include <gtest/gtest.h>

#else
    #define dGTEST_LIBRARY_USED_ 1
    #include <gtest/gtest.h>

#endif

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_USED_