#include "definition.cpp"
#include <iostream>

class Solution {
public:
    TreeNode * travelSal(vector<int> &inorder, vector<int> &postorder) {
        // 处理结束条件
        if (postorder.size() == 0) {
            return NULL;
        }
        // 得到后序的最后一个节点
        int val = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(val);

        // 判断是否只有一个节点
        if (postorder.size() == 1) {
            return root;
        }

        int delimiter;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                delimiter = i;
                break;
            }
        }
        // 遵循左开右闭的原则
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + delimiter);
        vector<int> rightInOrder(inorder.begin() + delimiter + 1, inorder.end()); // 去除中间元素
        postorder.resize(postorder.size() - 1);
        // 得到左右中序和后序
        vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftInOrder.size());
        vector<int> rightPostOrder(postorder.begin() + leftInOrder.size(), postorder.end());

        root->left = travelSal(leftInOrder, leftPostOrder);
        root->right = travelSal(rightInOrder, rightPostOrder);
    }
        // 无需定义新数组的方法
        // 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin, postorderEnd)
    TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return NULL;

        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);

        if (postorderEnd - postorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割后序数组
        // 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
        int leftPostorderBegin =  postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
        // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,  postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }

    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        return travelSal(inorder, postorder);
    }
};