# add the parent directory to the path
import sys
sys.path.append('..')

from util import isclose

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
    arr = list(range(100))
    for i in arr:
        assert(i == binary_search(arr, i))
    
    assert(-1 == binary_search(arr, 200))
    assert(-1 == binary_search(arr, -10))    
    print("Success!")
