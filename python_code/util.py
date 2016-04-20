"""
    Check if two floats are close enough.
    Adopted from math.isclose in Python 3.5
"""
def isclose(a, b, rel_tol=1e-09):
    return abs(a-b) <= rel_tol * max(abs(a), abs(b))
