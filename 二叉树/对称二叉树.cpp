#include "definition.cpp"
#include <iostream>

class Solution {
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right != NULL) {
            return false;
        }
        else if (left != NULL && right == NULL) {
            return false;
        }
        else if (left == NULL && right == NULL) {
            return true;
        }
        else if (left->val != right->val) {
            return false;
        }
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside && inside;
        return result;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        bool result = compare(root->left, root->right);
    }
};