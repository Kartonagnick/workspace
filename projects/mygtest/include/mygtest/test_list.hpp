
#pragma once

#include <mygtest/component.hpp>
#include <mygtest/mygtest.hpp>
#ifdef STABLE_RELEASE
    #include "test_list_stable.hpp"
#else
    #include "test_list_dev.hpp"    
#endif

