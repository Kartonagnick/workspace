
#pragma once

#ifdef _MSC_VER
    #pragma message("pch -> enabled")

    #include <mygtest/confbuild.hpp>
    #pragma message("test: " dFULL_VERSION)

    #ifdef STABLE_RELEASE
        #pragma message("Build stable release version")
    #else
        #pragma message("Build development version")
    #endif
#endif

#include <mygtest/pch_used.hpp>

//================================================================================
//================================================================================
