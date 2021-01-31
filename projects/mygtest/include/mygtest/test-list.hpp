
#pragma once

#include <mygtest/component.hpp>
#include <mygtest/mygtest.hpp>
#ifdef STABLE_RELEASE
    #include "test-stable.hpp"
#else
    #include "test-develop.hpp"    
#endif

