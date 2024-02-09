#pragma once

#include "Json.hpp"

class JsonFile;

class Null : public Json{
public:
    Null(const std::string& string, size_t& i);
    Null(JsonFile& file);
    ~Null(){}
    std::string to_string() const override;
    std::ostream& print(std::ostream& out) const override;
};
