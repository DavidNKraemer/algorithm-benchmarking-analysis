#include "searchlib.h"
int binary_search_iter(int * arr, int n, int value) {
    int low = 0;
    int high = n;
    int mid;

    while (low != high) {
        mid = (low + high) / 2;
        if (value == arr[mid]) {
            return mid;
        }
        else if (arr[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid;
        }

    }
    return -1;

}
