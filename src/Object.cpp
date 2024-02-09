#include "Object.hpp"

#include <iostream>
#include <sstream>

#include "utility.hpp"
#include "JsonException.hpp"
#include "JsonFile.hpp"

Object::Object(const std::string& string, size_t& i){
    skip_whitespace(string, i);
    if(string[i] != '{'){
        throw JsonException("Not an object");
    }
    i++;
    skip_whitespace(string, i);
    while(i < string.length() && string[i] != '}'){
        if(string[i] != '"'){
            throw JsonException("Missing '\"' in Object");
        }
        String key(string, i);
        skip_whitespace(string, i);
        if(string[i] != ':'){
            throw JsonException("Missing seperator in object");
        }
        i++;
        values.emplace(key, parse_json(string, i));
        skip_whitespace(string, i);
        if(string[i] != ',' && string[i] != '}'){
            std::cout << string[i] << '\n';
            throw JsonException("Invalid seperator in object");
        }else if(string[i] == '}'){
            i++;
            break;
        }
        i++;
        skip_whitespace(string, i);
    }
}

Object::Object(JsonFile& file){
    skip_whitespace(file);
    if(file.get() != '{'){
        std::stringstream error;
        error << "Not an object (" << file.get_row() << ", " << file.get_column() << ")\n";
        throw JsonException(error.str());
    }
    file.next();
    skip_whitespace(file);
    while(file.get() != '}'){
        if(file.get() != '"'){
            std::stringstream error;
            error << "Missing '\"' in object (" << file.get_row() << ", " << file.get_column() << ")\n";
            throw JsonException(error.str());
        }
        String key(file);
        skip_whitespace(file);
        if(file.get() != ':'){
            std::stringstream error;
            error << "Missing seperator in object (" << file.get_row() << ", " << file.get_column() << ")\n";
            throw JsonException(error.str());
        }
        file.next();
        values.emplace(key, parse_json(file));
        skip_whitespace(file);
        if(file.get() != ',' && file.get() != '}'){
            std::stringstream error;
            error << "Invalid seperator in object (" << file.get_row() << ", " << file.get_column() << ")\n";
            throw JsonException(error.str());
        }else if(file.get() == '}'){
            break;
        }
        file.next();
        skip_whitespace(file);
    }
    if(file.has_next()){
        file.next();
    }
}

std::string Object::to_string() const{
    std::string result = "{";
    bool first = true;
    for(const std::pair<const String, std::shared_ptr<Json>>& item : values){
        if(first){
            result += item.first.to_string() + ": " + item.second->to_string();
            first = false;
        }else{
            result = result + ", " + item.first.to_string() + ": " + item.second->to_string();
        }
    }
    result += '}';
    return result;
}


const Json& Object::get(const String& key) const{
    return *values.at(key);
}

size_t Object::size() const{
    return values.size();
}

std::ostream& Object::print(std::ostream& out) const{
    out << "{";
    bool first = true;
    for(const std::pair<const String, std::shared_ptr<Json>>& item : values){
        if(first){
            item.first.print(out) << ": " << *item.second;
            first = false;
        }else{
            out << ", ";
            item.first.print(out) << ": " << *item.second;
        }
    }
    return out << '}';
}
