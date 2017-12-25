#include <iostream>
#include "Controller/Game.h"
#include "Utils/GradiusException.h"


int main() {
    try{
        ctrl::Game game;
        game.play();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
