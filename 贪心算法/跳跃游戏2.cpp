#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
    int ans = 0;
    int start = 0;
    int end = 1;
    while (end < nums.size()) {
        int maxPos = 0;
        for (int i = start; i < end; i++) {
            // 能跳到最远的距离
            maxPos = max(maxPos, i + nums[i]);
        }
        start = end;      // 下一次起跳点范围开始的格子
        end = maxPos + 1; // 下一次起跳点范围结束的格子
        ans++;            // 跳跃次数
    }
    return ans;
}

class Solution {
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int curDistance = 0;  // 当前覆盖最远距离下标
        int ans = 0;          // 记录走的最大步数
        int nextDistance = 0; // 下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖最远距离下标
            if (i == curDistance) {                        // 遇到当前覆盖最远距离下标
                ans++;                                     // 需要走下一步
                curDistance = nextDistance;                // 更新当前覆盖最远距离下标（相当于加油了）
                if (nextDistance >= nums.size() - 1)
                    break; // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
            }
        }
        return ans;
    }
};

int main()
{
}