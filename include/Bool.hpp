#pragma once

#include "Json.hpp"

class JsonFile;

class Bool: public Json{
private:
    bool value;
public:
    Bool(const std::string& string, size_t& i);
    Bool(JsonFile& file);
    ~Bool(){}
    std::string to_string() const override;
    bool get_value() const;
    std::ostream& print(std::ostream& out) const override;
};
