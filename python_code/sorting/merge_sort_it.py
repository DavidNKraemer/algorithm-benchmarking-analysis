"""
Example use:
cat sort_data.csv | python3 merge_sort_it.py > msi.csv

"""

import sys
sys.path.append('..')
from util import merge, benchmark_sort, test_sort

alg = "merge_sort"
kind = "iterative"

def merge_sort(arr):
    l = len(arr)
    # merge subarrays of sizes doubling from 1 to array length
    cur_size = 1
    while cur_size < l:
        lo = 0
        while lo < l - 1: # for every nonoverlapping window of current size
            mid = lo + cur_size
            hi = min(mid + cur_size, l) # not going out of bounds
            merge(arr, lo, mid, hi)
            lo += 2 * cur_size # advance by full size
        cur_size *= 2 # double the current size
    
                
if __name__ == '__main__':
    test_sort(merge_sort)
    benchmark_sort(merge_sort, alg, kind)
