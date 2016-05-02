"""
Example use:
cat bs_data.csv | python3 binary_search_recursive.py > bsr.csv

"""
import sys
sys.path.append('..')
from util import benchmark_search, test_search


alg = "binary_search"
kind = "recursive"

def binary_search(arr, x):
    return binary_search_rec(arr, 0, len(arr), x)
    
def binary_search_rec(arr, lo, hi, x):
    if (lo == hi):
        return -1
    else:
        mid = (hi + lo) // 2
        if (arr[mid] == x):
            return mid
        elif (arr[mid] > x): 
            return binary_search_rec(arr, lo, mid, x)
        else: # arr[mid] < x 
            return binary_search_rec(arr, mid + 1, hi, x)


if __name__ == '__main__':
    test_search(binary_search)
    benchmark_search(binary_search, alg, kind)
