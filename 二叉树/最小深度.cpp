#include "definition.cpp"
#include <iostream>

using namespace std;

class Solution{
	int getMindepth(TreeNode *root) {
			getdepth(root);	
	}

	int getdepth (TreeNode *node) {
		if (node == NULL) return 0;
		int leftdepth = getdepth(node->left);
		int rightdepth = getdepth(node->right);
		// 左右都为空，但自身节点不为空，则为最小深度节点。
		if (node->left == NULL && node->right != NULL) {
			return rightdepth + 1;		
		}
		if (node->left != NULL && node -> right == NULL) {
			return leftdepth + 1;	
		}
		// 获取左右节点的最小深度
		int result = min(leftdepth,rightdepth);
		return result;
	}
};
