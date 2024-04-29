#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
    vector<vector<int>> threeSum(vector<int> nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 相等的时候去重
                    while (left < right && (nums[left] == nums[left + 1]))
                    {
                        left++;
                    }
                    while (left < right && (nums[right] == nums[right - 1]))
                    {
                        right--;
                    }
                    // 找到答案时，双指针同时收缩,依然可能有满足条件的
                    left++;
                    right--;
                }
            }
        }
    }
};