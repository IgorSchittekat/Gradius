#include "Stopwatch.h"

namespace ctrl {


    Stopwatch::Stopwatch() {
        m_start = std::chrono::steady_clock::now();
    }

    void Stopwatch::restart() {
        m_start = std::chrono::steady_clock::now();
    }

    std::chrono::duration<double> Stopwatch::elapsed() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_start);
    }




}