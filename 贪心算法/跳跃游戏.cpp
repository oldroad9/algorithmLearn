#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        if (nums.size() == 1)
            return true;                   // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true; // 说明可以覆盖到终点了
        }
        return false;
    }
    // own
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int maxScope = nums[0];
        int startIndex = 0;
        while (startIndex <= maxScope) {
            if (maxScope >= nums.size() - 1) {
                return true;
            }
            for (int i = startIndex; i <= startIndex + nums[startIndex]; i++) {
                if (i + nums[i] > maxScope) {
                    maxScope = i + nums[i];
                }
            }
            startIndex++;
        }
        return false;
    }
};