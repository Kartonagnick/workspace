// [2020y-12m-05d] Idrisov Denis R.
// [2021y-01m-20d] Idrisov Denis R.
// [2021y-05m-15d][00:42:36] Idrisov Denis R.
#pragma once
#ifndef dMYGTEST_PRINT_USED_
#define dMYGTEST_PRINT_USED_ 102

//==============================================================================
//=== [dprint] =================================================================

#include <iostream>

#ifdef dHAS_ATOMIC

#include <mutex>

#define dprint(out_message_operation)         \
{                                             \
    auto& gp_mutex                            \
        = glob_dprint_mutex_::get();          \
    ::std::lock_guard<::std::recursive_mutex> \
        dprint_lock(gp_mutex);                \
    out_message_operation;                    \
} void()

struct glob_dprint_mutex_
{
    static ::std::recursive_mutex& get()
    {
        static ::std::recursive_mutex mut;
        return mut;
    }
};

#else

#include <mygtest/synch.hpp>

#define dprint(out_message_operation) \
{                                     \
    ::mygtest::synch& gp_mutex        \
        = glob_dprint_mutex_::get();  \
    ::mygtest::synch_guard            \
        dprint_lock(gp_mutex);        \
    out_message_operation;            \
} void()

struct glob_dprint_mutex_
{
    static ::mygtest::synch& get()
    {
        static ::mygtest::synch mut;
        return mut;
    }
};

#endif // !dHAS_ATOMIC

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_PRINT_USED_
