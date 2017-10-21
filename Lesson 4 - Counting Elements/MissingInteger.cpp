#include <assert.h>
#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
    std::vector<bool> isPresent(A.size(), false);
    const int64_t size = static_cast<int64_t>(A.size());
    for (const auto& num : A)
    {
        if (num > 0 && num <= size)
        {
            isPresent[num - 1] = true;
        }
    }

    auto it = std::find_if(isPresent.begin(), isPresent.end(), [](const bool& val) { return !val; });
    return it != isPresent.end() ? it - isPresent.begin() + 1 : A.size() + 1;
}

int main()
{
    assert(5 == solution(std::vector<int>({ 1, 3, 6, 4, 1, 2 })));
    assert(4 == solution(std::vector<int>({ 1, 2, 3 })));
    assert(1 == solution(std::vector<int>({ -1, -3 })));
}

