#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int n = 10000;   
    int target;
    printf("Target : ");
    scanf("%d", &target);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erreur d’allocation mémoire.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i+1;
    }

    if (!is_sorted_nondecreasing(arr, n)) {
        printf("Le tableau n’est pas trié.\n");
        free(arr);
        return 1;
    }

    clock_t start, end;
    double time_linear, time_jump, time_binary;
    int result_linear, result_jump, result_binary;

    // Linear Search
    start = clock();
    result_linear = linear_search(arr, n, target);
    end = clock();
    time_linear = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear Search: index = %d, Time = %f s\n", result_linear, time_linear);

    // Jump Search
    start = clock();
    result_jump = jump_search(arr, n, target);
    end = clock();
    time_jump = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Jump Search: index = %d, Time = %f s\n", result_jump, time_jump);

    // Binary Search
    start = clock();
    result_binary = binary_search(arr, n, target);
    end = clock();
    time_binary = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary Search: index = %d, Time = %f s\n", result_binary, time_binary);

    free(arr);
    return 0;
}

