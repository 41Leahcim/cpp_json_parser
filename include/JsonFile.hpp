#pragma once

#include <fstream>

class JsonFile{
private:
    std::string line;
    std::string next_line;
    bool next_line_valid;
    size_t column;
    size_t row;
    std::ifstream file;
public:
    JsonFile(const char *path);
    char get() const;
    size_t get_row() const;
    size_t get_column() const;
    char get_next();
    void next();
    bool has_next() const;
    bool operator==(const char *string);
    bool operator!=(const char *string);
};
