#include <cstring>
#include <lw8/slice.h>

lw8::Utf8::Utf8(const char *data)
{
    this->data = (uint8_t *)data;
    this->length = strlen(data);
}

lw8::Utf8::Utf8(const char *data, size_t length)
{
    this->data = (uint8_t *)data;
    this->length = length;
}
