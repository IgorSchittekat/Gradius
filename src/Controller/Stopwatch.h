#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#pragma once

#include <chrono>
#include <memory>

namespace  ctrl {

    class Stopwatch {
    public:
        /**
         * @brief Constructor.
         */
        Stopwatch();

        /**
         * @brief Restarts the Stopwatch
         */
        void restart();

        /**
         * @brief Returns time between now and last restart
         * @return Time between now and last restart
         */
        std::chrono::duration<double> elapsed();

    private:
        /**
         * @brief time of last restart
         */
        std::chrono::steady_clock::time_point m_start;
    };

} //namespace ctrl

#endif //GRADIUS_STOPWATCH_H
