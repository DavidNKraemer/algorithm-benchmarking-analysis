#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear_search(int * arr, int n, int value);
int linear_search_helper(int * arr, int index, int n, int value, 
        int epsilon);

int main() {
    int array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%d\n", linear_search(array, 5, 4.0));

    return 0;
}

int linear_search(int * arr, int n, int value) {
    return linear_search_helper(arr, 0, n, value);
}

int linear_search_helper(int * arr, int index, int n, int value) {
    if (index == n) {
        return -1;
    }
    else {
        if (arr[index] = value) {
            return index;
        }
        else {
            return linear_search_helper(arr, index + 1, n, value);
        }
    }
}
