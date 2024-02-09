#pragma once

#include <string>
#include <ostream>

class Json{
public:
    virtual ~Json(){}
    virtual std::string to_string() const = 0;
    virtual std::ostream& print(std::ostream& out) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Json& json);
