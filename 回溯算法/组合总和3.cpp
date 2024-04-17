#include <vector>
#include <iostream>

using namespace std;

class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int sum, int startIndex)
    {
        if (sum > n) // 进行减枝操作
            return;
        if (path.size() == k) {
            if (sum == n) {
                result.push_back(path);
            }
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtracking(n, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 0, 1);
        return result;
    }
};


int main() {
    Solution s;
    auto result = s.combine(9, 3);
    for (auto it = result.begin(); it != result.end();it++) {
        for (auto ite = (*it).begin(); ite != (*it).end(); ite++){
            cout << (*ite) << " ";
        }
        cout << endl;
    }
}