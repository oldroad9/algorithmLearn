#include "definition.cpp"
#include <climits>
#include <vector>

class Solution {
private:
    int result = INT_MAX;
    TreeNode *pre = NULL;
    // 直接遍历的时候计算
    void traversal2(TreeNode *cur)
    {
        if (cur == NULL)
            return;
        traversal2(cur->left); // 左
        if (pre != NULL) {     // 中
            result = min(result, cur->val - pre->val);
        }
        pre = cur;              // 记录前一个
        traversal2(cur->right); // 右
    }

    vector<int> vec;
    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        traversal(root->left);
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        vec.clear();
        traversal(root);
        if (vec.size() < 2)
            return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) { // 统计有序数组的最小差值
            result = min(result, vec[i] - vec[i - 1]);
        }
        return result;
    }

    int getMinimumDifference2(TreeNode *root)
    {
        traversal2(root);
        return result;
    }
};
