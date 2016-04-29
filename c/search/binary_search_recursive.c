#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int binary_search(int * arr, int n, int value);
int binary_search_helper(int * arr, int low, int high, 
    int value);

int main() {
    int array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%d\n", binary_search(array, 5, 4.0, 1e-5));

    return 0;
}

int binary_search(int * arr, int n, int value) {
    return binary_search_helper(arr, 0, n, value);
   }

int binary_search_helper(int * arr, int low, int high, 
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
            return binary_search_helper(arr, mid + 1, high, value);
        }
        else {
            return binary_search_helper(arr, low, mid, value);
        }
    }
}



