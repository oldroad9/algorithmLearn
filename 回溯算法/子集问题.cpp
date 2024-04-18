#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, int startIndex){
        result.push_back(path); // 放在最前面
        if (startIndex == nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};