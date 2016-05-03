#include "sortlib.h"

void insertion_sort_iter(int * arr, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

