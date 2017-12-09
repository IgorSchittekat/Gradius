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
        /**
         * @brief constructor, setUps the whole game
         */
        Game();

        /**
         * @brief play the game
         */
        void play();

    private:
        /**
         * @brief load the window
         * @param data : data needed to load the window
         */
        void loadWindow(nlohmann::json data);

        /**
         * @brief load the next level
         */
        void loadNextLevel();

    private:
        std::shared_ptr<view::Window> wnd;
        std::unique_ptr<model::Level> lvl;
        int m_lvl;
    };


} // namespace ctrl

#endif //GRADIUS_GAME_H
