#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <class T>
class BinaryTree {
public:
    struct myTreeNode {
        T val;
        myTreeNode *left;
        myTreeNode *right;
        myTreeNode(T x) : val(x), left(NULL), right(NULL) {}
    };

    void createTree(vector<T> &s)
    {
        _creat(root, s);
    }

    void preorderPrint()
    {
        preorderTravelsal(root); // 前序遍历打印
        cout << endl;
        inorderTravelsal(root); // 中序遍历打印
        cout << endl;
        postorderTravelsal(root); // 后序遍历打印
        cout << endl;
    }

    vector<vector<T>> levelOrder()
    {
        queue<myTreeNode *> que;
        if (root != NULL)
            que.push(root);
        vector<vector<T>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<T> vec;
            // 要使用固定大小的size
            for (int i = 0; i < size; i++) {
                myTreeNode *node = que.front();
                que.pop(); // 依次pop()
                vec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(vec);
        }
        for (auto it = result.begin(); it != result.end(); it++) {
            for (auto ite = (*it).begin(); ite != (*it).end(); ite++) {
                cout << *ite << " ";
            }
        }
        return result;
    }

    vector<vector<T>> levelOrder2()
    {
        vector<vector<T>> result;
        int depth = 0;
        order(root, result, depth);
        for (auto it = result.begin(); it != result.end(); it++) {
            for (auto ite = (*it).begin(); ite != (*it).end(); ite++) {
                cout << *ite << " ";
            }
        }
        cout << endl;
        return result;
    }

    void order(myTreeNode *cur, vector<vector<T>> &result, int depth)
    {
        if (cur == NULL)
            return;
        if (result.size() == depth)
            result.push_back(vector<T>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }

    int minDepth()
    {
        if (root == NULL)
            return 0;
        int depth = 0;
        queue<myTreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                myTreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (!node->left && !node->right) {
                    return depth;
                }
            }
        }
        return depth;
    }

    void invert()
    {
        invertTree(root);
    }

    void invertTree(myTreeNode *node)
    {
        if (node == NULL) {
            return;
        }
        // 递归的写法 交换节点指针
        swap(node->left, node->right);
        invertTree(node->left);
        invertTree(node->right);
        return;
    }

    int getMindepth() {
		return getdepth(root);	
	}

	int getdepth (myTreeNode *node) {
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
		int result = 1 + min(leftdepth,rightdepth);
		return result;
	}

private:
    myTreeNode *root;

    void _creat(myTreeNode *&cur, vector<T> &s)
    {
        if (s.empty())
            return;
        if (s[0] == "#") {
            cur = NULL;
            s.erase(s.begin());
            return;
        }
        else {
            cur = new myTreeNode(s[0]);
        }
        s.erase(s.begin());
        _creat(cur->left, s);
        _creat(cur->right, s);
    }

    void preorderTravelsal(myTreeNode *cur)
    {
        if (cur == NULL)
            return;
        cout << cur->val << " ";
        preorderTravelsal(cur->left);
        preorderTravelsal(cur->right);
    }

    void inorderTravelsal(myTreeNode *cur)
    {
        if (cur == NULL)
            return;
        inorderTravelsal(cur->left);
        cout << cur->val << " ";
        inorderTravelsal(cur->right);
    }

    void postorderTravelsal(myTreeNode *cur)
    {
        if (cur == NULL)
            return;
        postorderTravelsal(cur->left);
        postorderTravelsal(cur->right);
        cout << cur->val << " ";
    }
};

int main()
{
    vector<string> s = {"A", "B", "C", "#", "#", "D", "E", "#",
                        "G", "#", "#", "F", "#", "#", "#"};
    BinaryTree<string> tree;
    tree.createTree(s);
    tree.preorderPrint();
    tree.levelOrder2();
    // tree.invert();
    tree.levelOrder2();
    int mindepth = tree.getMindepth();
    int mindepth2 = tree.minDepth();
    cout << mindepth << " "<< mindepth2 << endl;
}
