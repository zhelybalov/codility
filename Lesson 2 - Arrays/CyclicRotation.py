def solution(A, K):
    if not len(A):
        return A

    cycles = int(K / len(A))
    K = K - cycles * len(A)

    if not K:
        return A

    B = A[:]
    for i in range(0, len(A)):
        j = i - K
        j = j + len(A) if j < 0 else j
        B[i] = A[j]

    return B

assert [ 3             ] == solution([ 3 ], 1)
assert [ 3             ] == solution([ 3 ], 2)
assert [ 3, 8          ] == solution([ 3, 8 ], 2)
assert [ 8, 3          ] == solution([ 3, 8 ], 1)
assert [ 6, 3, 8, 9, 7 ] == solution([ 3, 8, 9, 7, 6 ], 1)
assert [ 7, 6, 3, 8, 9 ] == solution([ 3, 8, 9, 7, 6 ], 2)
assert [ 9, 7, 6, 3, 8 ] == solution([ 3, 8, 9, 7, 6 ], 3)
assert [ 3, 8, 9, 7, 6 ] == solution([ 3, 8, 9, 7, 6 ], 5)
assert [ 9, 7, 6, 3, 8 ] == solution([ 3, 8, 9, 7, 6 ], 33)
