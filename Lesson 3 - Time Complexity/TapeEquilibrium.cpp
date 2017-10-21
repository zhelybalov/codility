#include <iostream>
#include <assert.h>

#include <algorithm>
#include <limits.h>
#include <vector>

int solution(std::vector<int> &A)
{
    if (A.size() < 2)
    {
        return 0;
    }

    int64_t rightPartSum = 0;
    std::for_each(A.begin(), A.end(), [&rightPartSum](const int& n) { rightPartSum += n; });

    int64_t leftPartSum = 0;
    int64_t result = INT_MAX;
    for (size_t i = 0; i < A.size() - 1; i++)
    {
        leftPartSum += A[i];
        rightPartSum -= A[i];

        int64_t localResult = std::abs(leftPartSum - rightPartSum);
        if (localResult < result)
        {
            result = localResult;
        }
    }

    return static_cast<int>(result);
}

int main()
{
    assert(0 == solution(std::vector<int>()));
    assert(0 == solution(std::vector<int>({ 1 })));
    assert(0 == solution(std::vector<int>({ 1, 1 })));
    assert(0 == solution(std::vector<int>({ -1, 1, 0 })));
    assert(1 == solution(std::vector<int>({ 3, 1, 2, 4, 3 })));
    assert(0 == solution(std::vector<int>({ INT_MAX, INT_MAX, INT_MAX, INT_MAX })));
    assert(0 == solution(std::vector<int>({ INT_MIN, INT_MIN, INT_MIN, INT_MIN })));
    assert(INT_MAX == solution(std::vector<int>({ INT_MAX, INT_MAX, INT_MAX })));
}
