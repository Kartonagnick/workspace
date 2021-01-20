
#pragma once
#ifndef dGMAIN_USED_
#define dGMAIN_USED_

// do not include the header in pch.hpp

#if defined(__GNUC__)
    #pragma GCC system_header
#endif

#include <mygtest/mygtest.hpp>
#include <mygtest/features.hpp>

#if defined(_DEBUG) && defined(_WIN32)
    #include <windows.h>
    #include <crtdbg.h>
#endif

#include <cassert>

//==============================================================================
//==============================================================================

namespace testing
{
    static inline void InitGoogleTestFramework(int argc, char** argv)
    {
        assert(argv);
        #if defined(dGMOCK_LIBRARY_USED_)
            ::testing::InitGoogleMock(&argc, argv);
        #elif defined(dGTEST_LIBRARY_USED_)
            ::testing::InitGoogleTest(&argc, argv);
        #else
            #error "unknown test system"
        #endif
    }

    static inline void PrepareEnvironment() dNOEXCEPT
    {
        #if defined(_DEBUG) && defined(_WIN32)
            _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
            _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
        #endif

        #if defined(_DEBUG) && defined(_WIN32) && defined(__MINGW32__)
            // this prevents annoying error message boxes popping up
            // when assert is called in your program code
            ::SetErrorMode(SEM_NOGPFAULTERRORBOX);
        #endif

        #if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW__)
            ::testing::FLAGS_gtest_death_test_style = "threadsafe";
        #else
            /* nothing */
        #endif
    }

    void SetGlobalVariable(int argc, char** argv) dNOEXCEPT;

    static inline int run(int argc, char** argv)
    {
        ::testing::PrepareEnvironment();
        ::testing::InitGoogleTestFramework(argc, argv);
        ::testing::SetGlobalVariable(argc, argv);
        return ::RUN_ALL_TESTS();
    }

} // namespace testing

//==============================================================================
//==============================================================================
#endif // !dGMAIN_USED_
