// [2021y-05m-15d][00:42:36] Idrisov Denis R.
#pragma once
#ifndef dTEST_LIST_DEV_USED_ 
#define dTEST_LIST_DEV_USED_ 1

#ifdef STABLE_RELEASE
    #error STABLE_RELEASE require #include <test-stable.hpp>
#endif

    #define CODE_GENERATION_ON
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

#endif // !dTEST_LIST_DEV_USED_
