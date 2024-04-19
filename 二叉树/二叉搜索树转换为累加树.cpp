#include "definition.cpp"
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> path;
    TreeNode* convertBST2(TreeNode* root) {
        travelSal(root);
        for (int i = path.size() - 2; i >= 0; i--) {
            path[i] += path[i + 1];
        }
        int index = 0;
        travelSalRefresh(root, index);
        return root;
    }
    void travelSal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        travelSal(node->left);
        path.push_back(node->val);
        travelSal(node->right);
    }
    void travelSalRefresh(TreeNode *node, int &index) {
        if (node == nullptr) {
            return;
        }
        travelSalRefresh(node->left, index);
        node->val = path[index++];
        travelSalRefresh(node->right, index);
    }

    // 利用递归的方式，反中序遍历
    int pre = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == NULL) {
            return NULL;
        }
        convertBST(root->right);
        root->val += pre;
        pre = root->val;
        convertBST(root->left);
        return root;
    }
};