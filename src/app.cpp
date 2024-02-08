#include <iostream>
#include <fstream>

#include "Array.hpp"
#include "Bool.hpp"
#include "Null.hpp"
#include "Number.hpp"
#include "String.hpp"

std::string read_file(const char *path){
    std::ifstream file(path);
    std::string line, text;
    while(std::getline(file, line)){
        if(!text.empty()){
            text += '\n';
        }
        text += line;
    }
    return text;
}

void test(){
    std::string text = "-123.456";
    size_t index = 0;
    Number number(text, index);
    std::cout << number.to_string() << '\n';

    index = 0;
    text = "true";
    Bool boolean(text, index);
    std::cout << boolean.to_string() << '\n';

    index = 0;
    text = "null";
    Null null(text, index);
    std::cout << null.to_string() << '\n';

    index = 0;
    text = "\"Hello, World!\\n\"";
    String string(text, index);
    std::cout << string.to_string() << '\n';

    index = 0;
    text = "[-7.8,true, null, null , \"Hello, World\"]";
    Array array(text, index);
    std::cout << array.to_string() << '\n';
}

int main(int argc, const char **argv){
    test();
    if(argc <= 1){
        std::cout << "Missing filename.\nApplication usage: " << argv[0] << " <filepath>\n";
        exit(EXIT_FAILURE);
    }
    std::string content = read_file(argv[1]);
}
