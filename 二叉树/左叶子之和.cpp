#include <iostream>
#include <vector>
#include "definition.cpp"

using namespace std;

class Solution{
public:
    int sumofLeftleaves(TreeNode *root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL){
            return 0;   
        }
        int leftvalue = sumofLeftleaves(root->left);

        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            leftvalue = root->left->val;
        }
        int rightvalue = sumofLeftleaves(root->right);

        int sum = leftvalue + rightvalue;
        return sum;
    }
};