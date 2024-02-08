#include "Null.hpp"

#include "JsonException.hpp"

Null::Null(const std::string& string, size_t& i){
    if(string.substr(i, 4) != "null"){
        throw JsonException("Not null");
    }
    i += 4;
}

std::string Null::to_string() const{
    return "null";
}
