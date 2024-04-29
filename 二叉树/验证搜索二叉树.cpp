#include "definition.cpp"
#include <iostream>

using namespace std;

// 使用递归法 前序遍历判断
// 错误 需要左子树全部都小于根
class Solution {
public:
    bool isValidBST(TreeNode *root)
    {
        vec.clear(); // 不加这句在leetcode上也可以过，但最好加上
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            // 注意要小于等于，搜索树里不能有相同元素
            if (vec[i] <= vec[i - 1])
                return false;
        }
        return true;
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

    TreeNode* pre = NULL; // 用来记录前一个节点
    bool isValidBST2(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST2(root->left);

        if (pre != NULL && pre->val >= root->val) return false;
        pre = root; // 记录前一个节点

        bool right = isValidBST2(root->right);
        return left && right;
    }
};