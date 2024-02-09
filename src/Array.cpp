#include "Array.hpp"

#include <iostream>
#include <sstream>

#include "JsonException.hpp"
#include "utility.hpp"
#include "JsonFile.hpp"

Array::Array(const std::string& string, size_t& i){
    skip_whitespace(string, i);
    if(string[i] != '['){
        throw JsonException("Not an array");
    }
    i++;
    skip_whitespace(string, i);
    while(i < string.length() && string[i] != ']'){
        values.push_back(parse_json(string, i));
        skip_whitespace(string, i);
        if(string[i] != ',' && string[i] != ']'){
            throw JsonException("Invalid seperator in array");
        }else if(string[i] == ']'){
            i++;
            break;
        }
        i++;
        skip_whitespace(string, i);
    }
}

Array::Array(JsonFile& file){
    skip_whitespace(file);
    if(file.get() != '['){
        std::stringstream error;
        error << "Not an array (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
    file.next();
    skip_whitespace(file);
    while(file.get() != ']'){
        values.push_back(parse_json(file));
        skip_whitespace(file);
        if(file.get() != ',' && file.get() != ']'){
            std::stringstream error;
            error << "Invalid seperator in array (" << file.get_row() << ", " << file.get_column() << ")\n";
            throw JsonException(error.str());
        }else if(file.get() == ']'){
            if(file.has_next()){
                file.next();
            }
            break;
        }
        file.next();
        skip_whitespace(file);
    }
}

std::string Array::to_string() const{
    std::string result = "[";
    if(!values.empty()){
        result += values[0]->to_string();
        for(size_t i = 1;i < values.size();i++){
            result = result + ", " + values[i]->to_string();
        }
    }
    return result + "]";
}

const Json& Array::get(const size_t index) const{
    return *values.at(index);
}

size_t Array::size() const{
    return values.size();
}

std::ostream& Array::print(std::ostream& out) const{
    out << "[";
    if(!values.empty()){
        out << *values[0];
        for(size_t i = 1;i < values.size();i++){
            out << ", " << *values[i];
        }
    }
    return out << "]";
}
