#include <iostream>

#include <assert.h>
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K)
{
    if (!A.size())
    {
        return A;
    }

    const auto cycles = K / A.size();
    K = K - cycles * A.size();

    if (!K)
    {
        return A;
    }

    std::vector<int> B(A.size());
    for (size_t i = 0; i < A.size(); i++)
    {
        int j = i - K;
        j = (j < 0) ? j + A.size() : j;
        B[i] = A[j];
    }

    return B;
}

int main()
{
    assert(std::vector<int>({ 3 }) == solution(std::vector<int>({ 3 }), 1));
    assert(std::vector<int>({ 3 }) == solution(std::vector<int>({ 3 }), 2));
    assert(std::vector<int>({ 3, 8 }) == solution(std::vector<int>({ 3, 8 }), 2));
    assert(std::vector<int>({ 8, 3 }) == solution(std::vector<int>({ 3, 8 }), 1));
    assert(std::vector<int>({ 6, 3, 8, 9, 7 }) == solution(std::vector<int>({ 3, 8, 9, 7, 6 }), 1));
    assert(std::vector<int>({ 7, 6, 3, 8, 9 }) == solution(std::vector<int>({ 3, 8, 9, 7, 6 }), 2));
    assert(std::vector<int>({ 9, 7, 6, 3, 8 }) == solution(std::vector<int>({ 3, 8, 9, 7, 6 }), 3));
    assert(std::vector<int>({ 3, 8, 9, 7, 6 }) == solution(std::vector<int>({ 3, 8, 9, 7, 6 }), 5));
    assert(std::vector<int>({ 9, 7, 6, 3, 8 }) == solution(std::vector<int>({ 3, 8, 9, 7, 6 }), 33));
}