#include <vector>

using namespace std;

class Solution {
public:
  // 动态规划方法
  int maxProfit(vector<int> &prices) {
    int len = prices.size();
    if (len == 0)
      return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] = -prices[0]; // 持有股票的最大价值
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
      // 由于可以多次买卖， 因此持有股票计算需要上一次的利润
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
  }
};
