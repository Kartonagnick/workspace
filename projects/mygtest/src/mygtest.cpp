
#include <cassert>
#include <cstring>

//==============================================================================
//==============================================================================

#if defined(__clang__)
    #if __has_feature(cxx_noexcept)
        #define dHAS_NOEXCEPT 1
    #endif
#endif

#if defined(__GXX_EXPERIMENTAL_CXX0X__) && __GNUC__ * 10 + __GNUC_MINOR__ >= 46
    #define dHAS_NOEXCEPT 1
#endif

#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023026
    #define dHAS_NOEXCEPT 1
#endif
                
#if defined(dHAS_NOEXCEPT)
    #define dNOEXCEPT noexcept
#else
    #define dNOEXCEPT
#endif

//==============================================================================
//==============================================================================

namespace testing
{
    bool stress = false;
    bool generate = false;

    void SetGlobalVariable(int argi, char** argv) dNOEXCEPT
    {
        assert(argv);
        assert(argi >= 0);
        const size_t argc = static_cast<size_t>(argi);

        for(size_t i = 0; i != argc; ++i)
        {
            size_t x = 0;
            const char* const arg = argv[i];

            if(!arg)
                goto next;

            while(arg[x] == ' ' || arg[x] == '-')
                if(arg[++x] == 0)
                    goto next;

            if(::strcmp(arg + x, "stress") == 0)
                ::testing::stress = true;

            if(::strcmp(arg + x, "generate") == 0)
                ::testing::generate = true;
        next:
            void();
        }
    }

} // namespace testing

//==============================================================================
//==============================================================================
