#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(nums, 0, used);
        return result;
    }

    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums,int startIndex, vector<bool> &used) {
        result.push_back(path);
        if (startIndex == nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            // used[i - 1] = false 确保横向循环时，去除重复元素
            if (i > 0 && nums[i] == nums[i-1] && used[i-1]== false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    // 方法 2
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > startIndex && nums[i] == nums[i - 1] ) { // 注意这里使用i > startIndex
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};