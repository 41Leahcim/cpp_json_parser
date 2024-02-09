#include "String.hpp"

#include <sstream>

#include "JsonException.hpp"
#include "JsonFile.hpp"

String::String(const std::string& string, size_t& i){
    const size_t start = i;
    if(string[i] != '"'){
        throw JsonException("Not a string");
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

String::String(JsonFile& file){
    value = "";
    if(file.get() != '"'){
        std::stringstream error;
        error << "Not a string (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
    file.next();
    bool escaped = false;
    while((file.get() != '"' || escaped) && file.has_next()){
        if(file.get() == '\\'){
            escaped = !escaped;
        }else{
            escaped = false;
        }
        value += file.get();
        file.next();
    }
    if(file.get() != '"' || escaped){
        throw JsonException("Unexpected End Of File in String");
    }
    file.next();
}

bool String::operator==(const String& other) const{
    return value == other.get_value();
}

bool String::operator<(const String& other) const{
    return value < other.get_value();
}

std::string String::to_string() const{
    std::string text = "\"";
    text += value + "\"";
    return text;
}

const std::string& String::get_value() const{
    return value;
}

std::ostream& String::print(std::ostream& out) const{
    return out << '"' << value << '"';
}
