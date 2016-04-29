"""
Example use:
cat bs_data.csv | python3 binary_search_iterative.py > bsi.csv

"""

import sys 
import time

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
    # brief testing 
    arr = list(range(100))
    for i in arr:
        assert(i == binary_search(arr, i))
    
    assert(-1 == binary_search(arr, 200))
    assert(-1 == binary_search(arr, -10))    
    #print("Success!")

    # Read in the arrays from stdin and output to stdout
    for line in sys.stdin:
        line_arr = line.split(',')
        item = int(line_arr[0])
        arr = [int(x) for x in line_arr[1:]]
        start = time.process_time()
        n = binary_search(arr, item)
        end = time.process_time()
        print("%d,%d,%f" % (len(arr),n,end-start))
        
    
