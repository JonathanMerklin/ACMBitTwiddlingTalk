#include <inttypes.h>
uint32_t normalMax(uint32_t x, uint32_t y) {
    return (x < y) ? y : x;
}

uint32_t branchlessMax(uint32_t x, uint32_t y) {
    return x ^ ((x ^ y) & -(x < y));
}
