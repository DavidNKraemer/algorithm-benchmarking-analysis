#include "sortlib.h"

void merge_sort_rec(int * arr, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort_rec(arr, m);
    merge_sort_rec(arr + m, n - m);
    merge_rec(arr, n, m);
}

void merge_rec(int * arr, int n, int m) {
    int i,j,k;
    int x[n];
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n           ? arr[i++]
             : i == m           ? arr[j++]
             : arr[j] < arr[i]  ? arr[j++]
             :                    arr[i++];
    }
    for (i = 0; i < n; i++) {
        arr[i] = x[i];
    }
}
