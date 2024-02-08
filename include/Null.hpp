#pragma once

#include "Json.hpp"

class Null : public Json{
public:
    Null(const std::string& string, size_t& i);
    ~Null(){}
    std::string to_string() const override;
};
