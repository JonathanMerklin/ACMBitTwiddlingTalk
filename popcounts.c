#include <stdint.h>

uint32_t popCountNaive(uint32_t n) {
    uint32_t count;
    for(count=0; n; n >>= 1) {
        count += n & 1;
    }
    return count;
}

uint32_t popCountLessNaive(uint32_t n) {
    uint32_t count;
    for(count = 0; n; count++) {
        n &= n-1;
    }
    return count;
}

uint32_t popCountLookupTable(uint32_t n) {
    static const unsigned char BitsSetTable256[256] = 
    {
    # define B2(n)  n,      n+1,        n+1,        n+2
    # define B4(n)  B2(n),  B2(n+1),    B2(n+1),    B2(n+2)
    # define B6(n)  B4(n),  B4(n+1),    B4(n+1),    B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
    };
    return  BitsSetTable256[n & 0x00ff] +
            BitsSetTable256[(n >> 8) & 0x00ff] +
            BitsSetTable256[(n >> 16) & 0x00ff] +
            BitsSetTable256[(n >> 24) & 0x00ff];
}

uint32_t popCountDivideAndConquer(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
    n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
    n = (n & 0x0000FFFF) + ((n >> 16)& 0x0000FFFF);
    return n;
}

uint32_t popCountVoodooMagic(uint32_t n) {
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

