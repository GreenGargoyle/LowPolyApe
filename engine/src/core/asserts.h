#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line.
#define LPAASSERTIONS_ENABLED

#ifdef LPAASSERTIONS_ENABLED
// If Visual Studio's compiler.
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

LPAAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);


#define LPAASSERT(expr)                                             \
{                                                                   \
    if (expr) {                                                     \
    } else {                                                        \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);    \
        debugBreak();                                               \
    }                                                               \
}

#define LPAASSERT_MSG(expr, message)                                            \
{                                                                               \
    if (expr) {                                                                 \
    } else {                                                                    \
        report_assertion_failure(#expr, message, __FILE__, __LINE__);           \
        debugBreak();                                                           \
    }                                                                           \
}

#ifdef _DEBUG
#define LPAASSERT_DEBUG(expr)                                       \
{                                                                   \
    if(expr){                                                       \
    } else {                                                        \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);    \
        debugBreak();                                               \
    }                                                               \
}
#else
#define LPAASSERT_DEBUG(expr) // Does nothing.
#endif

#else
#define LPAASSERT(expr) // Does nothing.
#define LPAASSERT_MSG(expr, message) // Does nothing.
#define LPAASSERT_DEBUG(expr) // Does nothing.
#endif