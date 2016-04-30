"""
Example use:
cat sort_data.csv | python3 insertion_sort_it.py > isi.csv

"""
import sys
sys.path.append('..')
from util import shuffle

import time


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
    # breif testing
    for i in range(100):
        ordered = list(range(i))
        shuffled = shuffle(ordered)
        insertion_sort(shuffled)
        assert(ordered == shuffled)
    #print("Success!")
    

    # Read in the arrays from stdin and output to stdout
    for line in sys.stdin:
        arr = [int(x) for x in line.split(',')]
        start = time.process_time()
        insertion_sort(arr)
        end = time.process_time()
        # the first element is printed out so that sorting doesn't get
        # optimized out
        print("%d,%d,%f" % (len(arr), arr[0], end-start))
