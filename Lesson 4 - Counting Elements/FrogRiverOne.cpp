#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

int solution(int X, std::vector<int> &A)
{
    if (X == 0)
    {
        return 0;
    }

    if (X < 0 || !A.size())
    {
        return -1;
    }

    std::vector<bool> isPresent(X, false);
    size_t requiredLeavesNum = static_cast<size_t>(X);

    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] > X || isPresent[A[i] - 1])
        {
            continue;
        }

        isPresent[A[i] - 1] = true;
        requiredLeavesNum--;

        if (!requiredLeavesNum)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    assert(0 == solution(0, std::vector<int>({ 1 })));
    assert(0 == solution(0, std::vector<int>({ 1 })));
    assert(-1 == solution(-5, std::vector<int>({ 1 })));
    assert(-1 == solution(1, std::vector<int>()));
    assert(0 == solution(1, std::vector<int>({ 1 })));
    assert(1 == solution(2, std::vector<int>({ 1, 2 })));
    assert(6 == solution(5, std::vector<int>({ 1, 3, 1, 4, 2, 3, 5, 4 })));
    assert(-1 == solution(5, std::vector<int>({ 1, 3, 1, 4, 6, 3, 5, 4 })));
}

