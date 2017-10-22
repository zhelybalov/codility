#include <assert.h>

int solution(int A, int B, int K)
{
    if (A > B || K <= 0)
    {
        return 0;
    }

    int excludes = A / K - (A % K ? 0 : 1);
    int allDivisibles = B / K;

    return allDivisibles - excludes;
}

int main()
{
    assert(0 == solution(12, 11, 2));
    assert(0 == solution(6, 11, 0));
    assert(0 == solution(11, 11, 2));
    assert(1 == solution(10, 10, 2));
    assert(3 == solution(6, 11, 2));
    assert(3 == solution(5, 11, 2));
    assert(4 == solution(6, 12, 2));
}
