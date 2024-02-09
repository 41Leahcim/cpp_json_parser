#pragma once

#include <exception>
#include <string>

class JsonException: public std::exception{
private:
    std::string message;
public:
    JsonException(std::string message);
    ~JsonException(){}
    const char* what() const noexcept override;
};
