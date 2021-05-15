// [2021y-02m-23d] Idrisov Denis R.
// [2021y-02m-24d] Idrisov Denis R.
// [2021y-05m-15d][00:42:36] Idrisov Denis R.
#if defined(_MSC_VER) && _MSC_VER <= 1600
// pragma message("Visual Studio 2010 or older")

//==============================================================================
//=== windows ==================================================================

#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0502
#endif

#ifdef _WIN32
    #define NOMINMAX 1
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h> 
#else
     #error: only windows supported
#endif

//==============================================================================
//=== assert ===================================================================

#ifdef NDEBUG
    #define dASSERT(...)
#else
    #include <cassert>
    #define dASSERT(...) assert(__VA_ARGS__)
#endif

//==============================================================================
//==============================================================================

#include <mygtest/synch.hpp>
#include <new>

//==============================================================================
//==============================================================================

namespace
{
    ::CRITICAL_SECTION* cast(char* storage)
    {
        dASSERT(storage);
        return reinterpret_cast<::CRITICAL_SECTION*>(storage);
    }

    template<bool> 
        struct static_assert_;

    template<> 
        struct static_assert_<true> {};

    #define dSTATIC_ASSERT(expr, msg) \
    {                                 \
        static_assert_<(expr)> msg;   \
        (void) msg;                   \
    } 

    void dummy() dNOEXCEPT
    {
        dSTATIC_ASSERT(
            sizeof(::CRITICAL_SECTION) <= 40,
            INVALID_SIZE_OF_STORAGE
        );
    }

} // namespace

//==============================================================================
//==============================================================================

namespace mygtest
{
    synch::synch() dNOEXCEPT
    {
        new (this->m_storage.arr) ::CRITICAL_SECTION;
        ::CRITICAL_SECTION* ptr = cast(this->m_storage.arr);
        dASSERT(ptr);

        ZeroMemory(ptr, sizeof(::CRITICAL_SECTION)); 
        ::InitializeCriticalSection(ptr);
    }

    synch::~synch() 
    {
        ::CRITICAL_SECTION* ptr = cast(this->m_storage.arr);
        dASSERT(ptr);
        ::DeleteCriticalSection(ptr);
    }

    void synch::lock() dNOEXCEPT
    {
        ::CRITICAL_SECTION* ptr = cast(this->m_storage.arr);
        dASSERT(ptr);
        ::EnterCriticalSection(ptr);
    }

    void synch::unlock() dNOEXCEPT 
    {
        ::CRITICAL_SECTION* ptr = cast(this->m_storage.arr);
        dASSERT(ptr);
        ::LeaveCriticalSection(ptr);
    }

} // namespace mygtest

//==============================================================================
//==============================================================================
#endif // !(defined(_MSC_VER) && _MSC_VER <= 1600)