#include <vector>

using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    vector<int> dp(nums.size(), 1);
    int result = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        dp[i] = dp[i - 1] + 1;
      }
      if (dp[i] > result) {
        result = dp[i];
      }
    }
    return result;
  }
};
