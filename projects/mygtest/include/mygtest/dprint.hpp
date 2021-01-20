
#pragma once
#ifndef dPRINT_USED_
#define dPRINT_USED_ 1

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
#endif // !dPRINT_USED_
