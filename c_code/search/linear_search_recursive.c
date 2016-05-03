#include "searchlib.h"

int linear_search_rec(int * arr, int n, int value) {
    return linear_search_rec_helper(arr, 0, n, value);
}

int linear_search_rec_helper(int * arr, int index, int n, int value) {
    if (index == n) {
        return -1;
    }
    else {
        if (arr[index] == value) {
            return index;
        }
        else {
            return linear_search_rec_helper(arr, index + 1, n, value);
        }
    }
}
