#include "Json.hpp"

std::ostream& operator<<(std::ostream& out, const Json& json){
    return json.print(out);
}
