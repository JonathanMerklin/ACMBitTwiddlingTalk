# ACMBitTwiddlingTalk

Note that due to time constraints, we will not be dealing with the branchless
max example.

###XOR SWAP EXAMPLE

Pretty simple, once I go through some GCC flags and introduce some basic bit
twiddling concepts, we'll introduce the XOR swap, examine the (optimized)
assembly, and then actually compile and run it.

* gcc -O2 -g -c -Wa,-ahl="swapExamples.s" swapExamples.c
* vim ./swapExamples.s
* gcc -O2 -Wall -o "swapExamples" swapExamples.c
* ./swapExamples [value]

###POPCOUNT EXAMPLE

After I go through the awesome ordeal of explaining the 5 different variations
on how to calculate the popcount, we're going to investigate the assembly to
prove how awesome the voodoo magic way is. Then, we'll run each one on a single
value just to make sure they work, then we'll run each one on 50000 values,
10000 times to test them for time.

* gcc -O2 -g -c -Wa,-ahl="popcounts.s" popcounts.c
* vim ./popcounts.s
* gcc -O2 -Wall -o "popcounts" popcounts.c printHelpers.c testPopcount.c
* ./popcounts 1 1
* ./popcounts 2 1
* ./popcounts 3 1
* ./popcounts 4 1
* ./popcounts 5 1
* command time -v ./popcounts 1 50000 > /dev/null
* command time -v ./popcounts 2 50000 > /dev/null
* command time -v ./popcounts 3 50000 > /dev/null
* command time -v ./popcounts 4 50000 > /dev/null
* command time -v ./popcounts 5 50000 > /dev/null

Note that I am aware that there is an existing small bug in the code which
causes the program to not generate all possible uint32_t values. I know where it
is, but I'd like Github to be a somewhat social platform, so here's a challenge:
If you find it, fix it and shoot me a pull request and I'll buy you a
Chik-fil-a milkshake (or Wendy's frosty, if that's your thing). :)
