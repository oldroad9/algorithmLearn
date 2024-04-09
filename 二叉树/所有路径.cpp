#include <string>
#include <vector>
#include <iostream>
#include "definition.cpp"

class Solution{
public:
    vector<string> BinaryTreeAllpath(TreeNode *root)
    {
        vector<string> result;
        vector<int> path;
        if (root == NULL)
            return result;
    }

    void travelSal(TreeNode *cur, vector<int> &path, vector<string> &result)
    {
        path.push_back(cur->val); // 插入最后一个节点的值
        if (cur->left == NULL && cur->right == NULL) {
            string spath;
            for (size_t i = 0; i < path.size() - 1; i++) {
                spath += to_string(path[i]);
                spath += "->";
            }

            spath += path[path.size() - 1];
            result.push_back(spath);
            return;
        }

        if (cur->left) {
            travelSal(cur->left, path, result);
            path.pop_back();
        }

        if (cur->right) {
            travelSal(cur->right, path, result);
            path.pop_back();
        }
    }
};