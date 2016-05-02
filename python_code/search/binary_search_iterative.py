"""
Example use:
cat bs_data.csv | python3 binary_search_iterative.py > bsi.csv

"""

import sys
sys.path.append('..')
from util import benchmark_search, test_search


alg = "binary_search"
kind = "iterative"

def binary_search(arr, x):
    lo = 0
    hi = len(arr)
    while(lo < hi):
        mid = (hi + lo) // 2
        if (arr[mid] ==  x):
            return mid
        elif (arr[mid] > x): 
            hi = mid
        else: # arr[mid] < x
            lo = mid + 1
    return -1

if __name__ == '__main__':
    test_search(binary_search)
    benchmark_search(binary_search, alg, kind)
    
