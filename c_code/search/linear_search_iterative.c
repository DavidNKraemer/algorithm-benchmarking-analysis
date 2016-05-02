#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear_search(int * arr, int n, int value) {
    for(int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    printf("%d\n", linear_search(array, 5, 4));

    return 0;
}
