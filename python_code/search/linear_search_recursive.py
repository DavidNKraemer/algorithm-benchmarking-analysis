# add the parent directory to the path
import sys
sys.path.append('..')

from util import isclose

def linear_search(arr, x):
    return linear_search_rec(arr, 0, x)

def linear_search_rec(arr, cur, x):
    if cur == len(arr):
        return -1
    else:
        if isclose(arr[cur], x):
            return cur
        else:
            return linear_search_rec(arr, cur + 1, x)
        
if __name__ == '__main__':
    arr = list(range(100))
    for i in arr:
        assert(i == linear_search(arr, i))
    
    assert(-1 == linear_search(arr, 200))
    assert(-1 == linear_search(arr, -10))    
    print("Success!")
