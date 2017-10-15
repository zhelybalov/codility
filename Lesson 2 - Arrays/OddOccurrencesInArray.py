import sys

def solution(A):
    assert len(A) % 2
    res = 0
    for elem in A:
        res ^= elem
    return res

assert 1 == solution([ 1 ])
assert 1 == solution([ 1, 1, 1 ])
assert 3 == solution([ 3, 1, 1 ])
assert sys.maxint == solution([ 1, sys.maxint, 1 ])
assert -sys.maxint - 1 == solution([ 1, 1, -sys.maxint - 1 ])
assert 7 == solution([ 9, 3, 9, 3, 9, 7, 9 ])
