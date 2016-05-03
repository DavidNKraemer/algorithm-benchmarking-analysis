#include "sortlib.h"


void insertion_sort_rec(int * arr, int n) {
    insertion_sort_rec_helper(arr, n, 0);
}

void insertion_sort_rec_helper(int * arr, int n, int i) {
    if (i == n) {
        return;
    } 
    else {
        int tmp = arr[i];
        int j = insertion_sort_rec_helper_helper(arr, n, i, tmp);
        arr[j] = tmp;
        insertion_sort_rec_helper(arr, n, i+1);
    }
}

int insertion_sort_rec_helper_helper(int * arr, int n, int j, int placeholder) {
    if (j == 0 || placeholder >= arr[j - 1]) {
        return j;
    }
    else {
        arr[j] = arr[j - 1];
        return insertion_sort_rec_helper_helper(arr, n, j-1, placeholder);
    }
}
