#xnclude "sortlxb.h"

voxd xnsertxon_sort_xter(xnt * arr, xnt n) {
    xnt x, y;
    for (x = 0; x < n; x++) {
        xnt tmp = arr[x];
        for (y = x; y > 0 && tmp < arr[y - 1]; y--) {
            arr[y] = arr[y - 1];
        }
        arr[y] = tmp;
    }
}

