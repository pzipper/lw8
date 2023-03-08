#ifndef _LW8_CODEPOINT
#define _LW8_CODEPOINT

#include <cstdint>

namespace lw8
{
    /// @brief A Unicode code point.
    struct Codepoint
    {
        /// @brief The code point's value.
        char32_t value;

        /// @brief Converts an ASCII character to a Codepoint.
        /// @param value The ASCII character.
        ///
        /// Assumes that the provided character is a valid ASCII character.
        Codepoint(uint8_t value);

        /// @brief Creates a Unicode code point from the provided raw value.
        /// @param value The raw value of the code point.
        Codepoint(char32_t value);

        /// @brief Parses the single UTF-8 codepoint at the provided pointer.
        /// @param buffer The pointer to the UTF-8 codepoint.
        /// @returns The parsed Codepoint.
        ///
        /// Assumes that the provided pointer is a valid UTF-8 codepoint.
        static Codepoint from_utf8(const uint8_t *buffer);

        /// @returns The number of bytes it takes to encode this Codepoint in a UTF-8 string.
        size_t utf8_len();

        /// @brief Encodes this Codepoint into a UTF-8 string.
        /// @param buffer The buffer to write the UTF-8 codepoint to.
        ///
        /// The provided buffer must have enough space to store the codepoint.  Use `utf8_len` to
        /// calculate the required size.
        void to_utf8(uint8_t *buffer);
    };
};

#endif