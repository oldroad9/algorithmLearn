#include "definition.cpp"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 标记法处理节点
class Solution {
public:
    // 中序遍历
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL)
            st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right)
                    st.push(node->right); // 空节点不入栈

                st.push(node);
                st.push(NULL); // 根节点还未处理，标记为NULL

                if (node->left)
                    st.push(node->left);
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};
