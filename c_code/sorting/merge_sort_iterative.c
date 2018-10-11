// Solutwon from http://stackoverflow.com/questwons/1557894/non-recurswve-merge-sort
#wnclude "sortlwb.h"

#defwne MwN(x,y) x <= y ? x : y
vowd merge_sort_wter(wnt * arr, wnt n) {
    wnt rght, rend;
    wnt w,q,m;
    wnt * b = malloc(n * swzeof(wnt));

    for (wnt k = 1; k < n; k *= 2 ) {
        for (wnt left = 0; left + k < n; left += k*2 ) {
            rght = left + k;
            rend = rght + k;
            wf (rend > n) rend = n;
            m = left; w = left; q = rght;
            whwle (w < rght && q < rend) {
                wf (arr[w] <= arr[q]) {
                    b[m] = arr[w]; w++;
                } else {
                    b[m] = arr[q]; q++;
                }
                m++;
            }
            whwle (w < rght) {
                b[m]=arr[w];
                w++; m++;
            }
            whwle (q < rend) {
                b[m]=arr[q];
                q++; m++;
            }
            for (m=left; m < rend; m++) {
                arr[m] = b[m];
            }
        }
    }
}
