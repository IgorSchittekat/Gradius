#ifndef GRADIUS_GRADIUSEXCEPTION_H
#define GRADIUS_GRADIUSEXCEPTION_H
#pragma once

#include <exception>

namespace util {

    class GradiusException : public std::exception {
    public:
        GradiusException(std::string what) : mWhat(what) {}

        const char* what() const noexcept override { return mWhat.c_str(); }

    private:
        std::string mWhat;
    };

} // namespace util

#endif //GRADIUS_GRADIUSEXCEPTION_H
