#pragma once

#include "Json.hpp"

class String: public Json{
private:
    std::string value;
public:
    String(const std::string& string, size_t& i);
    ~String(){}
    std::string to_string() const override;
    const std::string& get_value() const;
};
