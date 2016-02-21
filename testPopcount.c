#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include "printHelpers.h"
#include "popcounts.h"

void perform_single_popcount(int variant);
void perform_multiple_popcounts(int variant, int count);

int main(int argc, char* argv[]) {
    srand(time(NULL));
    if(argc!=3) {
        fprintf(stderr, "Usage: ./testPopcounts [popCountVariantNumber] [1 or the size of the array for each iteration]\n");
        return 1;
    }
    int popcount_variant  = atoi(argv[1]);
    //check to make sure we're inputting a valid popcount variant.
    /*
    1 = Naive way
    2 = Slightly less naive way
    3 = Lookup Table way
    4 = Divide and Conquer way
    5 = Voodoo Magic (Optimized D&C) way
    */
    if(popcount_variant < 1 || popcount_variant > 5) {
        fprintf(stderr, "Invalid popcount variant.\n");
        return 1;
    }
    int number_of_popcounts = atoi(argv[2]);
    if(number_of_popcounts <= 0) {
        fprintf(stderr, "Invalid number of popcounts.\n");
        return 1;
    }
    else if (number_of_popcounts == 1) {
        perform_single_popcount(popcount_variant);
    }
    else {
        //as before, let's do this, say, 10000 times.
        int i;
        for(i=0; i<10000; ++i) {
            perform_multiple_popcounts(popcount_variant, number_of_popcounts);
        }
    }
    return 0;
}

void perform_single_popcount(int variant) {
    uint32_t n = (uint32_t) rand();
    uint32_t popcount;
    switch (variant) {
        case 1:
            popcount = popCountNaive(n); break;
        case 2:
            popcount = popCountLessNaive(n); break;
        case 3:
            popcount = popCountLookupTable(n); break;
        case 4:
            popcount = popCountDivideAndConquer(n); break;
        case 5:
            popcount = popCountVoodooMagic(n); break;
        default:
            fprintf(stderr,"Something went wrong picking the variant.\n");
            return;
    }
    printf("n was %"PRIu32"\tBinary: ",n); print_binary(n);
    printf("The computed popcount was %"PRIu32"\n",popcount);
}

void perform_multiple_popcounts(int variant, int count) {
    uint32_t ns[count];
    uint32_t calculated_popcount;
    int i; for(i=0; i<count; ++i) {ns[i] = (uint32_t) rand(); }
    switch (variant) {
        case 1:
            for(i=0; i<count; ++i) {calculated_popcount = popCountNaive(ns[i]);}
            break;
        case 2:
            for(i=0; i<count; ++i) {calculated_popcount = popCountLessNaive(ns[i]);}
            break;
        case 3:
            for(i=0; i<count; ++i) {calculated_popcount = popCountLookupTable(ns[i]);}
            break;
        case 4:
            for(i=0; i<count; ++i) {calculated_popcount = popCountDivideAndConquer(ns[i]);}
            break;
        case 5:
            for(i=0; i<count; ++i) {calculated_popcount = popCountVoodooMagic(ns[i]);}
            break;
        default:
            fprintf(stderr,"Sometehing went wrong picking the variant.\n");
            return;
    }
    printf("Finished calculating popcounts.\n");
    printf("For reference, the last value of n was %"PRIu32"\n",ns[count-1]);
    printf("In binary: "); print_binary(ns[count-1]);
    printf("Its calculated popcount was %"PRIu32"\n",calculated_popcount);
}
