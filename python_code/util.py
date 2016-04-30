import random

"""
    Check if two floats are close enough.
    Adopted from math.isclose in Python 3.5
"""
def isclose(a, b, rel_tol=1e-09):
    return abs(a-b) <= rel_tol * max(abs(a), abs(b))

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
