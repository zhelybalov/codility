from sys import maxint

def solution(A):
    isPresent = [0] * len(A)

    for num in A:
        if num > len(A):
            return 0

        isPresent[num - 1] = 1

    return int(sum(isPresent) == len(isPresent))


assert 1 == solution([]);
assert 1 == solution([ 1 ]);
assert 0 == solution([ 2 ]);
assert 1 == solution([ 4, 1, 3, 2 ]);
assert 0 == solution([ 4, 1, 3 ]);

stressTestArr = range(100000) # by the task
assert 1 == solution(stressTestArr)
stressTestArr[-1] = maxint
assert 0 == solution(stressTestArr)
