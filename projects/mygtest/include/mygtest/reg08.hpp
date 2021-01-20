
#pragma once
#ifndef dMYGTEST_REG8_USED_ 
#define dMYGTEST_REG8_USED_

//==============================================================================
//=== dREGISTER_UNIT_TEST ======================================================
#define dGTEST_IN  ::testing::internal

#define dREGISTER_UNIT_TEST(Class, TestName, SubtestName) \
    struct Class : public ::testing::Test                 \
    {                                                     \
        Class() {}                                        \
        void Public_(){}                                  \
    private:                                              \
        virtual void TestBody();                          \
        static ::testing::TestInfo* const test_info_;     \
        dNOCOPYABLE(Class);                               \
    };                                                    \
    ::testing::TestInfo* const Class::test_info_ =        \
      ::testing::internal::MakeAndRegisterTestInfo(       \
          #TestName,                                      \
          #SubtestName,                                   \
          static_cast<const char*>(0),                    \
          static_cast<const char*>(0),                    \
          dGTEST_IN::CodeLocation(__FILE__, __LINE__),    \
          (dGTEST_IN::GetTestTypeId),                     \
          testing::Test::SetUpTestCase,                   \
          testing::Test::TearDownTestCase,                \
          new dGTEST_IN::TestFactoryImpl<Class>           \
    );                                                    \
    void Class::TestBody()


#define dREGISTER_DISABLED_UNIT_TEST(Class, TestName, SubtestName) \
    struct Class : public ::testing::Test             \
    {                                                 \
        Class() {}                                    \
        void Public_(){}                              \
    private:                                          \
        virtual void TestBody();                      \
        static ::testing::TestInfo* const test_info_; \
        dNOCOPYABLE(Class);                           \
    };                                                \
    void Class::TestBody()

    #if 0
    // example:
    dREGISTER_UNIT_TEST(SampleTest_Method, tools\\ololo\\SampleTest, Method)
    {
        std::cout << "ok\n";
        auto lambda = []{ assert(false); };
        ASSERT_DEATH(lambda(), ".*");
    }
    #endif

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_REG8_USED_