#define MIN(x,y) x <= y ? x : y
void merge_sort_iter(int * arr, int n) {
    int curr_size, left_start;

    for (curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = MIN(left_start + 2 * curr_size - 1, n - 1);

            merge_iter(arr, left_start, mid, right_end);
        }
    }
}

void merge_iter(int * arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of
     * L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements
     * of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
