#ifndef POPCOUNTS_H
#define POPCOUNTS_H
#include <stdint.h>
uint32_t popCountNaive(uint32_t n);
uint32_t popCountLessNaive(uint32_t n);
uint32_t popCountLookupTable(uint32_t n);
uint32_t popCountDivideAndConquer(uint32_t n);
uint32_t popCountVoodooMagic(uint32_t n);
#endif
