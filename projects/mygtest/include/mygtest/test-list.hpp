
// [2020y-12m-05d] Idrisov Denis R.
// [2021y-01m-20d] Idrisov Denis R.

#pragma once
#ifndef dMYGTEST_TEST_LIST_USED_ 
#define dMYGTEST_TEST_LIST_USED_
//==============================================================================
//==============================================================================

#include <mygtest/component.hpp>
#include <mygtest/mygtest.hpp>
#ifdef STABLE_RELEASE
    #include "test-stable.hpp"
#else
    #include "test-develop.hpp"    
#endif

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_TEST_LIST_USED_