"""
Example use:
cat ls_data.csv | python3 linear_search_recursive.py > lsr.csv

"""
import sys
import time

def linear_search(arr, x):
    return linear_search_rec(arr, 0, x)

def linear_search_rec(arr, cur, x):
    if cur == len(arr):
        return -1
    else:
        if arr[cur] == x:
            return cur
        else:
            return linear_search_rec(arr, cur + 1, x)
        
if __name__ == '__main__':
    arr = list(range(100))
    for i in arr:
        assert(i == linear_search(arr, i))
    
    assert(-1 == linear_search(arr, 200))
    assert(-1 == linear_search(arr, -10))    
    #print("Success!")

    # Read in the arrays from stdin and output to stdout
    for line in sys.stdin:
        line_arr = line.split(',')
        item = int(line_arr[0])
        arr = [int(x) for x in line_arr[1:]]
        start = time.process_time()
        n = linear_search(arr, item)
        end = time.process_time()
        print("%d,%d,%f" % (len(arr),n,end-start))
