def solution(A):
    passingCarsNum = 0
    eastDrivingCars = 0

    for car in A:
        if 0 == car:
            eastDrivingCars += 1
        elif 1 == car:
            passingCarsNum += eastDrivingCars

        if passingCarsNum > 1000000000:
            return -1

    return passingCarsNum


assert 0 == solution([ 1, 0 ])
assert 0 == solution([ 0, 2 ])
assert 1 == solution([ 0, 1 ])
assert 9 == solution([ 0, 0, 0, 1, 1, 1 ])
assert 5 == solution([ 0, 1, 0, 1, 1 ])

stressTestArr = [0] * 100000
stressTestArr.extend([1] * 10000)
assert 1000000000 == solution(stressTestArr)

stressTestArr.append(1)
assert -1 == solution(stressTestArr)
