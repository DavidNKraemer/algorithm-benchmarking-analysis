#include <stdio.h>


void insertion_sort(double * arr, int n) ;
void insertion_sort_helper(double * arr, int n, int i) ;
int insertion_sort_helper_helper(double * arr, int n, int j, double placeholder) ;

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

void insertion_sort(double * arr, int n) {
    insertion_sort_helper(arr, n, 0);
}

void insertion_sort_helper(double * arr, int n, int i) {
    if (i == n) {
        return;
    } 
    else {
        double tmp = arr[i];
        int j = insertion_sort_helper_helper(arr, n, i, tmp);
        arr[j] = tmp;
        insertion_sort_helper(arr, n, i+1);
    }
}

int insertion_sort_helper_helper(double * arr, int n, int j, double placeholder) {
    if (j == 0 || placeholder >= arr[j - 1]) {
        return j;
    }
    else {
        arr[j] = arr[j - 1];
        return insertion_sort_helper_helper(arr, n, j-1, placeholder);
    }
}
