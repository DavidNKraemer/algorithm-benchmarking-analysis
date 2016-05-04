// Solution from http://stackoverflow.com/questions/1557894/non-recursive-merge-sort
#include "sortlib.h"

#define MIN(x,y) x <= y ? x : y
void merge_sort_iter(int * arr, int n) {
    int rght, rend;
    int i,j,m;
    int * b = malloc(n * sizeof(int));

    for (int k = 1; k < n; k *= 2 ) {
        for (int left = 0; left + k < n; left += k*2 ) {
            rght = left + k;
            rend = rght + k;
            if (rend > n) rend = n;
            m = left; i = left; j = rght;
            while (i < rght && j < rend) {
                if (arr[i] <= arr[j]) {
                    b[m] = arr[i]; i++;
                } else {
                    b[m] = arr[j]; j++;
                }
                m++;
            }
            while (i < rght) {
                b[m]=arr[i];
                i++; m++;
            }
            while (j < rend) {
                b[m]=arr[j];
                j++; m++;
            }
            for (m=left; m < rend; m++) {
                arr[m] = b[m];
            }
        }
    }
}
