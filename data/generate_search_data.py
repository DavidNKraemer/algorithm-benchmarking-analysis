from sys import argv
import random 
"""
Generate a sorted array of floats of specified size
"""
def generate_array(size):
    arr = []
    cur = 1.0
    for i in range(size):
        arr.append(cur)
        cur += random.uniform(1.0, 5.0)
    return arr

"""
Make a comma separated string from an array
"""
def array_to_csv_string(arr):
    s = ''
    for i in range(len(arr) - 1):
        s += str(arr[i]) + ','
    s += str(arr[len(arr) - 1])
    return s

if __name__ == '__main__':
    min_length = int(argv[1]) if len(argv) > 1 else 10
    max_length = int(argv[2]) if len(argv) > 2 else 1000
    increments = int(argv[3]) if len(argv) > 3 else 50
    repeats    = int(argv[4]) if len(argv) > 4 else 1
    
    fn = argv[5] if len(argv) > 5 else "search_data.csv"

    current_size = min_length
    with open(fn, 'w') as fp:
        while(current_size < max_length):
            for i in range(repeats):
                # write sorted array of current_size
                fp.write(array_to_csv_string(generate_array(current_size))+'\n')
            current_size += increments
            
