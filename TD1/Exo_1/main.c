#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main() {
    int n = 45;  // définir n manuellement ici

    long long int DPFib[n + 1];
    for (int i = 0; i < n+1; i++)
        DPFib[i] = -1;


    clock_t start, end;
    double time_naive, time_dynamic;

    // Test de la version naïve
    start = clock();
    long long int result_naive = fibonacci_naive(n);
    end = clock();
    time_naive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Naive Fibonacci(%d) = %lld, Time = %f secondes\n", n, result_naive, time_naive);

    // Test de la version dynamique
    start = clock();
    long long int result_dynamic = fibonacci_dynamic(n, DPFib);
    end = clock();
    time_dynamic = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Dynamic version (DPFib) = %lld, Time = %f secondes\n", result_dynamic, time_dynamic);

    return 0;
}
