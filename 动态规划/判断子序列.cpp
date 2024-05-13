#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    // 判断 s 是否为 t 的子串
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int j = 1; j <= t.size(); j++) {
      for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == t[j - 1]) {
          cout << " is same" << endl;
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        cout << dp[i][j] << " " << i << " " << j << endl;
        if (dp[i][j] == s.size()) {
          return true;
        }
      }
    }
    for (auto it = dp.begin(); it != dp.end(); it++) {
      for (auto ite = it->begin(); ite != it->end(); ite++) {
        cout << *ite << " ";
      }
      cout << endl;
    }
    return false;
  }
};

int main() {
  string s = "bb";
  string t = "ahbgdc";
  Solution solution;
  solution.isSubsequence(s, t);
}
