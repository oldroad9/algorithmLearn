#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 将石头分割为 两部分重量相等
        int weightSum = 0;
        for (int i = 0; i < stones.size(); i++) {
            weightSum += stones[i];
        }
        int target = weightSum / 2;
        vector<int> dp(15001, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return weightSum - dp[target] - dp[target];
    }
};