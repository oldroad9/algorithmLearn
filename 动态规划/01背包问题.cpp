#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void bagProblem(vector<int> weight, vector<int> value, int bagweight)
    {
        vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
        // 从weight[0] 开始，小于 weight[0] 的都为 0
        // 初始化 dp 列表
        for (int j = weight[0]; j <= bagweight; j++) {
            dp[0][j] = value[0];
        }

        for (int i = 1; i < weight.size(); i++) {
            for (int j = 0; j <= bagweight; j++) {
                // 剪枝， 当容量小于 i 物品的质量时
                if (j < weight[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        cout << dp[weight.size() - 1][bagweight] << endl;
        for (auto it = dp.begin(); it != dp.end(); it++) {
            for (auto ite = it->begin(); ite != it->end(); ite++) {
                cout << *ite << " ";
            }
            cout << endl;
        }
    }
    // 一维数组实现
    void test_1_wei_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}
};

int main() {
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bagweight = 4;
    Solution s;
    s.bagProblem(weight, value, bagweight);
}