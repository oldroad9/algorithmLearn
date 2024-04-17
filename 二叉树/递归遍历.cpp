#include "definition.cpp"
#include <vector>

using namespace std;

class Solution {
public:
    void travelSal(TreeNode *cur, vector<int> &result)
    {
        if (cur == NULL)
            return;
        result.push_back(cur->val);    // 中
        travelSal(cur->left, result);  // 左
        travelSal(cur->right, result); // 右
    }

    vector<int> preorderTravelsal(TreeNode *root)
    {
        vector<int> result;
        travelSal(root, result);
        return result;
    }
};