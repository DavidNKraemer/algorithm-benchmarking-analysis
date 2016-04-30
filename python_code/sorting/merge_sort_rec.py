import sys

import time
import random

import pdb

def shuffle(arr):
    l = len(arr)
    ret = list(arr) # make a copy of the original
    for i in range(l**2):
        j = random.randint(0, l-1)
        k = random.randint(0, l-1)
        temp = ret[j]
        ret[j] = ret[k]
        ret[k] = temp
    return ret
        
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
    for i in range(100):
        ordered = list(range(i))
        shuffled = shuffle(ordered)
        merge_sort(shuffled)
        assert(ordered == shuffled)
    print("Success!")
