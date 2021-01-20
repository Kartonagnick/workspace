
#pragma once
//================================================================================
//================================================================================

#ifdef _MSC_VER
    #ifdef STABLE_RELEASE
        #pragma message("STABLE_RELEASE: activate all unit-tests")
        #pragma message("STABLE_RELEASE: disable 'dprint'")
    #else
        #pragma message("UNSTABLE_RELEASE: individual unit-tests")
        #pragma message("UNSTABLE_RELEASE: enable 'dprint'")
    #endif
#endif

//================================================================================
//================================================================================

#include <mygtest/pch_weak.hpp>
#include <mygtest/mygtest.hpp>

//================================================================================
//================================================================================

