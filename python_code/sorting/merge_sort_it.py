"""
Example use:
cat sort_data.csv | python3 merge_sort_it.py > msi.csv

"""

import sys
sys.path.append('..')
from util import shuffle

import time
        
def merge_sort(arr):
    l = len(arr)
    # merge subarrays of sizes doubling from 1 to array length
    cur_size = 1
    while cur_size < l:
        lo = 0
        while lo < l - 1: # for every nonoverlapping window of current size
            mid = lo + cur_size
            hi = min(mid + cur_size, l) # not going out of bounds
            merge(arr, lo, mid, hi)
            lo += 2 * cur_size # advance by full size
        cur_size *= 2 # double the current size
    
        
def merge(arr, lo, mid, hi):
    l = hi - lo
    temp = [0] * l
    temp_ind = 0
    left_ind = lo
    right_ind = mid
    while temp_ind < l:
        if (left_ind >= mid or
            (right_ind < hi and arr[right_ind] < arr[left_ind])): 
            temp[temp_ind] = arr[right_ind] # add from right subarray
            right_ind += 1
        else:
            temp[temp_ind] = arr[left_ind] # add from left subarray
            left_ind += 1
        temp_ind += 1
    # copy from temp into original array
    for i in range(l):
        arr[lo + i] = temp[i]
        
                
if __name__ == '__main__':
    # brief testing 
    for i in range(100):
        ordered = list(range(i))
        shuffled = shuffle(ordered)
        merge_sort(shuffled)
        assert(ordered == shuffled)
    #print("Success!")

    # Read in the arrays from stdin and output to stdout
    for line in sys.stdin:
        arr = [int(x) for x in line.split(',')]
        start = time.process_time()
        merge_sort(arr)
        end = time.process_time()
        # the first element is printed out so that sorting doesn't get
        # optimized out
        print("%d,%d,%f" % (len(arr), arr[0], end-start))
