#include <iostream>
#include "definition.cpp"

class Solution{
public:
    TreeNode * constructMaxBinaryTree(vector<int> &nums) {
        // 终止条件为：
        TreeNode *node = new TreeNode(0);
        if (nums.size() == 1){
            node->val = nums[0];
            return node;
        }
        int maxValue = 0;
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        node->val = maxValue;
        if (maxIndex > 0){
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        node->left = constructMaxBinaryTree(leftNums);
        }
        if (maxIndex < nums.size() - 1){
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
        node->right = constructMaxBinaryTree(rightNums);
        }
        return node;
    }
    // 利用原数组进行操作
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        // 分割点下标：maxValueIndex
        int maxValueIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        // 左闭右开：[left, maxValueIndex)
        root->left = traversal(nums, left, maxValueIndex);

        // 左闭右开：[maxValueIndex + 1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
};