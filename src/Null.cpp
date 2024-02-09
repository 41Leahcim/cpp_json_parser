#include "Null.hpp"

#include <sstream>

#include "JsonException.hpp"
#include "JsonFile.hpp"

Null::Null(const std::string& string, size_t& i){
    if(string.substr(i, 4) != "null"){
        throw JsonException("Not null");
    }
    i += 4;
}

Null::Null(JsonFile& file){
    if(file != "null"){
        std::stringstream error;
        error << "Not null (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
}

std::string Null::to_string() const{
    return "null";
}

std::ostream& Null::print(std::ostream& out) const{
    return out << "null";
}
