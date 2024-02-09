#pragma once

#include "Json.hpp"

#include <compare>

class JsonFile;

class String: public Json{
private:
    std::string value;
public:
    String(const std::string& string, size_t& i);
    String(JsonFile& file);
    ~String(){}
    bool operator==(const String& other) const;
    bool operator<(const String& other) const;
    std::string to_string() const override;
    const std::string& get_value() const;
    std::ostream& print(std::ostream& out) const override;
};
