#include "searchlib.h"

int binary_search_rec(int * arr, int n, int value) {
    return binary_search_rec_helper(arr, 0, n, value);
   }

int binary_search_rec_helper(int * arr, int low, int high, 
    int value) {
    if (low == high) {
        return -1;
    }
    else {
        int mid = (low + high) / 2;
        if (value == arr[mid]) {
            return mid;
        }
        else if (arr[mid] < value) {
            return binary_search_rec_helper(arr, mid + 1, high, value);
        }
        else {
            return binary_search_rec_helper(arr, low, mid, value);
        }
    }
}



