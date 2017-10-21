def solution(X, A):
    if not X:
        return 0

    if X < 0 or not len(A):
        return -1

    isPresent = [0] * X
    requiredLeavesNum = X

    for i in range(len(A)):
        if A[i] > X or isPresent[A[i] - 1]:
            continue

        isPresent[A[i] - 1] = 1
        requiredLeavesNum -= 1

        if not requiredLeavesNum:
            return i

    return -1


assert 0  == solution(0, [ 1 ]);
assert 0  == solution(0, [ 1 ]);
assert -1 == solution(-5,[ 1 ]);
assert -1 == solution(1, []);
assert 0  == solution(1, [ 1 ]);
assert 1  == solution(2, [ 1, 2 ]);
assert 6  == solution(5, [ 1, 3, 1, 4, 2, 3, 5, 4 ]);
assert -1 == solution(5, [ 1, 3, 1, 4, 6, 3, 5, 4 ]);
