#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int binary_search(double * arr, int n, double value, double epsilon);
int binary_search_helper(double * arr, int low, int high, 
    double value, double epsilon);

int main() {
    double array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%d\n", binary_search(array, 5, 4.0, 1e-5));

    return 0;
}

int binary_search(double * arr, int n, double value, double epsilon) {
    return binary_search_helper(arr, 0, n, value, epsilon);
   }

int binary_search_helper(double * arr, int low, int high, 
    double value, double epsilon) {
    if (low == high) {
        return -1;
    }
    else {
        int mid = (low + high) / 2;
        if (fabs(value - arr[mid]) < epsilon) {
            return mid;
        }
        else if (arr[mid] < value) {
            return binary_search_helper(arr, mid + 1, high, value, epsilon);
        }
        else {
            return binary_search_helper(arr, low, mid, value, epsilon);
        }
    }
}



