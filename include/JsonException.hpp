#pragma once

#include <exception>

class JsonException: public std::exception{
private:
    const char *message;
public:
    JsonException(const char *message);
    ~JsonException(){}
    const char* what() const noexcept override;
};
