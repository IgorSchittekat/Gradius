#include "Stopwatch.h"

namespace ctrl {

    Stopwatch::Stopwatch() {

    }

    Stopwatch::Stopwatch(const Stopwatch &rhs) {

    }

    Stopwatch &Stopwatch::operator=(const Stopwatch &rhs) {
        return *this;
    }

    Stopwatch::~Stopwatch() {

    }

    void Stopwatch::start() {
        m_start = std::chrono::system_clock::now();
    }

    std::chrono::duration<double> Stopwatch::stop() {
        return std::chrono::system_clock::now() - m_start;
    }

}