#include <assert.h>
#include <algorithm>
#include <vector>

int solution(std::vector<int> &A)
{
    int passingCarsNum = 0;
    int eastDrivingCars = 0;

    for (const auto& car : A)
    {
        if (0 == car)
        {
            eastDrivingCars++;
        }
        else if (1 == car)
        {
            passingCarsNum += eastDrivingCars;
        }

        if (passingCarsNum > 1000000000)
        {
            return -1;
        }
    }

    return passingCarsNum;
}

int main()
{
    assert(0 == solution(std::vector<int>({ 1, 0 })));
    assert(0 == solution(std::vector<int>({ 0, 2 })));
    assert(1 == solution(std::vector<int>({ 0, 1 })));
    assert(9 == solution(std::vector<int>({ 0, 0, 0, 1, 1, 1 })));
    assert(5 == solution(std::vector<int>({ 0, 1, 0, 1, 1 })));

    std::vector<int> stressTestArr(110000, 0);
    std::for_each(stressTestArr.begin() + 100000, stressTestArr.end(), [](int& val) { val = 1; });
    assert(1000000000 == solution(stressTestArr));

    stressTestArr.push_back(1);
    assert(-1 == solution(stressTestArr));
}

