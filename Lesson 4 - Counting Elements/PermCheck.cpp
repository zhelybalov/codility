#include <iostream>
#include <assert.h>

#include <algorithm>
#include <limits.h>
#include <vector>

int solution(std::vector<int> &A)
{
    std::vector<bool> isPresent(A.size(), false);

    const int64_t size = static_cast<int64_t>(A.size());
    for (const auto& num : A)
    {
        if (num > size)
        {
            return false;
        }

        isPresent[num - 1] = true;
    }

    return std::all_of(isPresent.begin(), isPresent.end(), [](const bool& val) { return val; });
}

int main()
{
    assert(1 == solution(std::vector<int>()));
    assert(1 == solution(std::vector<int>({ 1 })));
    assert(0 == solution(std::vector<int>({ 2 })));
    assert(1 == solution(std::vector<int>({ 4, 1, 3, 2 })));
    assert(0 == solution(std::vector<int>({ 4, 1, 3 })));

    const int MaxArrSize = 100000; // by the task
    std::vector<int> stressTestArr(MaxArrSize);
    for (size_t i = 0; i < stressTestArr.size(); i++)
    {
        stressTestArr[i] = i + 1;
    }
    assert(1 == solution(stressTestArr));

    stressTestArr.back() = INT_MAX;
    assert(0 == solution(stressTestArr));
}
