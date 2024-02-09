#include "utility.hpp"

#include <iostream>
#include <sstream>

#include "Array.hpp"
#include "Bool.hpp"
#include "Null.hpp"
#include "Number.hpp"
#include "Object.hpp"
#include "String.hpp"

#include "JsonException.hpp"
#include "JsonFile.hpp"

constexpr bool is_whitespace(const char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void skip_whitespace(const std::string& string, size_t& i){
    while(i < string.length() && is_whitespace(string[i])){
        i++;
    }
}

void skip_whitespace(JsonFile& file){
    while(is_whitespace(file.get()) && file.has_next()){
        file.next();
    }
}

std::shared_ptr<Json> parse_json(const std::string& string, size_t& i){
    skip_whitespace(string, i);
    switch(string[i]){
        case '[':
            return std::make_shared<Array>(string, i);
        case '{':
            return std::make_shared<Object>(string, i);
        case 't': case 'f':
            return std::make_shared<Bool>(string, i);
        case 'n':
            return std::make_shared<Null>(string, i);
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
        case '8': case '9': case '-':
            return std::make_shared<Number>(string, i);
        case '\"':
            return std::make_shared<String>(string, i);
        default:
            std::cout << string[i] << '\n';
            throw JsonException("Invalid Json value");
    }
}

std::shared_ptr<Json> parse_json(JsonFile& file){
    skip_whitespace(file);
    switch(file.get()){
        case '[':
            return std::make_shared<Array>(file);
        case '{':
            return std::make_shared<Object>(file);
        case 't': case 'f':
            return std::make_shared<Bool>(file);
        case 'n':
            return std::make_shared<Null>(file);
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
        case '8': case '9': case '-':
            return std::make_shared<Number>(file);
        case '\"':
            return std::make_shared<String>(file);
        default:
        std::stringstream error;
        error << "Not a Json object (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
}
