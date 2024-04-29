#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(i);
            backtracking(candidates, target, sum, i); // 不用 +1 允许有重复元素
            sum -= candidates[i];
            path.pop_back();
        }
    }
private:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};