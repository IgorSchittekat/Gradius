#ifndef GRADIUS_RAND_H
#define GRADIUS_RAND_H
#pragma once

#include <random>


class Rand {
public:
    Rand() :
            rng( rd() ),
            rand( -1,1 ){}

    double getRandom() {
        return rand(rng);
    }


private:
    std::random_device rd;
    std::mt19937 rng;
    std::uniform_real_distribution<double> rand;
};


#endif //GRADIUS_RAND_H
