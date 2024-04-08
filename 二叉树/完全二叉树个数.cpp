#include <iostream>
#include <queue>
#include "definition.cpp"

using namespace std;

class Solution{
    int countNodeNums(TreeNode *root){
        // 采用层次遍历的方式
        queue<TreeNode *> que;
        if (root != NULL)
            que.push(root);
        int count = 0;
        while (!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                count++;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return count;
    }

    // 采用迭代法计算
    int countNodes (TreeNode *root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

	int countNodes2 (TreeNode *root) {
		if (root == NULL) return 0;
		TreeNode *left = root->left;
		TreeNode *right = root->right;
		int leftdepth = 0;
		int rightdepth = 0;
		while (left) {
			leftdepth++;
			left = left->left;
		}

		while (right) {
			rightdepth++;
			right = right->right;
		}

		if (leftdepth == rightdepth) {
			return (2 << leftdepth - 1);
		} // 左移类似于 2^leftdepth 

		return countNode2(root->left) + countNode2(root->right) + 1;
	}
};
