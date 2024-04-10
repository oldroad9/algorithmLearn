#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        // for (int i = startindex; i <= n - (k - path.size()) + 1; i++) 进行减枝
        for (int i = startindex; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution s;
    auto result = s.combine(4, 2);
    for (auto it = result.begin(); it != result.end();it++) {
        for (auto ite = (*it).begin(); ite != (*it).end(); ite++){
            cout << (*ite) << " ";
        }
        cout << endl;
    }
}