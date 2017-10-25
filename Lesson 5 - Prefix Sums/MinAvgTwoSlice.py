def solution(A):
    minSlice = 10001.0
    result = -1

    for i in range(len(A)):
        curSlice = (A[i] + A[i + 1]) / 2.0
        if curSlice < minSlice:
            minSlice = curSlice
            result = i

        if len(A) - 2 == i:
            break

        curSlice = (A[i] + A[i + 1] + A[i + 2]) / 3.0
        if curSlice < minSlice:
            minSlice = curSlice
            result = i

    return result


assert 0 == solution([ 10000, 10000 ])
assert 0 == solution([ -10000, 10000, -10000 ])
assert 1 == solution([ 4, 2, 2, 5, 1, 5, 8 ])
