#include "Bool.hpp"

#include <sstream>

#include "JsonException.hpp"
#include "JsonFile.hpp"

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

Bool::Bool(JsonFile& file){
    if(file == "true"){
        value = true;
    }else if(file == "false"){
        value = false;
    }else{
        std::stringstream error;
        error << "Not a boolean (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
}

std::string Bool::to_string() const{
    return value? "true" : "false";
}

bool Bool::get_value() const{
    return value;
}

std::ostream& Bool::print(std::ostream& out) const{
    return out << (value? "true" : "false");
}
