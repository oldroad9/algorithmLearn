#include <iostream>
#include "definition.cpp"

using namespace std;

class Solution {
public:
	int getdepth(TreeNode *node){
		if (node == NULL) {return 0;}
		int leftdepth = getdepth(node->left);
		int rightdepth = getdepth(node->right);
		int depth = 1 + max(leftdepth,rightdepth);
		return depth;
	}
	int maxDepth(TreeNode *root){
		int depth = getdepth(root);
		return depth;
	}
};
