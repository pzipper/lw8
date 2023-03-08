#include <lw8/codepoint.h>
#include <lw8/unicode.h>

inline size_t utf8_codepoint_size(const uint8_t byte)
{
    if ((byte & lw8::ONE_BYTE_MASK) == lw8::ONE_BYTE_BITS)
    {
        return 1;
    }

    if ((byte & lw8::TWO_BYTES_MASK) == lw8::TWO_BYTES_BITS)
    {
        return 2;
    }

    if ((byte & lw8::THREE_BYTES_MASK) == lw8::THREE_BYTES_BITS)
    {
        return 3;
    }

    if ((byte & lw8::FOUR_BYTES_MASK) == lw8::FOUR_BYTES_BITS)
    {
        return 4;
    }

    return 0;
}

lw8::Codepoint::Codepoint(uint8_t value)
{
    this->value = (char32_t)value | lw8::ONE_BYTE_BITS;
}

lw8::Codepoint::Codepoint(char32_t value)
{
    this->value = value;
}

lw8::Codepoint lw8::Codepoint::from_utf8(const uint8_t *buffer)
{
    lw8::Codepoint codepoint = lw8::Codepoint(*buffer);

    size_t size = utf8_codepoint_size(*buffer);

    switch (size)
    {
    case 1:
        codepoint.value = ((uint32_t)buffer[0] & ~ONE_BYTE_MASK);
        break;
    case 2:
        codepoint.value =
            ((uint32_t)buffer[0] & ~TWO_BYTES_MASK) << 6 |
            ((uint32_t)buffer[1] & ~CONTINUATION_MASK);
        break;
    case 3:
        codepoint.value =
            ((uint32_t)buffer[0] & ~THREE_BYTES_MASK) << 12 |
            ((uint32_t)buffer[1] & ~CONTINUATION_MASK) << 6 |
            ((uint32_t)buffer[2] & ~CONTINUATION_MASK);

        break;
    case 4:
        codepoint.value =
            ((uint32_t)buffer[0] & ~FOUR_BYTES_MASK) << 18 |
            ((uint32_t)buffer[1] & ~CONTINUATION_MASK) << 12 |
            ((uint32_t)buffer[2] & ~CONTINUATION_MASK) << 6 |
            ((uint32_t)buffer[3] & ~CONTINUATION_MASK);
        break;
    default:
        // this should never happen, since we check validity of the string
        return Codepoint((char32_t)0);
    }

    return codepoint;
}

size_t lw8::Codepoint::utf8_len()
{
    if (this->value < 0x80)
        return 1;
    else if (this->value < 0x800)
        return 2;
    else if (this->value < 0x10000)
        return 3;

    return 4;
}

void lw8::Codepoint::to_utf8(uint8_t *buffer)
{
    if (this->value < 0x80)
        buffer[0] = this->value;
    else if (this->value < 0x800)
    { // 00000yyy yyxxxxxx
        buffer[0] = (0b11000000 | (this->value >> 6));
        buffer[1] = (0b10000000 | (this->value & 0x3f));
    }
    else if (this->value < 0x10000)
    {
        buffer[0] = (0b11100000 | (this->value >> 12));
        buffer[1] = (0b10000000 | ((this->value >> 6) & 0x3f));
        buffer[2] = (0b10000000 | (this->value & 0x3f));
    }
    else if (this->value < 0x200000)
    {
        buffer[0] = (0b11110000 | (this->value >> 18));
        buffer[1] = (0b10000000 | ((this->value >> 12) & 0x3f));
        buffer[2] = (0b10000000 | ((this->value >> 6) & 0x3f));
        buffer[3] = (0b10000000 | (this->value & 0x3f));
    }
}