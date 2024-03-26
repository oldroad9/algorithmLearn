#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > target && target >= 0)
            {
                break;
            }
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++)
            {
                if (nums[k] + nums[i] > target && target >= 0)
                {
                    break;
                }
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int left = i + 1;
                int right = nums.size();
                while (left < right)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && (nums[left] == nums[left + 1]))
                        {
                            left++;
                        }
                        while (left < right && (nums[right] == nums[right - 1]))
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};