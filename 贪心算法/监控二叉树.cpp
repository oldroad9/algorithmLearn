#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        // 设计最小监控数量
        // 采用后序遍历 从子节点出发 其中空节点 认为 有覆盖的状态
        if (travelSal(root) == 0) {
            result++;
        }
        return result;
    }
    int result;
    int travelSal(TreeNode* cur) {
        if (cur == NULL) {
            return 2;
        }
        int left = travelSal(cur->left);
        int right = travelSal(cur->right);
        if (left == 2 && right == 2) {
            return 0;
        }
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
};