#include <unordered_map>
#include "definition.cpp"
#include <algorithm>

class Solution {
public:
    unordered_map<int,int> m;
    vector<int> findMode(TreeNode* root) {
        travelSal(root);
        vector<int> result;
        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), cmp);
        result.push_back(vec[0].first);
        // 要从 1 开始
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) {
                result.push_back(vec[i].first);
            }
            else continue;
        }
        return result;
    }
    // 不加 static 会报错, 要转换为静态方法
    bool static cmp(pair<int,int> &p1, pair<int, int> &p2){
        if (p1.second > p2.second) {
            return true;
        }
        else
            return false;
    }
    void travelSal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        travelSal(node->left);
        m[node->val]++;
        travelSal(node->right);
    }
    // 方法二 由于为二叉搜索树 转换为中序遍历 -> 有序数组求众数的方式

    int maxCount = 0;
    int count = 0;
    TreeNode *pre = nullptr;
    vector<int> result;
    void travelSal2(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        travelSal2(node->left);
        if (pre == nullptr) {
            count = 1;
        }
        else if (pre->val == node->val) {
            count++;
        }
        else
            count = 1;
        if (count == maxCount) {
            result.push_back(node->val);
        }
        pre = node; // 很重要
        if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(node->val);
        }
        travelSal(node->right);
        return;
    }
};
