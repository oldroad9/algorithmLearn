#include "definition.cpp"


class Solution {
public:
    // 修改 t1 的结构, 采用递归的方法
    TreeNode *mergeTree(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTree(t1->left, t2->left);
        t1->right = mergeTree(t1->right, t2->right);
        return t1;
    }
};