#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary_search(double * arr, int n, double value, double epsilon) {
    int low = 0;
    int high = n;
    int mid;

    while (low != high) {
        mid = (low + high) / 2;
        if (fabs(value - arr[mid]) < epsilon) {
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
    double array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%d\n", binary_search(array, 5, 4.0, 1e-5));

    return 0;
}
