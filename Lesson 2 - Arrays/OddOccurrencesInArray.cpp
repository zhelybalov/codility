#include <assert.h>
#include <vector>

int solution(std::vector<int> &A)
{
    assert(A.size() % 2);
    int res = 0;
    for (const auto& elem : A)
    {
        res ^= elem;
    }
    return res;
}

int main()
{
    assert(1 == solution(std::vector<int>({ 1 })));
    assert(1 == solution(std::vector<int>({ 1, 1, 1 })));
    assert(3 == solution(std::vector<int>({ 3, 1, 1 })));
    assert(INT_MAX == solution(std::vector<int>({ 1, INT_MAX, 1 })));
    assert(INT_MIN == solution(std::vector<int>({ 1, 1, INT_MIN })));
    assert(7 == solution(std::vector<int>({ 9, 3, 9, 3, 9, 7, 9 })));
}