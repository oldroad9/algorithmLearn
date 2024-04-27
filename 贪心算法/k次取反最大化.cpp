#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 分为两个阶段
        // 第一阶段，找到负数
        sort(nums.begin(), nums.end());
        // 从小到大排序
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
                if (k <= 0) {
                    return getSum(nums);
                }
            }
        }
        sort(nums.begin(), nums.end());
        if (k % 2 == 0) {
            return getSum(nums);
        }
        else {
            nums[0] = -nums[0];
            return getSum(nums);
        }
    }

    int getSum(vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += nums[i];
        }
        return result;
    }
};