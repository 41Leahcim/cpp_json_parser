#include "String.hpp"

#include "JsonException.hpp"

String::String(const std::string& string, size_t& i){
    const size_t start = i;
    if(string[i] != '"'){
        throw JsonException("Missing '\"' at the start of the string");
    }
    i++;
    bool escaped = false;
    while(string[i] != '"' || escaped){
        if(string[i++] == '\\'){
            escaped = !escaped;
        }else{
            escaped = false;
        }
    }
    value = string.substr(start + 1, i - start - 1);
    i++;
}

std::string String::to_string() const{
    std::string text = "\"";
    text += value + "\"";
    return text;
}

const std::string& String::get_value() const{
    return value;
}
