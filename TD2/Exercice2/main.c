#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    int n = 100000;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 10);
    }


    int *arr_sel   = (int *)malloc(n * sizeof(int));
    int *arr_ins   = (int *)malloc(n * sizeof(int));
    int *arr_bub   = (int *)malloc(n * sizeof(int));
    int *arr_merge = (int *)malloc(n * sizeof(int));
    int *arr_quick = (int *)malloc(n * sizeof(int));

    if (!arr_sel || !arr_ins || !arr_bub || !arr_merge || !arr_quick) {
        printf("Erreur d'allocation mémoire pour les copies.\n");
        free(arr);
        return 1;
    }

    copy_array(arr, arr_sel, n);
    copy_array(arr, arr_ins, n);
    copy_array(arr, arr_bub, n);
    copy_array(arr, arr_merge, n);
    copy_array(arr, arr_quick, n);

    clock_t start, end;
    double time_sel, time_ins, time_bub, time_merge, time_quick;

    // Selection Sort
    start = clock();
    selection_sort(arr_sel, n);
    end = clock();
    time_sel = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f s, tri %s\n", time_sel,
           is_sorted_nondecreasing(arr_sel, n) ? "OK" : "FAIL");

    // Insertion Sort 
    start = clock();
    insertion_sort(arr_ins, n);
    end = clock();
    time_ins = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f s, tri %s\n", time_ins,
           is_sorted_nondecreasing(arr_ins, n) ? "OK" : "FAIL");

    // Bubble Sort 
    start = clock();
    bubble_sort(arr_bub, n);
    end = clock();
    time_bub = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f s, tri %s\n", time_bub,
           is_sorted_nondecreasing(arr_bub, n) ? "OK" : "FAIL");

    // Merge Sort 
    start = clock();
    merge_sort(arr_merge, n);
    end = clock();
    time_merge = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f s, tri %s\n", time_merge,
           is_sorted_nondecreasing(arr_merge, n) ? "OK" : "FAIL");

    // Quick Sort
    start = clock();
    quick_sort(arr_quick, n);
    end = clock();
    time_quick = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f s, tri %s\n", time_quick,
           is_sorted_nondecreasing(arr_quick, n) ? "OK" : "FAIL");

    free(arr);
    free(arr_sel);
    free(arr_ins);
    free(arr_bub);
    free(arr_merge);
    free(arr_quick);

    return 0;
}
