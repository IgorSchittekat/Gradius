#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H
#pragma once

#include <chrono>
#include <memory>
#include "Singleton.h"

namespace  util {

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

    private:
        /**
         * @brief Constructor.
         */
        Stopwatch();

    private:
        /**
         * @brief time of last restart
         */
        std::chrono::steady_clock::time_point mRestart;
    };

} //namespace util

#endif //GRADIUS_STOPWATCH_H
