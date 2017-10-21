from sys import maxint

def solution(A):
    if (len(A) < 2):
        return 0

    rightPartSum = sum(A)

    leftPartSum = 0
    result = maxint
    for i in range(0, len(A) - 1):
        leftPartSum += A[i]
        rightPartSum -= A[i]

        localResult = abs(leftPartSum - rightPartSum)
        if localResult < result:
            result = localResult

    return result


assert 0 == solution([])
assert 0 == solution([1])
assert 0 == solution([1, 1])
assert 0 == solution([-1, 1, 0])
assert 1 == solution([3, 1, 2, 4, 3])
assert 0 == solution([maxint, maxint, maxint, maxint])
assert 1 == solution([-maxint - 1, -maxint - 1, -maxint - 1, -maxint - 1])
assert maxint == solution([maxint, maxint, maxint])
