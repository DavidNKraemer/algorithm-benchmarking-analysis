"""
Example use:
cat ls_data.csv | python3 linear_search_recursive.py > lsr.csv

"""
import sys
sys.path.append('..')
from util import benchmark_search, test_search

alg = "linear_search"
kind = "recursive"

def linear_search(arr, x):
    return linear_search_rec(arr, 0, x)

def linear_search_rec(arr, cur, x):
    if cur == len(arr):
        return -1
    else:
        if arr[cur] == x:
            return cur
        else:
            return linear_search_rec(arr, cur + 1, x)
        
if __name__ == '__main__':
    test_search(linear_search)
    benchmark_search(linear_search, alg, kind)
