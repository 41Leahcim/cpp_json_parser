#pragma once

#include "Json.hpp"

class Bool: public Json{
private:
    bool value;
public:
    Bool(const std::string& string, size_t& i);
    ~Bool(){}
    std::string to_string() const override;
    bool get_value() const;
};
