#include <vector>

using namespace std;

class Solution {
public:
    // 暴力搜索法
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            for (int j = i; j < nums.size(); j++) {
                count += nums[j];
                if (count > result) {
                    result = count;
                }
            }
        }
        return result;
    }
    // 采用贪心算法
    int maxSubArray(vector<int> &nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) {
                result = count;
            }
            if (count < 0) {
                count = 0;
            }
        }
        return result;
    }
};