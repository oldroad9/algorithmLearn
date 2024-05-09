#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = __INT_MAX__;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            result = max(result, prices[i] - low);
        }
        return result;
    }
    // 动态规划方法
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2,0));
        dp[0][0] = -prices[0]; // 持有股票的最大价值
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }

};
