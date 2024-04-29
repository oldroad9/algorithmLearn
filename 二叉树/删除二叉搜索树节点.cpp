#include "definition.cpp"


class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            // 分为五种情况
            // 情况1 左右都为空
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            // 情况2 左为空, 右不为空
            else if (root->left == nullptr && root->right != nullptr) {
                return root->right;
            }
            else if (root->right == nullptr && root->left != nullptr) {
                return root->left;
            }
            else {
                TreeNode *cur = root->right;
                while(cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};