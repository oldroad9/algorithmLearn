#include "definition.cpp"


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return travelSal(nums, 0, nums.size() - 1);
        // 左闭右闭 nums.size() - 1
    }
    TreeNode *travelSal(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        // 为 > , start = end 代表一种情况， 还有一个数，依然创建
        int middle = (start - end) / 2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = travelSal(nums, start, middle - 1);
        root->right = travelSal(nums, middle + 1, end);
        return root;
    }
};