#include "Stopwatch.h"

namespace util {


    Stopwatch::Stopwatch() {
        mStart = std::chrono::steady_clock::now();
        mRestart = std::chrono::steady_clock::now();
    }

    void Stopwatch::restart() {
        mRestart = std::chrono::steady_clock::now();
    }

    std::chrono::duration<double> Stopwatch::elapsed() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - mRestart);
    }

    std::chrono::duration<double> Stopwatch::getTime() const {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - mStart);
    }

} //namespace util