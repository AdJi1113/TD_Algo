#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == target) {
            return i;
        }
    }
    return -1;
}

int jump_search(int *arr, int n, int target) {
    if (!is_sorted_nondecreasing(arr, n))
        return -1;

    int jump = sqrt(n);
    int prev = 0;
    int next = jump;

    while (next < n && arr[next - 1] < target) {
        prev = next;
        next += jump;
        if (next > n) next = n;
    }

    for (int i = prev; i < next; i++) {
        if (*(arr + i) == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr, int n, int target) {
    if (!is_sorted_nondecreasing(arr, n))
        return -1;
        
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (*(arr + mid) == target)
            return mid;
        else if (*(arr + mid) < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
