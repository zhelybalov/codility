#include <algorithm>
#include <assert.h>

int solution(int N)
{
    if (N <= 0)
    {
        return 0;
    }

    while (!(N & 0x1))
    {
        N = N >> 1;
    }

    int maxZeroSequence = 0;
    int curZeroSequence = 0;

    while (N)
    {
        if (N & 0x1)
        {
            maxZeroSequence = std::max(maxZeroSequence, curZeroSequence);
            curZeroSequence = 0;
        }
        else
        {
            curZeroSequence++;
        }
        N = N >> 1;
    }

    return maxZeroSequence;
}

int main()
{
    assert(0 == solution(0));           // 0
    assert(0 == solution(1));           // 0
    assert(0 == solution(4));           // 100
    assert(1 == solution(5));           // 101
    assert(4 == solution(529));         // 1000010001
    assert(29 == solution(1073741825)); // 01000000000000000000000000000001
    assert(0 == solution(2147483647));  // 01111111111111111111111111111111
    assert(0 == solution(2147483648));  // 10000000000000000000000000000000
}