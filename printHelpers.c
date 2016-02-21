#include "printHelpers.h"
void print_binary(uint32_t n) {
    /* Iterate through, bit by bit. */
    uint32_t mask = 0x80000000;
    printf("0b");
    while(mask) {
        if(mask & n) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
}

void print_hex(uint32_t n) {
   printf("0x%08" PRIx32 "\n",n); 
}
