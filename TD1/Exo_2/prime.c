#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

// Vérifie si un entier est premier (pour la méthode naïve)
static int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= (int)sqrt((double)x); i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

// Version naïve :
int count_primes_naive(int n) {
    int c = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime(i))
            c += 1;
    }
    return c;
}


// Version optimisée :
int count_primes_optimized(int n) {
    if (n <= 2) return 0;

    char *is_prime = malloc(n * sizeof(char));

    for (int i = 0; i < n; i++)
        is_prime[i] = 1;

    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i < n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = 0;
        }
    }

    int c = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime[i])
            c += 1;
    }

    free(is_prime);
    return c;
}
