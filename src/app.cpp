#include <iostream>
#include <fstream>
#include <chrono>

#include "Array.hpp"
#include "Bool.hpp"
#include "Null.hpp"
#include "Number.hpp"
#include "String.hpp"
#include "utility.hpp"
#include "JsonFile.hpp"

namespace chrono = std::chrono;

const double NANOSECONDS_PER_SECOND = 1'000'000'000;

int main(int argc, const char **argv){
    if(argc <= 1){
        std::cout << "Missing filename.\nApplication usage: " << argv[0] << " <filepath>\n";
        exit(EXIT_FAILURE);
    }
    JsonFile file(argv[1]);
    chrono::time_point start = chrono::steady_clock::now();
    std::shared_ptr<Json> object = parse_json(file);
    chrono::time_point parsing = chrono::steady_clock::now();
    std::cout << *object << '\n' << std::flush;
    chrono::time_point printing = chrono::steady_clock::now();
    std::cout << "Parsing: " << (parsing - start).count() / NANOSECONDS_PER_SECOND << " seconds\n";
    std::cout << "Printing: " << (printing - parsing).count() / NANOSECONDS_PER_SECOND << " seconds\n";
}
