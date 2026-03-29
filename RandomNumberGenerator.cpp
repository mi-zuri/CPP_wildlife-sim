//
// Created by Michał on 2023-04-23.
//

#include "RandomNumberGenerator.h"
#include <random>

namespace rng {
    int integer(int min, int max) {
        std::random_device rd;  // generating seed for rng
        std::mt19937 rng(rd()); // generating rn
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max); // distribution in range [min, max]

        return (int)dist(rng);
    }
}

/// Source: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c