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
    return height(node->leftside) - height(node->rightside); // left height - right height
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
AVL *predecessor(AVL *root)
{
    while (root && root->rightside != NULL)
        root = root->leftside;
    return root;
}
AVL *Succesor(AVL *root)
{
    while (root && root->leftside != NULL)
        root = root->rightside;
    return root;
}
AVL *deleteNode(AVL *root, int key)
{
    AVL *tempPtr;
    // check if root is empty
    if (root == NULL)
        return NULL;
    // deleting leaf node
    if (root->leftside == NULL && root->rightside == NULL)
    {
        if (key == root->data)
        {
            root = NULL;
            delete root;
            return NULL;
        }
    }
    // first search and than delete
    if (key < root->data)
        root->leftside = deleteNode(root->leftside, key);
    else if (key > root->data)
        root->rightside = deleteNode(root->rightside, key);
    else
    {
        if (height(root->leftside) > height(root->rightside))
        {
            tempPtr = predecessor(root->leftside);
            root->data = tempPtr->data;
            root->leftside = deleteNode(root->leftside, tempPtr->data);
        }
        else
        {

            tempPtr = Succesor(root->rightside);
            root->data = tempPtr->data;
            root->rightside = deleteNode(root->rightside, tempPtr->data);
        }
    }
    root->height = max(height(root->leftside), height(root->rightside)) + 1;
    int bFactor = getBalanceFactor(root);
    if (bFactor > 1)
    {
        if (key < root->leftside->data)
            return RightRotation(root);
        else if (key > root->leftside->data)
        {
            root->leftside = leftRotation(root->leftside);
            return RightRotation(root);
        }
    }
    if (bFactor < -1)
    {
        if (key > root->rightside->data)
            return leftRotation(root);
        else if (key < root->rightside->data)
        {
            root->rightside = RightRotation(root->rightside);
            return leftRotation(root);
        }
    }
    return root;
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
    cout << "\n-----------Inorder-----------------\n";
    inorder(node);
    cout << "\n-----------postrder-----------------\n";
    postorder(node);
    cout << "\n-----------Preorder-----------------\n";
    preorder(node);
    cout << "\n-----------deletion of node-----------------\n";
    node = deleteNode(node, 110);
    inorder(node);
}
