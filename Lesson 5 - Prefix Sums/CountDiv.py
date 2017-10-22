def solution(A, B, K):
    if A > B or K <= 0:
        return 0

    excludes = A / K - (0 if A % K else 1)
    allDivisibles = B / K

    return allDivisibles - excludes

assert 0 == solution(12, 11, 2)
assert 0 == solution(6, 11, 0)
assert 0 == solution(11, 11, 2)
assert 1 == solution(10, 10, 2)
assert 3 == solution(6, 11, 2)
assert 3 == solution(5, 11, 2)
assert 4 == solution(6, 12, 2)
