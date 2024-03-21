#include <iostream>
#include <vector>

using namespace std;

// 删除对应元素，并返回删除后的大小
class Solution
{
public:
    static int removeElement(vector<int> &nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == val)
            {
                for (int j = i; j < size - 1; ++j)
                {
                    nums[j] = nums[j + 1];
                }
                i--;
                size--;
            }
        }
        return size;
    }
    // 双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
    static int removeElement2(vector<int> &nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex])
            {
                nums[slowIndex++] = nums[fastIndex];
                // nums[slowIndex] = nums[fastIndex];
                // slowIndex++;
            }
        } // 快指针类似于寻找新数组中的元素，若是相同则不是寻找的目标
        return slowIndex;
    }
};

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
    // 原来元素数目为10
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }
    PrintVector(nums);
    int result = Solution::removeElement(nums, 3);
    PrintVector(nums);
    std::cout << result << std::endl;
    result = Solution::removeElement(nums, 4);
    PrintVector(nums);
    std::cout << result << std::endl;
}