#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H


#include <chrono>

namespace  ctrl {

    class Stopwatch {
    public:
        Stopwatch();

        Stopwatch(const Stopwatch &rhs);

        Stopwatch &operator=(const Stopwatch &rhs);

        ~Stopwatch();

        void start();

        std::chrono::duration<double> stop();

    private:
        std::chrono::time_point<std::chrono::system_clock> m_start;
    };

} //namespace ctrl

#endif //GRADIUS_STOPWATCH_H
