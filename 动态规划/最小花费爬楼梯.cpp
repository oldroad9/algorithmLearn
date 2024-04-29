#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size() + 1];
        dp[0] = 0; // dp[0] 代表的含义为到底第 0 个台阶的体力花费， 所以应为 0
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]);
        }
        return dp[cost.size()];
    }
};