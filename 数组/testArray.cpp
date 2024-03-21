#include <iostream>
#include <vector>
#include "有序数组平方.cpp"

void PrintVector(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    // 使用 auto 自动判断数据类型
    std::cout << std::endl;
}

int main()
{
    std::vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(3 - i);
    }
    PrintVector(nums);
    auto result = Solution::sortedSquares2(nums);
    PrintVector(result);
}