#include <stdio.h>
#include <time.h>
#include "prime.h"

int main() {
    int n = 1000000;  // définir n manuellement ici

    clock_t start, end;
    double time_naive, time_opti;

    // Méthode naïve
    start = clock();
    int result_naive = count_primes_naive(n);
    end = clock();
    time_naive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Prime naive: %d primes, Time = %f secondes\n", result_naive, time_naive);

    // Méthode optimisée
    start = clock();
    int result_opti = count_primes_optimized(n);
    end = clock();
    time_opti = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Prime optimized: %d primes, Time = %f secondes\n", result_opti, time_opti);

    return 0;
}
