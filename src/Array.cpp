#include "Array.hpp"

#include <iostream>

#include "JsonException.hpp"
#include "utility.hpp"

#include "Array.hpp"
#include "Bool.hpp"
#include "Null.hpp"
#include "Number.hpp"
#include "String.hpp"

Array::Array(const std::string& string, size_t& i){
    skip_whitespace(string, i);
    if(string[i] != '['){
        throw JsonException("Not an array");
    }
    i++;
    while(i < string.length() && string[i] != ']'){
        skip_whitespace(string, i);
        switch(string[i]){
            case '[':
                values.push_back(std::make_shared<Array>(string, i));
                break;
            case 't': case 'f':
                values.push_back(std::make_shared<Bool>(string, i));
                break;
            case 'n':
                values.push_back(std::make_shared<Null>(string, i));
                break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
            case '8': case '9': case '-':
                values.push_back(std::make_shared<Number>(string, i));
                break;
            case '\"':
                values.push_back(std::make_shared<String>(string, i));
                break;
            default:
                std::cout << string[i] << '\n';
                throw JsonException("Invalid value in array");
        }
        skip_whitespace(string, i);
        if(string[i] != ',' && string[i] != ']'){
            throw JsonException("Invalid seperator in array");
        }
        i++;
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
