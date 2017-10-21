def solution(A):
    refSum = len(A) + 1
    curSum = 0

    for i in range(0, len(A)):
        refSum += i + 1
        curSum += A[i]

    return refSum - curSum

assert 1 == solution([])
assert 2 == solution([ 1 ])
assert 1 == solution([ 2 ])
assert 4 == solution([ 2, 3, 1, 5 ])

MaxArrSize = 100000 # by the task
stressTestArr = []
for i in range(MaxArrSize):
    stressTestArr.append(i + 1)
assert MaxArrSize + 1 == solution(stressTestArr)
