import sys
import random
import time

"""
    Shuffle an array.
    Returns a permutation of the original. Original array remains intact.
"""
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

"""
Test a search
"""
def test_search(alg_func):
    arr = list(range(100))
    for i in arr:
        assert(i == alg_func(arr, i))
    
    assert(-1 == alg_func(arr, 200))
    assert(-1 == alg_func(arr, -10))


"""
Test a sort
"""
def test_sort(alg_func):
    for i in range(100):
        ordered = list(range(i))
        shuffled = shuffle(ordered)
        alg_func(shuffled)
        assert(ordered == shuffled)
        
"""
Run and time a search, read from stdin and write to stdout
"""
def benchmark_search(alg_func,alg_name,alg_impl):
    print("time,input,algorithm,implementation,language,dummy")
    for line in sys.stdin:
        line_arr = line.split(',')
        item = int(line_arr[0])
        # skip the second element--it is the length of the array
        arr = [int(x) for x in line_arr[2:]]
        start = time.process_time()
        n = alg_func(arr, item)
        end = time.process_time()
        print("%f,%d,%s,%s,Python,%d" % (end-start,
                                         len(arr),
                                         alg_name,
                                         alg_impl,
                                         n))

        
"""
Run and time a sort, read from stdin and write to stdout
"""
def benchmark_sort(alg_func,alg_name,alg_impl):
    print("time,input,algorithm,implementation,language,dummy")
    for line in sys.stdin:
        line_arr = line.split(',')
        item = int(line_arr[0])
        arr = [int(x) for x in line_arr[1:]]
        start = time.process_time()
        alg_func(arr)
        end = time.process_time()
        # the first element is printed out so that sorting doesn't get
        # optimized out
        print("%f,%d,%s,%s,Python,%d" % (end-start,
                                         len(arr),
                                         alg_name,
                                         alg_impl,
                                         arr[0]))
"""
Merge operation used in merge sort
"""
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
