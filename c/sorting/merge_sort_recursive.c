#include <stdlib.h>
#include <stdio.h>


void merge_sort(double * arr, int n) ;
void merge(double * arr, int n, int i) ;

int main() {
    double array[5] = {31.0, 12.0, 3.0, 14.0, 25.0};
    printf("{");
    for (int i = 0; i < 5; i++)
        printf("%0.2lf,",array[i]);
    printf("}\n");

    merge_sort(array, 5);
    printf("{");
    for (int i = 0; i < 5; i++)
        printf("%0.2lf,",array[i]);
    printf("}\n");

    return 0;

}

void merge_sort(double * arr, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(arr, m);
    merge_sort(arr + m, n - m);
    merge(arr, n, m);
}

void merge(double * arr, int n, int m) {
    int i,j,k;
    int x[n];
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n           ? arr[i++]
             : i == m           ? arr[j++]
             : arr[j] < arr[i]  ? arr[j++]
             :                    arr[i++];
    }
    for (i = 0; i < n; i++) {
        arr[i] = x[i];
    }
    // free(x);


}


