
// [2020y-12m-05d] Idrisov Denis R.
// [2021y-01m-20d] Idrisov Denis R.

#pragma once
#ifndef dMYGTEST_PRINT_USED_
#define dMYGTEST_PRINT_USED_ 102

#if defined(_MSC_VER) && _MSC_VER < 1700
    // mutex is available for studio 2012 or newer
    #error need msvc2012 (or newer)
#endif

//==============================================================================
//=== [dprint] =================================================================

#include <iostream>
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

//==============================================================================
//==============================================================================
#endif // !dMYGTEST_PRINT_USED_
