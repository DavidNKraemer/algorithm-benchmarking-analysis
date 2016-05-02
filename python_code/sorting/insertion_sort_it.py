"""
Example use:
cat sort_data.csv | python3 insertion_sort_it.py > isi.csv

"""
import sys
sys.path.append('..')
from util import benchmark_sort, test_sort

alg = "insertion_sort"
kind = "iterative"

def insertion_sort(arr):
    l = len(arr)
    for i in range(1,l):
        to_insert = arr[i]
        j = i - 1
        while(j >= 0 and to_insert < arr[j]):
            # shift jth element to the right
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = to_insert
        
if __name__ == '__main__':
    test_sort(insertion_sort)
    benchmark_sort(insertion_sort, alg, kind)
