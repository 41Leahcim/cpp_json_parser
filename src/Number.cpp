#include "Number.hpp"

#include <string.h>

#include "JsonException.hpp"

Number::Number(const std::string& string, size_t& i){
    const size_t start = i;
    while(
        (string[i] >= '0' && string[i] <= '9') ||
        (string[i] == '-' && i - start == 0) ||
        string[i] == '.'){
        i++;
    }
    if(i == start){
        throw JsonException("Not a number");
    }
    std::string number_string = string.substr(start, i - start);
    value = std::stof(number_string);
}

std::string Number::to_string() const{
    return std::to_string(value);
}

double Number::get_value() const{
    return value;
}
