#ifndef GRADIUS_STOPWATCH_H
#define GRADIUS_STOPWATCH_H


#include <chrono>
#include <memory>

namespace  ctrl {

    class Stopwatch {
    public:

        Stopwatch(const Stopwatch &rhs) = delete;
        Stopwatch &operator=(const Stopwatch &rhs) = delete;

        static std::shared_ptr<Stopwatch> getInstance();

        void start();

        std::chrono::duration<double> stop();

    private:
        static std::shared_ptr<Stopwatch> m_instance;
        std::chrono::time_point<std::chrono::system_clock> m_start;

    private:
        Stopwatch() = default;
        ~Stopwatch() = default;
    };

} //namespace ctrl

#endif //GRADIUS_STOPWATCH_H
