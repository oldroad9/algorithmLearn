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
}; // 时间复杂度 O(logn)

void PrintVector(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
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
}