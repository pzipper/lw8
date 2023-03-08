#include <lw8/chars.h>

lw8::Chars::Chars(Utf8 *source)
{
    this->source = source;
    this->index = 0;
}

lw8::Codepoint lw8::Chars::next()
{
    if (this->index >= this->source->length)
    {
        return Codepoint((char32_t)0);
    }

    lw8::Codepoint codepoint = lw8::Codepoint::from_utf8(this->source->data + this->index);
    this->index += codepoint.utf8_len();

    return codepoint;
}

bool lw8::Chars::end()
{
    return this->index >= this->source->length;
}