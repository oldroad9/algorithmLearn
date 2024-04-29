#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        for (int i = 0; i <=n; i++) {
            cout << dp[i]<< " ";
        }
        return dp[n];
    } 
};

int main() {
    Solution s;
    s.numTrees(3);
}