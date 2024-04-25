#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        /*
        F(0) = 0，F(1) = 1
        F(n) = F(n - 1) + F(n - 2)，其中 n > 1
        */
        int dp[n];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};