#include <iostream>
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
}