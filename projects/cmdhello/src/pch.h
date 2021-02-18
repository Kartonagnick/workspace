
#pragma once

#ifdef _MSC_VER
    #ifdef STABLE_RELEASE
        #pragma message("cmdhello: Build stable release version")
    #else
        #pragma message("cmdhello: Build development version")
    #endif
#endif

#include <cstdio>



