#include <vector>

using namespace std;

class Solution {
public:
  // 动态规划方法
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(5, 0));
    // 设置为五个状态，分别为
    // 无操作、第一次买入、第一次不持有、第二次买入、第二次不持有
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < len; i++) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
      // 在第一次不持有的基础上再买入第二次
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[len - 1][4];
  }
};
