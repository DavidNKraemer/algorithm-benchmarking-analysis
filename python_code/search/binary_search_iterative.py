"""
Example use:
cat search_data.csv | python3 binary_search_iterative.py > new_file.txt

"""
# add the grandparent directory to the path
import sys
sys.path.append('..')

from util import isclose
import time

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
    # brief testing 
    arr = list(range(100))
    for i in arr:
        assert(i == binary_search(arr, i))
    
    assert(-1 == binary_search(arr, 200))
    assert(-1 == binary_search(arr, -10))    
    print("Success!")

    # Read in the arrays from stdin and output to stdout
    for line in sys.stdin:
        line_arr = line.split(',')
        item = float(line_arr[0])
        arr = [float(x) for x in line_arr[1:]]
        start = time.clock()
        n = binary_search(arr, item)
        end = time.clock()
        print("%d,%d,%f" % (len(arr),n,end-start))
        
    
