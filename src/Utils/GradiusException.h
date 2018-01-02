#ifndef GRADIUS_GRADIUSEXCEPTION_H
#define GRADIUS_GRADIUSEXCEPTION_H
#pragma once

#include <exception>

namespace util {

    class GradiusException : public std::exception {
    public:
        /**
         * @brief Constructor
         * @param what : Error massage
         * @param file : File name
         * @param line : Line number
         */
        GradiusException(std::string what, std::string file, unsigned int line) : std::exception(), mWhat(what), mFile(file), mLine(line) {}

        /**
         * @brief Returns Error massage
         * @return Error massage
         */
        const char* what() const noexcept override { return mWhat.c_str(); }

        /**
         * Returns the location where the error occurred
         * @return Location of the error
         */
        std::string location() const { return "line: " + std::to_string(mLine) + " in file: " + mFile; }

    private:
        /**
         * @brief Error message
         */
        std::string mWhat;
        /**
         * @brief File
         */
        std::string mFile;
        /**
         * @brief Line
         */
        unsigned int mLine;
    };

} // namespace util

#endif //GRADIUS_GRADIUSEXCEPTION_H
