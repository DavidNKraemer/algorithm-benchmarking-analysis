"""
Example use:
cat sort_data.csv | python3 merge_sort_rec.py > msr.csv

"""
import sys
sys.path.append('..')
from util import shuffle

import time
        
def merge_sort(arr):
    merge_sort_helper(arr, 0, len(arr))

def merge_sort_helper(arr, lo, hi):
    if (hi - lo > 1): # continue until array has size one
        mid = (lo + hi) // 2
        merge_sort_helper(arr, lo, mid)
        merge_sort_helper(arr, mid, hi)
        merge(arr, lo, mid, hi) 

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
    import random
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
