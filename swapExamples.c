#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void normalSwap(uint32_t *x, uint32_t *y) {
    uint32_t temp = *x;
    *x = *y;
    *y = temp;
}

void xorSwap(uint32_t *x, uint32_t *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int main() {
    srand(time(NULL));
    uint32_t a, b;
    uint32_t* ptr_a = &a;
    uint32_t* ptr_b = &b;
    a = (uint32_t) rand() % 100;
    b = (uint32_t) rand() % 100;
    printf("The original value of a is %d.\n",a);
    printf("The original value of b is %d.\n",b);
    normalSwap(ptr_a,ptr_b);
    printf("After a normal swap, a is %d and b is %d.\n",a,b);
    xorSwap(ptr_a,ptr_b);
    printf("After an xor swap back, a is %d and is b %d.\n",a,b);
    return 0;
}
