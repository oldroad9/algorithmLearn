#include "definition.cpp"
#include <iostream>

class Solution {
public:
    bool travelSal(TreeNode *cur, int count) {
        if (cur->left == NULL && cur->right == NULL && count == 0) {
            return true;
        }
        if (cur->left == NULL && cur->right == NULL) {
            return false;
        }

        if (cur->left) {
            count -= cur->left->val;
            if (travelSal(cur->left, count))
                return true;
            count += cur->left->val;
        }
        if (cur->right) {
            count -= cur->right->val;
            if (travelSal(cur->right, count))
                return true;
            count += cur->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int count) {
        if (root == NULL)
            return false;
        return travelSal(root, count - root->val);
    }
};