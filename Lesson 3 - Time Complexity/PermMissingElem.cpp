#include <iostream>
#include <assert.h>

#include <algorithm>
#include <limits.h>
#include <vector>

int solution(std::vector<int> &A)
{
    int64_t refSum = A.size() + 1;
    int64_t curSum = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        refSum += i + 1;
        curSum += A[i];
    }

    return static_cast<int>(refSum - curSum);
}

int main()
{
    assert(1 == solution(std::vector<int>()));
    assert(2 == solution(std::vector<int>({ 1 })));
    assert(1 == solution(std::vector<int>({ 2 })));
    assert(4 == solution(std::vector<int>({ 2, 3, 1, 5 })));

    const int MaxArrSize = 100000; // by the task
    std::vector<int> stressTestArr(100000);
    for (int i = 0; i < MaxArrSize; i++)
        stressTestArr[i] = i + 1;
    assert(MaxArrSize + 1 == solution(stressTestArr));
}
