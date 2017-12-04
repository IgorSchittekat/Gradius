#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H
#pragma once

#include "../View/Window.h"
#include "../Model/Level.h"
#include "json.hpp"

namespace model {
    enum class Direction;
}

namespace ctrl {


    class Game {
    public:
        Game();

        void play();

    private:
        void loadWindow(nlohmann::json data);

        void loadShip(nlohmann::json data);

        void loadEnemy(nlohmann::json data);

        void loadBulletTexture(nlohmann::json data);

        void loadNextLevel();

    private:
        std::shared_ptr<view::Window> wnd;
        std::unique_ptr<model::Level> lvl;
        int m_lvl;
    };


} // namespace ctrl

#endif //GRADIUS_GAME_H
