#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    vector<int> dp(nums.size(), 0);
    // dp [i] 的含义为： 以i为 结尾的子序列和 最大值
    // 最后遍历得到 每一个结尾的最大值 ，得到整个数组的最大值
    dp[0] = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
      result = max(result, dp[i]);
    }
    return result;
  }
};
