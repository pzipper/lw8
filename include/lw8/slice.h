#ifndef _LW8_STRING
#define _LW8_STRING

#include <cstdint>

namespace lw8
{
    /// @brief A slice of UTF-8 characters.
    ///
    /// It simply acts as a wrapper around a pointer, it doesn't manage the memory of the string.
    struct Utf8
    {
        /// @brief A pointer to the first character in the slice.
        const uint8_t *data;

        /// @brief The number of bytes in the slice.
        size_t length;

        /// @brief Constructs a slice from a null-terminated string.
        /// @param data The raw string data.
        Utf8(const char *data);

        /// @brief Constructs a slice from its raw parts.
        /// @param data The raw string data.
        /// @param length The length of the string, in bytes.
        Utf8(const char *data, size_t length);
    };
};

#endif