#ifndef GRADIUS_GAME_H
#define GRADIUS_GAME_H
#pragma once

#include "../View/Window.h"
#include "../Model/Level.h"
#include "../Utils/json.hpp"

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
        bool loadNextLevel();

    private:
        std::shared_ptr<view::Window> mWnd;
        std::unique_ptr<model::Level> mLvl;
        int mCurrentLvl;
        int mTotalLvls;
    };


} // namespace ctrl

#endif //GRADIUS_GAME_H
