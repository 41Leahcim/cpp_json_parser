#pragma once

#include "Json.hpp"

#include <string_view>

class Number: public Json{
private:
    double value;
public:
    Number(const std::string& value, size_t& i);
    ~Number(){}
    std::string to_string() const override;
    double get_value() const;
};
