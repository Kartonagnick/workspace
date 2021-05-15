// [2021y-05m-15d][00:42:36] Idrisov Denis R.
#pragma once

#ifndef dTEST_LIST_STABLE_USED_ 
#define dTEST_LIST_STABLE_USED_ 1

#ifndef STABLE_RELEASE
    #error #include <test-stable.hpp> require #define STABLE_RELEASE
#endif

    #define dFORBID_ZERO_SIZE_ARRAY
    #define INCLUDE_AUTO_GENERATED

    // #define INCLUDE_STRESS_TESTS
    #define INCLUDE_LONG_LONG_TESTS
    #define INCLUDE_LONG_TESTS

//==============================================================================
//===== classic/modern =====================================||==================
    #define TEST_MODERN                                     // ready!
    #define TEST_CLASSIC                                    // ready!
//==========================================================||==================
//==============================================================================

#endif // !dTEST_LIST_STABLE_USED_

