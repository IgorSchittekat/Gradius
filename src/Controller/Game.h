#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H
#pragma once

#include "../View/Window.h"
#include "../Model/Level.h"

namespace ctrl {


    class Game {
    public:
        Game();

        void play();

    private:
        view::Window* wnd;
        model::Level* lvl;
    };


} // namespace ctrl

#endif //GRADIUS_GAME_H
