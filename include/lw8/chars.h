#ifndef _LW8_CHARS
#define _LW8_CHARS

#include <lw8/codepoint.h>
#include <lw8/slice.h>

namespace lw8
{
    /// @brief An iterator over the codepoints of a UTF-8 string.
    struct Chars
    {
        /// @brief The remaining values in the characters.
        Utf8 *source;

        /// @brief The current index of the iterator.
        size_t index;

        /// @brief Creates an iterator over the codepoints of the provided string.
        /// @param source The string to iterate over.
        Chars(Utf8 *source);

        /// @returns The next codepoint in the string.
        ///
        /// If there are no more codepoints, returns 0.
        Codepoint next();

        /// @returns `true` if there are no more codepoints in the string.
        bool end();
    };
};

#endif