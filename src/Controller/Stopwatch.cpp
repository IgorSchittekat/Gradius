#include "Stopwatch.h"

namespace ctrl {

    std::shared_ptr<Stopwatch> Stopwatch::m_instance = nullptr;

    std::shared_ptr<Stopwatch> Stopwatch::getInstance() {
        if (!m_instance) {
            m_instance = std::make_shared(Stopwatch());
        }
         return m_instance;
    }

    void Stopwatch::start() {
        m_start = std::chrono::system_clock::now();
    }

    std::chrono::duration<double> Stopwatch::stop() {
        return std::chrono::system_clock::now() - m_start;
    }


}