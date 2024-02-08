#include "Bool.hpp"

#include "JsonException.hpp"

Bool::Bool(const std::string& string, size_t& i){
    if(string.substr(i, 4) == "true"){
        value = true;
        i += 4;
    }else if(string.substr(i, 5) == "false"){
        value = false;
        i += 5;
    }else{
        throw JsonException("Not a boolean");
    }
}

std::string Bool::to_string() const{
    if(value){
        return "true";
    }else{
        return "false";
    }
}

bool Bool::get_value() const{
    return value;
}
