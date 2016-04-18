#include <stdio.h>

void insertion_sort(double * arr, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        double tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

int main() {
    double array[5] = {31.0, 12.0, 3.0, 14.0, 25.0};
    printf("{");
    for (int i = 0; i < 5; i++)
        printf("%0.2lf,",array[i]);
    printf("}\n");

    insertion_sort(array, 5);
    printf("{");
    for (int i = 0; i < 5; i++)
        printf("%0.2lf,",array[i]);
    printf("}\n");


    return 0;

}
