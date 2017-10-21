#include <iostream>
#include <assert.h>

#include <algorithm>
#include <limits.h>
#include <vector>

int solution(int X, int Y, int D)
{
    if (X > Y || D < 1)
    {
        return 0;
    }

    const unsigned int distance = Y - X;
    return distance / D + !!(distance % D);
}

int main()
{
    assert(0 == solution(10, 20, 0));
    assert(0 == solution(10, 10, 1));
    assert(0 == solution(11, 10, 1));
    assert(5 == solution(-15, -10, 1));
    assert(3 == solution(10, 85, 30));
}
