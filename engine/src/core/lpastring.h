#pragma once

#include "defines.h"

// Returns the length of the given string.
LPAAPI u64 string_length(const char* str);

LPAAPI char* string_duplicate(const char* str);

// Case-sensitive string comparison. True if the same, false otherwise.
LPAAPI b8 strings_equal(const char* str0, const char* str1);