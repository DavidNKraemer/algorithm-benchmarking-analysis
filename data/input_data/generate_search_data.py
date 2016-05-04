"""
Generate a csv of sorted (yet random) float arrays.

Command line args: min_length(=10) max_length(=1000) incr(=50) repeats(=1) fn

The first column is the item to look for. Default values only generate 20 arrays
"""
from sys import argv
import random
from numpy import cumsum
from numpy.random import randint


"""
Generate a sorted array of floats of specified size
"""
def generate_array(size):
    return list(cumsum(randint(1,10,size)))

"""
Make a comma separated string from an array
"""
def array_to_csv_string(arr):
    return '{},'.format(len(arr)) + ','.join(str(x) for x in arr)

def array_to_scheme_list(arr, item):
    return str(item) + '\n(' + ' '.join([str(x) for x in arr]) + ')'

if __name__ == '__main__':
    min_length = int(argv[1]) if len(argv) > 1 else 10
    max_length = int(argv[2]) if len(argv) > 2 else 1000
    increments = int(argv[3]) if len(argv) > 3 else 50
    repeats    = int(argv[4]) if len(argv) > 4 else 1
    
    fn = argv[5] if len(argv) > 5 else "search_data.csv"
    s_fn = argv[6] if len(argv) > 6 else "search_data.scm"
    
    current_size = min_length
    with open(fn, 'w') as fp, open(s_fn, 'w') as s_fp:
        while(current_size < max_length):
            for i in range(repeats):
                # generate an array of current_size
                arr = generate_array(current_size)
                # pick an item to look for
                if random.random() > .5:
                    look_for = 0 # not in arr
                else:
                    look_for = arr[random.randint(0, len(arr) - 1)] # in arr
                # write the item and sorted array
                fp.write(str(look_for) + ',' +
                         array_to_csv_string(arr)+'\n')
                # write the scheme array
                s_fp.write(array_to_scheme_list(arr, look_for)+'\n')
            current_size += increments
            
