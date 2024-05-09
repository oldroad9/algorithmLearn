#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    int rob_(TreeNode* root) {
        // 暴力递归法
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        // 跳过根节点
        int val1 = root->val;
        if (root->left)
            val1 += rob_(root->left->left) + rob_(root->left->right);
        if (root->right)
            val1 += rob_(root->right->left) + rob_(root->right->right);
        // 不偷父节点
        int val2 = rob_(root->left) + rob_(root->right);
        return max(val1, val2);
    }

    // 记忆化递推
    unordered_map<TreeNode *, int> map;
    int rob(TreeNode *root)
    {
        // 暴力递归法
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if (map[root])
            return map[root];
        // 跳过根节点
        int val1 = root->val;
        if (root->left)
            val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            val1 += rob(root->right->left) + rob(root->right->right);
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right);
        map[root] = max(val1, val2);
        return max(val1, val2);
    }

    int rob_dp(TreeNode *root) {
        auto result = robTree(root);
        return max(result[0], result[1]);
    }
    // 返回的为 Dp 数组 记录偷与不偷的最大值
    vector<int> robTree(TreeNode *cur) {
        if (cur == nullptr) {
            return vector<int>{0, 0};
        }
        // 采用后续遍历
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        int val1 = cur->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{val1, val2};
    }
};