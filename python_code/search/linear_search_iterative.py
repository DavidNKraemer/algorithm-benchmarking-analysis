# add the parent directory to the path
import sys
sys.path.append('..')

from util import isclose
    
def linear_search(arr, x):
    for i in range(len(arr)):
        if isclose(arr[i], x):
            return i
    return -1

if __name__ == '__main__':
    arr = list(range(100))
    for i in arr:
        assert(i == linear_search(arr, i))
    
    assert(-1 == linear_search(arr, 200))
    assert(-1 == linear_search(arr, -10))    
    print("Success!")
