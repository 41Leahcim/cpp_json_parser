#pragma once

#include "Json.hpp"

#include <map>
#include <memory>

#include "String.hpp"

class JsonFile;

class Object : public Json{
private:
    std::map<String, std::shared_ptr<Json>> values;
public:
    Object(const std::string& string, size_t& i);
    Object(JsonFile& file);
    ~Object(){}
    std::string to_string() const override;
    const Json& get(const String& key) const;
    size_t size() const;
    std::ostream& print(std::ostream& out) const override;
};
