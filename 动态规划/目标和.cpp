#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class solution {
public:
    int findtargetsumways(vector<int> &nums, int target)
    {
        // 寻找求和等于目标和的 方式
        // 转换为 求 = (sum + target) / 2 的方式有多少种
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum < target) {
            return 0;
        }
        if ((sum + target) % 2 != 0) {
            return 0;
        }
        int bagsize = (sum + target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(bagsize + 1, 0));
        for (int j = 0; j < bagsize + 1; j++) {
            if (nums[0] == j) {
                dp[0][j] = 1;
            }
        }
        int numsZeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                numsZeros++;
            }
            dp[i][0] = pow(2, numsZeros);
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < bagsize + 1; j++) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            }
        }

        for (auto it = dp.begin(); it != dp.end(); it++) {
            for (auto ite = it->begin(); ite != it->end(); ite++) {
                cout << *ite << " ";
            }
            cout << endl;
        }

        return dp[nums.size() - 1][bagsize];
    }

    int findTargetSumWays2(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int &num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size(), neg = (target + sum) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        for (auto it = dp.begin(); it != dp.end(); it++) {
            for (auto ite = it->begin(); ite != it->end(); ite++) {
                cout << *ite << " ";
            }
            cout << endl;
        }
        return dp[n][neg];
    }
};

int main()
{
    vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;
    solution s;
    auto result = s.findTargetSumWays2(nums, target);
    s.findtargetsumways(nums, target);
    cout << result << endl;
}