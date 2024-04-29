#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 令被障碍阻挡的路径为 0 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        // 将dp 数组初始化为 第 i, j 下最短路径
        // 下面处理方式更简便 存在障碍，则停止赋值 1
        // for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        // for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
            if (obstacleGrid[i][0] == 1) {
                for (int j = i; j < m; j++) {
                    dp[j][0] = 0;
                }
                break;
            } 
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = 1;
            if (obstacleGrid[0][i] == 1) {
                for (int j = i; j < n; j++) {
                    dp[0][i] = 0;
                }
                break;
            } 
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (dp[i][j - 1] == 0 && dp[i - 1][j] == 0) {
                    dp[i][j] = 0;
                }
                // 以下可以进行简化
                if (dp[i][j - 1] == 0 && dp[i - 1][j] != 0) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (dp[i][j - 1] != 0 && dp[i - 1][j] == 0) {
                    dp[i][j] = dp[i][j - 1];
                }
                if (dp[i][j - 1] != 0 && dp[i - 1][j] != 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> obstacleGrid{{0, 1}, {0, 0}};
    s.uniquePathsWithObstacles(obstacleGrid);
}