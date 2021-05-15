// [2021y-02m-21d] Idrisov Denis R.
// [2021y-02m-23d] Idrisov Denis R.
// [2021y-02m-24d] Idrisov Denis R.
// [2021y-05m-15d][00:42:36] Idrisov Denis R.
#pragma once
#ifndef dMYGTEST_SYNCH_USED_ 
#define dMYGTEST_SYNCH_USED_ 102
//==============================================================================
//==============================================================================

#include <mygtest/features.hpp>

#ifdef dHAS_ATOMIC

#include <mutex>

namespace mygtest
{
    class synch
    {
        ::std::recursive_mutex m_mutex;
    public:
        dNOCOPYABLE(synch);

        synch() dNOEXCEPT : m_mutex() {}

        void lock() dNOEXCEPT
        {
            this->m_mutex.lock();
        }
        void unlock() dNOEXCEPT
        {
            this->m_mutex.unlock();
        }
    };

} // namespace mygtest

#else

// --- old compiler
namespace mygtest
{
    class synch
    {
        typedef char arr_t[40];
        union storage
        {
            void* ptr;
            arr_t arr;
        };
        storage m_storage;
    public:
        dNOCOPYABLE(synch);

        ~synch();
        synch() dNOEXCEPT;

        void lock()   dNOEXCEPT;
        void unlock() dNOEXCEPT;
    };

} // namespace mygtest

#endif

//==============================================================================
//==============================================================================

namespace mygtest
{
    class synch_guard
    {
        synch& ref;
    public:
        dNOCOPYABLE(synch_guard);

        synch_guard(synch& s) dNOEXCEPT 
            : ref(s)
        {
            ref.lock();
        }
        ~synch_guard() dNOEXCEPT
        {
            ref.unlock();
        }
    };

} // namespace mygtest

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_SYNCH_USED_