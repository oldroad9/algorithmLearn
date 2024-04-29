#include<vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2) {
            return result;  
        }
        backtracking(nums, 0);
    }
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums,int startIndex) {
        if (path.size() > 1)
            result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) ||
                uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};