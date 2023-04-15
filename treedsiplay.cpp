#include <iostream>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

void display(TreeNode *root, int level)
{
    if (root == nullptr)
    {
        return;
    }

    // display right subtree
    display(root->right, level + 1);

    // display current node
    for (int i = 0; i < level; i++)
    {
        cout << "  ";
    }
    cout << root->val << endl;

    // display left subtree
    display(root->left, level + 1);
}

int main()
{
    // create tree
    TreeNode *root = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    // root->left = node2;
    // root->right = node3;
    // node2->left = node4;
    // node2->right = node5;
    // node3->left = node6;
    // node3->right = node7;

    // display tree
    display(root, 0);

    return 0;
}
