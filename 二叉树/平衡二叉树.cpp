#include "definition.cpp"
#include <iostream>

class Solution {
public:
    int getHeight(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftheight = getHeight(node->left);
        if (leftheight == -1)
            return -1;
        int rightheight = getHeight(node->right);
        if (rightheight == -1)
            return -1;
        if (abs(leftheight - rightheight) > -1)
            return -1;
        else
            return 1 + max(leftheight, rightheight);
    }
    
    bool isBalanceTree(TreeNode *root) {
        if (getHeight(root) == -1)
            return false;
        else
            return true;
    }
};
