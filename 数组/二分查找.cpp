#include <iostream>
#include <vector>

// 数组不重复 采用二分法进行 计算

class Solution
{
public:
    // using namespace std;
    static int search(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }

    static int search2(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right)
        {                                              // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1); // 右移 / 2
            if (nums[middle] > target)
            {
                right = middle; // target 在左区间，在[left, middle)中
            }
            else if (nums[middle] < target)
            {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            }
            else
            {                  // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }

}; // 时间复杂度 O(logn)

void PrintVector(std::vector<int> &v)
{
    // for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
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
        nums.push_back(i);
    }
    PrintVector(nums);
    int result = Solution::search(nums, 3);
    std::cout << result << std::endl;
    result = Solution::search2(nums, 4);
    std::cout << result << std::endl;
}