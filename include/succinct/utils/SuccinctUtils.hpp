#ifndef SUCCINCT_UTILS_H
#define SUCCINCT_UTILS_H

#include <cstdint>

#include "succinct/utils/definitions.hpp"

class SuccinctUtils {
public:
    // Returns the number of set bits in a 64 bit integer
    static uint64_t popcount(uint64_t n);

    // Returns integer logarithm to the base 2
    static uint32_t int_log_2(uint64_t n);

    // Returns a modulo n
    static uint64_t modulo(int64_t a, uint64_t n);
};

#endif