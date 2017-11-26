#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H


#include <chrono>
#include <memory>

namespace  ctrl {

    class Stopwatch {
    public:
        Stopwatch();
        ~Stopwatch() = default;
        Stopwatch(const Stopwatch &rhs) = delete;
        Stopwatch &operator=(const Stopwatch &rhs) = delete;


        void restart();

        std::chrono::duration<double> elapsed();




    private:
        std::chrono::steady_clock::time_point m_start;
    };

} //namespace ctrl

#endif //GRADIUS_STOPWATCH_H
