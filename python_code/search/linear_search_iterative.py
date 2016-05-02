"""
Example use:
cat ls_data.csv | python3 linear_search_iterative.py > lsi.csv

"""
import sys
sys.path.append('..')
from util import benchmark_search, test_search


alg = "linear_search"
kind = "iterative"
    
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1


if __name__ == '__main__':
    test_search(linear_search)
    benchmark_search(linear_search, alg, kind)
