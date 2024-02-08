#include "JsonException.hpp"

JsonException::JsonException(const char *text) : message(text){}

const char* JsonException::what() const noexcept{
    return message;
}
