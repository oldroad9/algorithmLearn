#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    static int minSubArrayLen(vector<int> &nums, int s)
    {
        // 求取连续数组 都大于等于s的最小数组
        int pointerS = 0;
        int pointerF = 0;
        int minLength = nums.size();
        int record = 0; // 记录滑动数组的长度
        int recordL = 0;
        // vector<int> numsNew(nums.size(), 0);
        for (; pointerF < nums.size(); pointerF++)
        {
            if (nums[pointerF] < s)
            {
                pointerS = pointerF;
                record = 0;
            }
            else
            {
                record++;
            }
            if (record >= recordL)
            {
                // 此时记录的值还在变大
            }
            else
            {
                // 此时记录的值还在变0 ，上一个值则为记录最大长度
                if (recordL < minLength)
                {
                    minLength = recordL;
                }
            }
            recordL = record;
        }
        return minLength;
    }
    static int minSubArrayLen2(vector<int> &nums, int s)
    {
        int result = INT32_MAX;
        int sum = 0;       // 滑动窗口数值之和
        int i = 0;         // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s)
            {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};