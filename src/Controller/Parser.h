#ifndef GRADIUS_PARSER_H
#define GRADIUS_PARSER_H

#include <string>
#include "../View/World.h"

namespace ctrl {

class Parser {
public:

    static view::World* parseWorld();

};

} //namespace ctrl

#endif //GRADIUS_PARSER_H
