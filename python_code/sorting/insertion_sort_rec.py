import sys
sys.path.append('..')
from util import shuffle

import time
import random


def insertion_sort(arr):
    insertion_sort_helper(arr, 1)
    
def insertion_sort_helper(arr, start):
    l = len(arr)
    if start < l:
        to_insert = arr[start]
        j = start - 1
        while(j >= 0 and to_insert < arr[j]):
            # shift jth element to the right
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = to_insert
        insertion_sort_helper(arr, start + 1)
        
if __name__ == '__main__':
    for i in range(100):
        ordered = list(range(i))
        shuffled = shuffle(ordered)
        insertion_sort(shuffled)
        assert(ordered == shuffled)
    print("Success!")
    
