
#pragma once
#ifndef dGCOMPONENT_USED_
#define dGCOMPONENT_USED_ 1

#if defined(__GNUC__)
    #pragma GCC system_header
#endif

// #include <mygtest/features.hpp>

#undef  TEST_COMPONENT
#undef _TEST_COMPONENT

//==============================================================================
//=== diagnostic`s messages ====================================================

#ifdef STABLE_RELEASE
    #define dDISABLE_DPRINT
#endif

#ifdef dDISABLE_DPRINT
    #define dprint(message) \
        void()
#elif !defined(_MSC_VER) || _MSC_VER >= 1700
    // #pragma message("build for msvc2012 (or newer) or other compiler")
    #include <mygtest/dprint.hpp>
#else
    #define dprint(message) \
        void()
#endif // dDISABLE_DPRINT

//==============================================================================
//==============================================================================

namespace testing
{
	/*
    template<class t>
    dCONSTEXPR_CPP11 void unused(t&&) dNOEXCEPT {}
	*/

} // namespace testing

#ifdef NDEBUG
    // release
    #define ASSERT_DEATH_DEBUG(...) \
        void()

    #define dDEATH_TEST(...) \
        void()
#else
    // debug
    #define ASSERT_DEATH_DEBUG(...) \
        ASSERT_DEATH(__VA_ARGS__, ".*")

    #define dDEATH_TEST(...) \
        ASSERT_DEATH((void)(__VA_ARGS__), ".*")
#endif

#define TEST_COMPONENT(n)   \
    TEST(TEST_CASE_NAME, TEST_NUMBER(n))

#define _TEST_COMPONENT(n)  \
   _TEST(TEST_CASE_NAME, TEST_NUMBER(n))

#define dCLASSNAME(a, b) a##b##_test

#define _TEST(a, b)         \
    struct dCLASSNAME(a, b) \
    {                       \
        void Public_(){}    \
    private:                \
        void TestBody();    \
    };                      \
    void dCLASSNAME(a, b)::TestBody()

//==============================================================================
//==============================================================================

namespace testing
{
    extern bool stress;
    extern bool generate;

} // namespace testing 

//==============================================================================
//==============================================================================

#define SKIP_STRESS_TEST                                \
    if(testing::stress)                                 \
    {                                                   \
        dprint(::std::cout << "skip stress-test...\n"); \
        return;                                         \
    } void() 

#define SKIP_TEST_GENERATOR                                  \
    if(!testing::generate)                                   \
    {                                                        \
        dprint(::std::cout << "skip test`s generator...\n"); \
        return;                                              \
    } void() 

//==============================================================================
//==============================================================================

#endif // !dGCOMPONENT_USED_
