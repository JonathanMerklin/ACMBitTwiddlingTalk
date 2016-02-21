#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include "maxExamples.h"
#include "printHelpers.h"

void test_single_max(int variant);
void test_multiple_maxes(int variant, int count);

int main(int argc, char* argv[]) {
    srand(time(NULL));
    if (argc != 3) {
        fprintf(stderr, "Usage: ./testMax [max variant] [number of maxes]\n");
        return 1;
    }
    int variant = atoi(argv[1]);
    /*
        Variant 1 = Normal Max
        Variant 2 = Brnachless Max
    */
    if(variant != 1 && variant != 2) {
        fprintf(stderr,"Invalid variant.\n");
        return 1;
    }
    int count = atoi(argv[2]);
    if(count <= 0) {
        fprintf(stderr,"Invalid number of maxes to calculate.\n");
        return 1;
    }
    else if(count == 1){
        test_single_max(variant);
    } 
    else {
        //since we're doing this for timing comparison purposes, let's just do this part, oh, say, 10000 iterations..
        int i;
        for(i=0; i<10000; i++){
            test_multiple_maxes(variant, count);
        }
    }
    return 0;
}

void test_single_max(int variant) {
    uint32_t x = (uint32_t) rand();
    uint32_t y = (uint32_t) rand();
    uint32_t computed_max;
    switch (variant) {
        case 1:
            computed_max = normalMax(x,y);
            break;
        case 2:
            computed_max = branchlessMax(x,y);
            break;
        default:
            fprintf(stderr,"Something went wrong picking the variant.\n");
            return;
    }
    printf("X was %" PRIu32". In binary: ",x); print_binary(x);
    printf("Y was %" PRIu32". In binary: ",y); print_binary(y);
    printf("The computed max was %" PRIu32". In binary: ", computed_max); print_binary(computed_max);
}

void test_multiple_maxes(int variant, int count) {
    uint32_t xs[count];
    uint32_t ys[count];
    uint32_t computed_max = 0;
    int i;
    for(i=0; i<count; ++i) {
        xs[i] = (uint32_t) rand();
        ys[i] = (uint32_t) rand();
    }
    switch (variant) {
        case 1:
            for(i=0; i<count; ++i) { computed_max = normalMax(xs[i],ys[i]); }
            break;
        case 2:
            for(i=0; i<count; ++i) { computed_max = branchlessMax(xs[i],ys[i]); }
            break;
        default:
            fprintf(stderr, "Something went wrong picking the variant.\n");
            return;
    } 
    printf("All maxes have been calculated.\n");
    printf("For reference, the last values of X, Y, and the computed max were:\n");
    printf("X: %"PRIu32"\n",xs[count-1]);
    printf("Y: %"PRIu32"\n",ys[count-1]);
    printf("Max %"PRIu32"\n",computed_max);
}
