#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear_search(double * arr, int n, double value, double epsilon);
int linear_search_helper(double * arr, int index, int n, double value, 
        double epsilon);

int main() {
    double array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%d\n", linear_search(array, 5, 4.0, 1e-5));

    return 0;
}

int linear_search(double * arr, int n, double value, double epsilon) {
    return linear_search_helper(arr, 0, n, value, epsilon);
}

int linear_search_helper(double * arr, int index, int n, double value, 
        double epsilon) {
    if (index == n) {
        return -1;
    }
    else {
        if (fabs(arr[index] - value) < epsilon) {
            return index;
        }
        else {
            return linear_search_helper(arr, index + 1, n, value, epsilon);
        }
    }
}
