"""
Example use:
cat sort_data.csv | python3 merge_sort_rec.py > msr.csv

"""
import sys
sys.path.append('..')
from util import merge, benchmark_sort, test_sort

alg = "merge_sort"
kind = "recursive"
        
def merge_sort(arr):
    merge_sort_helper(arr, 0, len(arr))

def merge_sort_helper(arr, lo, hi):
    if (hi - lo > 1): # continue until array has size one
        mid = (lo + hi) // 2
        merge_sort_helper(arr, lo, mid)
        merge_sort_helper(arr, mid, hi)
        merge(arr, lo, mid, hi) 


if __name__ == '__main__':
    test_sort(merge_sort)
    benchmark_sort(merge_sort, alg, kind)
