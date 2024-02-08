#pragma once

#include <string>

void skip_whitespace(const std::string& string, size_t& i){
    while(i < string.length() && (string[i] == ' ' || string[i] == '\t' || string[i] == '\n')){
        i++;
    }
}
