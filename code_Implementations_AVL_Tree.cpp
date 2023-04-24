#include <iostream>
using namespace std;
class AVL
{
public:
    int data;
    AVL *leftside;
    AVL *rightside;
    int height;
};
int height(AVL *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}
int max(int x, int y)
{
    // if (x > y)
    //     return x;
    // else
    //     return y;
    return x > y ? x : y; // ternary operator
}
AVL *CreateNode(int data)
{
    AVL *newNode = new AVL();
    newNode->data = data;
    newNode->leftside = NULL;
    newNode->rightside = NULL;
    newNode->height = 1;
    return newNode;
}
int getBalanceFactor(AVL *node)
{
    if (node == NULL)
        return 0;
    return height(node->leftside) - height(node->rightside);
}
AVL *RightRotation(AVL *y)
{
    // Bfore Rotation
    AVL *x = y->leftside;
    AVL *xrchild = x->rightside;
    // After rotation
    x->rightside = y;
    y->leftside = xrchild;

    y->height = max(height(y->leftside), height(y->rightside)) + 1;
    x->height = max(height(x->leftside), height(x->rightside)) + 1;
    return x;
}
AVL *leftRotation(AVL *x)
{
    // Before Rotation
    AVL *y = x->rightside;
    AVL *ylchild = y->leftside;
    // After Rotation
    y->leftside = x;
    x->rightside = ylchild;
    x->height = max(height(x->leftside), height(x->rightside)) + 1;
    y->height = max(height(y->leftside), height(y->rightside)) + 1;
    return y;
}
AVL *InsertNode(AVL *node, int data)
{
    // First we will generate binary tree
    //  creating first node
    if (node == NULL)
        return CreateNode(data);
    if (data < node->data)
        node->leftside = InsertNode(node->leftside, data);
    else if (data > node->data)
        node->rightside = InsertNode(node->rightside, data);
    else
        return node;
    node->height = max(height(node->leftside), height(node->rightside)) + 1;
    int bFactor = getBalanceFactor(node);
    if (bFactor > 1)
    {
        if (data < node->leftside->data)
            return RightRotation(node);
        else if (data > node->leftside->data)
        {
            node->leftside = leftRotation(node->leftside);
            return RightRotation(node);
        }
    }
    if (bFactor < -1)
    {
        if (data > node->rightside->data)
            return leftRotation(node);
        else if (data < node->rightside->data)
        {
            node->rightside = RightRotation(node->rightside);
            return leftRotation(node);
        }
    }
    return node;
}
void preorder(AVL *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorder(node->leftside);
        preorder(node->rightside);
    }
}
void inorder(AVL *node)
{
    if (node != NULL)
    {
        inorder(node->leftside);
        cout << node->data << " ";
        inorder(node->rightside);
    }
}
void postorder(AVL *node)
{
    if (node != NULL)
    {
        postorder(node->leftside);
        postorder(node->rightside);
        cout << node->data << " ";
    }
}

int main()
{
    AVL *node = NULL;
    node = InsertNode(node, 6);
    node = InsertNode(node, 150);
    node = InsertNode(node, 129);
    node = InsertNode(node, 210);
    node = InsertNode(node, 121);
    node = InsertNode(node, 110);
    node = InsertNode(node, 25);
    node = InsertNode(node, 90);
    node = InsertNode(node, 100);
    node = InsertNode(node, 120);
    node = InsertNode(node, 140);
    node = InsertNode(node, 170);
    node = InsertNode(node, 190);
    node = InsertNode(node, 185);
    cout << "\n-----------Preorder-----------------\n";
    preorder(node);
    cout << "\n-----------Inorder-----------------\n";
    inorder(node);
    cout << "\n-----------postrder-----------------\n";
    postorder(node);
}
