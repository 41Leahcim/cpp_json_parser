#include "JsonFile.hpp"

#include <string.h>
#include <iostream>

#include "JsonException.hpp"

JsonFile::JsonFile(const char *path): column(0), row(1){
    file = std::ifstream(path);
    if(!std::getline(file, line)){
        throw JsonException("Failed to read first line from file");
    }
    next_line_valid = static_cast<bool>(std::getline(file, next_line));
}

char JsonFile::get() const{
    return line[column];
}

size_t JsonFile::get_row() const{
    return row;
}

size_t JsonFile::get_column() const{
    return column + 1;
}

void JsonFile::next(){
    column++;
    if(column < line.length()){
        return;
    }
    if(!next_line_valid){
        throw JsonException("Failed to read line from file");
    }
    line = next_line;
    next_line_valid = static_cast<bool>(std::getline(file, next_line));
    column = 0;
    row++;
}

bool JsonFile::has_next() const{
    return column < line.length() - 1 || next_line_valid;
}

char JsonFile::get_next(){
    next();
    return get();
}

bool JsonFile::operator==(const char *string){
    size_t length = strlen(string);
    if(line.substr(column, length) == string){
        column += length;
        return true;
    }
    return false;
}

bool JsonFile::operator!=(const char *string){
    return !(*this == string);
}
