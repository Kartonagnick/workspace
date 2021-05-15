// [2020y-12m-05d] Idrisov Denis R.
// [2021y-01m-20d] Idrisov Denis R.
// [2021y-05m-15d][00:42:36] Idrisov Denis R.
#pragma once
#ifndef dMYGTEST_REG10_USED_ 
#define dMYGTEST_REG10_USED_ 102

//==============================================================================
//=== dREGISTER_UNIT_TEST ======================================================
#define dGTEST_IN  ::testing::internal
#define dRESOLVER  dGTEST_IN::SuiteApiResolver<::testing::Test>

#define dREGISTER_UNIT_TEST(Class, TestName, SubtestName)      \
    struct Class : public ::testing::Test                      \
    {                                                          \
        Class() {}                                             \
    private:                                                   \
        virtual void TestBody();                               \
        static ::testing::TestInfo* const test_info_;          \
        dNOCOPYABLE(Class);                                    \
    };                                                         \
    ::testing::TestInfo* const Class::test_info_ =             \
    ::testing::internal::MakeAndRegisterTestInfo(              \
        #TestName,                                             \
        #SubtestName,                                          \
        nullptr,                                               \
        nullptr,                                               \
        dGTEST_IN::CodeLocation(__FILE__, __LINE__),           \
        dGTEST_IN::GetTestTypeId(),                            \
        dRESOLVER::GetSetUpCaseOrSuite(__FILE__, __LINE__),    \
        dRESOLVER::GetTearDownCaseOrSuite(__FILE__, __LINE__), \
        new dGTEST_IN::TestFactoryImpl<Class>                  \
    );                                                         \
    void Class::TestBody()

#define dREGISTER_DISABLED_UNIT_TEST(Class, TestName, SubtestName) \
    struct Class         \
    {                    \
        void TestBody(); \
    };                   \
    void Class::TestBody()

    #if 0
    // example:
    dREGISTER_UNIT_TEST(SampleTest_Method, tools/ololo/SampleTest, Method)
    {
        std::cout << "ok\n";
        auto lambda = []{ assert(false); };
        ASSERT_DEATH(lambda(), ".*");
    }
    #endif

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_REG10_USED_