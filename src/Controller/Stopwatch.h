#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#pragma once

#include <chrono>
#include <memory>
#include "Singleton.h"

namespace  ctrl {

    class Stopwatch : public Singleton<Stopwatch> {
        friend class Singleton<Stopwatch>;
    public:
        /**
         * @brief Restarts the Stopwatch
         */
        void restart();

        /**
         * @brief Returns time between now and last restart
         * @return Time between now and last restart
         */
        std::chrono::duration<double> elapsed();

        /**
         * @brief Returns time between now and begin of the game
         * @return Time between now and begin of the game
         */
        std::chrono::duration<double> getTime() const;

    private:
        /**
         * @brief Constructor.
         */
        Stopwatch();

    private:
        /**
         * @brief time of last restart
         */
        std::chrono::steady_clock::time_point m_restart;

        /**
         * @brief time of begin of the game
         */
        std::chrono::steady_clock::time_point m_start;

    };

} //namespace ctrl

#endif //GRADIUS_STOPWATCH_H
