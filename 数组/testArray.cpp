#include <iostream>
#include <vector>
// #include "有序数组平方.cpp"
// #include "长度最小数组.cpp"
#include "螺旋矩阵.cpp"

void PrintVector(std::vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    // 使用 auto 自动判断数据类型
    std::cout << std::endl;
}

void PrintMatrix(std::vector<std::vector<int>> &v)
{
    for (std::vector<std::vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (auto ite = (*it).begin(); ite != (*it).end(); ite++)
        {
            std::cout << *ite << " ";
        }
        std::cout << std::endl;
        // std::cout << *it << " ";
    }
    // 使用 auto 自动判断数据类型
    std::cout << std::endl;
}

// int test01(std::vector<int> nums)
// {
//     int result = Solution::minSubArrayLen(nums, 4);
//     std::cout << "测试数字为 " << 4 << std::endl;
//     std::cout << result << std::endl;
//     return 0;
// }

void test02()
{
    int i = 10;
    auto matrix = Solution::generateMatrix(i);
    PrintMatrix(matrix);
}

int main()
{
    std::vector<int> nums;
    // for (int i = 0; i < 10; i++)
    // {
    //     nums.push_back(i);
    // }
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(2);
    // PrintVector(nums);
    // test01(nums);
    test02();
}