#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear_search(double * arr, int n, double value, double epsilon) {
    for(int i = 0; i < n; i++) {
        if (fabs(arr[i] - value) < epsilon) {
            return i;
        }
    }
    return -1;
}

int main() {
    double array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%d\n", linear_search(array, 5, 4.0, 1e-5));

    return 0;
}
