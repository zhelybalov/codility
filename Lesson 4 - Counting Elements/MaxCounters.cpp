#include <assert.h>
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> solution(int N, std::vector<int> &A)
{
    int minVal = 0;
    int maxVal = 0;

    std::vector<int> arr(N, 0);

    for (const auto& operation : A)
    {
        if (operation >= 1 && operation <= N)
        {
            arr[operation - 1] = std::max(arr[operation - 1], minVal) + 1;
            maxVal = std::max(maxVal, arr[operation - 1]);
        }
        else if (operation == N + 1)
        {
            minVal = maxVal;
        }
    }

    for (auto& num : arr)
    {
        num = std::max(num, minVal);
    }

    return arr;
}

int main()
{
    assert(std::vector<int>() == solution(0, std::vector<int>()));
    assert(std::vector<int>({ 0 }) == solution(1, std::vector<int>()));
    assert(std::vector<int>({ 3 }) == solution(1, std::vector<int>({ 1, 1, 1 })));
    assert(std::vector<int>({ 0 }) == solution(1, std::vector<int>({ 2, 2, 2 })));
    assert(std::vector<int>({ 0 }) == solution(1, std::vector<int>({ 0, -1, 3 })));
    assert(std::vector<int>({ 3, 2, 2, 4, 2 }) == solution(5, std::vector<int>({ 3, 4, 4, 6, 1, 4, 4 })));
}

