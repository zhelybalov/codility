#include <assert.h>
#include <vector>
#include <unordered_map>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q)
{
    if (!S.size() || !P.size() || P.size() != Q.size())
    {
        return std::vector<int>();
    }

    std::unordered_map<char, int> nucleotidesImpact({ {'A', 0},{ 'C', 1 },{ 'G', 2 },{ 'T', 3 } });

    std::vector<int> DNA;
    DNA.reserve(S.size());
    for (const auto& nucleotide : S)
    {
        DNA.push_back(nucleotidesImpact[nucleotide]);
    }

    std::vector<std::vector<int>> factorsAmount(DNA.size(), std::vector<int>(4));
    std::vector<int> firstFactor(4);
    firstFactor[DNA[0]]++;
    factorsAmount[0] = firstFactor;

    for (size_t i = 1; i < DNA.size(); i++)
    {
        factorsAmount[i] = factorsAmount[i - 1];
        factorsAmount[i][DNA[i]]++;
    }

    std::vector<int> result(P.size());
    for (size_t i = 0; i < result.size(); i++)
    {
        if (P[i] > Q[i] || P[i] < 0 || Q[i] >= static_cast<int64_t>(S.size()))
        {
            continue;
        }

        const auto left = (P[i] - 1 >= 0) ? factorsAmount[P[i] - 1] : std::vector<int>(4);
        const auto right = factorsAmount[Q[i]];

        for (size_t j = 0; j < left.size(); j++)
        {
            if (right[j] > left[j])
            {
                result[i] = j + 1;
                break;
            }
        }
    }

    return result;
}

int main()
{
    assert(std::vector<int>({ 0, 0, 0, 1, 2, 4, 1 }) == solution(std::string("CAGCCTA"), std::vector<int>({ -1, 0, 5, 1, 2, 5, 0 }), std::vector<int>({ 6, 7, 4, 1, 4, 5, 6 })));
    assert(std::vector<int>({ 2, 1, 2 }) == solution(std::string(1000, 'C') + 'A' + std::string(1000, 'C'), std::vector<int>({ 0, 0, 1001 }), std::vector<int>({ 999, 2000, 2000 })));
}
