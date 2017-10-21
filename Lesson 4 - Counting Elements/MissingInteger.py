def solution(A):
    isPresent = [0] * len(A)
    for i in range(len(A)):
        if A[i] > 0 and A[i] <= len(A):
            isPresent[A[i] - 1] = 1

    for i in range(len(isPresent)):
        if not isPresent[i]:
            return i + 1

    return len(A) + 1


assert 5 == solution([ 1, 3, 6, 4, 1, 2 ])
assert 4 == solution([ 1, 2, 3 ])
assert 1 == solution([ -1, -3 ])
