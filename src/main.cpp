#include <iostream>
#include "Controller/Game.h"
#include "Utils/GradiusException.h"


int main() {
    try {
        ctrl::Game game;
        game.play();
    }
    catch (util::GradiusException& e) {
        std::cout << e.what() << " Position: " << e.location() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "unidentified exception thrown" << std::endl;
    }

    return 0;
}
