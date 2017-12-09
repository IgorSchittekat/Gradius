#include "Stopwatch.h"

namespace util {


    Stopwatch::Stopwatch() {
        m_start = std::chrono::steady_clock::now();
        m_restart = std::chrono::steady_clock::now();
    }

    void Stopwatch::restart() {
        m_restart = std::chrono::steady_clock::now();
    }

    std::chrono::duration<double> Stopwatch::elapsed() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_restart);
    }

    std::chrono::duration<double> Stopwatch::getTime() const {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - m_start);
    }

} //namespace util