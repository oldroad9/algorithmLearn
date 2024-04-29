#include <queue>
#include "definition.cpp"

class Solution{
public:
    int findBottomleftValue(TreeNode *root) {
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int result = que.front()->val;
            bool isBottom = true;
            for (int i = 0; i < que.size(); i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                    isBottom = false;
                }
                if (node->right) {
                    que.push(node->right);
                    isBottom = false;
                }
            }
            if (isBottom)
                return result;
        }
    }
};