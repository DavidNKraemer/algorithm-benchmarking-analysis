import sys
sys.path.append('..')
from util import shuffle

import time
import random


def insertion_sort(arr):
    l = len(arr)
    for i in range(1,l):
        to_insert = arr[i]
        j = i - 1
        while(j >= 0 and to_insert < arr[j]):
            # shift jth element to the right
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = to_insert
        
if __name__ == '__main__':
    for i in range(100):
        ordered = list(range(i))
        shuffled = shuffle(ordered)
        insertion_sort(shuffled)
        assert(ordered == shuffled)
    print("Success!")
    
