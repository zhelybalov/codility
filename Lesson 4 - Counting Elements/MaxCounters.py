def solution(N, A):
    minVal = 0
    maxVal = 0

    arr = [0] * N

    for operation in A:
        if operation >= 1 and operation <= N:
            arr[operation - 1] = max(arr[operation - 1], minVal) + 1
            maxVal = max(maxVal, arr[operation - 1])
        elif operation == N + 1:
            minVal = maxVal

    for i in range(len(arr)):
        arr[i] = max(arr[i], minVal)

    return arr


assert [ ] == solution(0, [])
assert [ 0 ] == solution(1, [])
assert [ 3 ] == solution(1, [ 1, 1, 1 ])
assert [ 0 ] == solution(1, [ 2, 2, 2 ])
assert [ 0 ] == solution(1, [ 0, -1, 3 ])
assert [ 3, 2, 2, 4, 2 ] == solution(5, [ 3, 4, 4, 6, 1, 4, 4 ])
