#include <assert.h>
#include <vector>

int solution(std::vector<int> &A)
{
    auto minSlice = 10001.0;
    auto result = -1;

    for (size_t i = 0; i < A.size() - 1; i++)
    {
        auto curSlice = static_cast<double>(A[i] + A[i + 1]) / 2.0;
        if (curSlice < minSlice)
        {
            minSlice = curSlice;
            result = i;
        }

        if (A.size() - 2 == i)
        {
            break;
        }

        curSlice = static_cast<double>(A[i] + A[i + 1] + A[i + 2]) / 3.0;
        if (curSlice < minSlice)
        {
            minSlice = curSlice;
            result = i;
        }
    }

    return result;
}

int main()
{
    assert(0 == solution(std::vector<int>({ 10000, 10000 })));
    assert(0 == solution(std::vector<int>({ -10000, 10000, -10000 })));
    assert(1 == solution(std::vector<int>({ 4, 2, 2, 5, 1, 5, 8 })));
}
