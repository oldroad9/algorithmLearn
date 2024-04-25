#include <vector>

using namespace std;

/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
*/

class Solution {
public:
    int integerBreak(int n) {
        // 将 dp 数组设置为 第 i 个数据的最大 乘积和
        // int dp[n + 1]; // int dp 会报错
        vector<int> dp(n+1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};