#include "Number.hpp"

#include <iostream>
#include <sstream>

#include "JsonException.hpp"
#include "JsonFile.hpp"

constexpr bool is_digit(const char c){
    return c >= '0' && c <= '9';
}

Number::Number(const std::string& string, size_t& i){
    const size_t start = i;
    bool dot_found = false;
    while(
        is_digit(string[i]) ||
        (string[i] == '-' && i - start == 0) ||
        (string[i] == '.' && !dot_found)){
        dot_found = dot_found || string[i] == '.';
        i++;
    }
    if(i == start){
        throw JsonException("Not a number");
    }
    std::string number_string = string.substr(start, i - start);
    value = std::stof(number_string);
}

Number::Number(JsonFile& file){
    bool dot_found = false;
    std::string number_string = "";
    while(is_digit(file.get()) ||
        (file.get() == '-' && number_string.empty()) ||
        (file.get() == '.' && !dot_found)){
        dot_found = dot_found || file.get() == '.';
        number_string += file.get();
        file.next();
        std::cout << number_string << '\n';
    }
    std::cout << file.get() << ' ' << file.has_next() << '\n';
    if(is_digit(file.get())){
        number_string += file.get();
    }
    if(number_string.empty()){
        std::stringstream error;
        error << "Not a number (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
    value = std::stof(number_string);
}

std::string Number::to_string() const{
    return std::to_string(value);
}

double Number::get_value() const{
    return value;
}

std::ostream& Number::print(std::ostream& out) const{
    return out << value;
}
