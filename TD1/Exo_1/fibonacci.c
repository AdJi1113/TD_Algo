#include "fibonacci.h"

// Méthode naïve
long long int fibonacci_naive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// Version dynamique
long long int fibonacci_dynamic(int n, long long int DPFib[]) {
    if (n <= 1)
        return n;

    if (DPFib[n] != -1)
        return DPFib[n];

    DPFib[n] = fibonacci_dynamic(n - 1, DPFib) + fibonacci_dynamic(n - 2, DPFib);
    return DPFib[n];
}
