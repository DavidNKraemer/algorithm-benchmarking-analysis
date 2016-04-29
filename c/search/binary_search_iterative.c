#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary_search(int * arr, int n, int value) {
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


int main() {
    int array[5] = {1, 2, 3, 4, 5};
    printf("%d\n", binary_search(array, 5, 4));

    return 0;
}
