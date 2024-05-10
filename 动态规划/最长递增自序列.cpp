#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    // 设置dp数组的含义为 第i个长度的最大子序列长度
    if (nums.size() <= 1)
      return nums.size();
    vector<int> dp(nums.size(), 1); // 初始全部为1
    dp[0] = 1;
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      if (dp[i] > result) {
        result = dp[i];
      }
    }
    return result;
  }
};
