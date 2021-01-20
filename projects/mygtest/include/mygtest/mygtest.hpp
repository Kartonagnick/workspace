
// [2020y-12m-05d] Idrisov Denis R.
//==============================================================================
//==============================================================================

#pragma once
#ifndef dMYGTEST_USED_ 
#define dMYGTEST_USED_

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