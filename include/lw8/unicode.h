#ifndef _LW8_UNICODE
#define _LW8_UNICODE

#include <cstdint>

namespace lw8
{
    static const uint32_t ONE_BYTE_MASK = 0x80;
    static const uint32_t ONE_BYTE_BITS = 0;
    static const uint32_t TWO_BYTES_MASK = 0xE0;
    static const uint32_t TWO_BYTES_BITS = 0xC0;
    static const uint32_t THREE_BYTES_MASK = 0xF0;
    static const uint32_t THREE_BYTES_BITS = 0xE0;
    static const uint32_t FOUR_BYTES_MASK = 0xF8;
    static const uint32_t FOUR_BYTES_BITS = 0xF0;
    static const uint32_t CONTINUATION_MASK = 0xC0;
    static const uint32_t CONTINUATION_BITS = 0x80;
};

#endif