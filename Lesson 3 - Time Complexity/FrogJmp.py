def solution(X, Y, D):
    if X > Y or D < 1:
        return 0

    distance = Y - X
    return distance / D + bool(distance % D)


assert 0 == solution(10, 20, 0)
assert 0 == solution(10, 10, 1)
assert 0 == solution(11, 10, 1)
assert 5 == solution(-15, -10, 1)
assert 3 == solution(10, 85, 30)
