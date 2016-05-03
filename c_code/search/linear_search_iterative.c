#include "searchlib.h"

int linear_search_iter(int * arr, int n, int value) {
    for(int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
