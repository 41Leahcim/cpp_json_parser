#pragma once

#include "Json.hpp"

#include <memory>
#include <vector>

class JsonFile;

class Array: public Json{
private:
    std::vector<std::shared_ptr<Json>> values;
public:
    Array(const std::string& string, size_t& i);
    Array(JsonFile& file);
    ~Array(){}
    std::string to_string() const override;
    const Json& get(const size_t index) const;
    size_t size() const;
    std::ostream& print(std::ostream& out) const override;
};
