# add the grandparent directory to the path
import sys
sys.path.append('..')

from util import isclose

def binary_search(arr, x):
    lo = 0
    hi = len(arr)
    while(lo < hi):
        mid = (hi + lo) // 2
        if (isclose(arr[mid], x)):
            return mid
        elif (arr[mid] > x): 
            hi = mid
        else: # arr[mid] < x
            lo = mid + 1
    return -1

if __name__ == '__main__':
    arr = list(range(100))
    for i in arr:
        assert(i == binary_search(arr, i))
    
    assert(-1 == binary_search(arr, 200))
    assert(-1 == binary_search(arr, -10))    
    print("Success!")
