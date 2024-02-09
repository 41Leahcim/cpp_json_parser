#include "JsonException.hpp"

JsonException::JsonException(std::string text) : message(text){}

const char* JsonException::what() const noexcept{
    return message.c_str();
}
