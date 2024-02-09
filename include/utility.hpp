#pragma once

#include <string>
#include <memory>

class Json;
class JsonFile;

void skip_whitespace(const std::string& string, size_t& i);
void skip_whitespace(JsonFile& file);

std::shared_ptr<Json> parse_json(const std::string& string, size_t& i); 
std::shared_ptr<Json> parse_json(JsonFile& file); 
