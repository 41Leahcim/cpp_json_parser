#pragma once

#include <string>

class Json{
public:
    virtual ~Json(){}
    virtual std::string to_string() const = 0;
};
