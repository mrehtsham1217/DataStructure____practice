#include <iostream>
using namespace std;
class Tree
{
private:
    int data;
    Tree *leftNode;
    Tree *rightNode;

public:
    Tree(int data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
    void insertData(int data)
    {
        if (data < this->data) // if the value is less than root value than value will be inserted on left side
        {
            if (leftNode == NULL)
            {

                leftNode = new Tree(data); // creation of new node
            }
            else
            {
                leftNode->insertData(data);
            }
        }
        else
        {
            if (rightNode == NULL)
            {

                rightNode = new Tree(data);
            }
            else
            {
                rightNode->insertData(data); // recursion self calling of a function
            }
        }
    }
    void printtree()
    {
        if (leftNode != NULL)
        {
            leftNode->printtree(); // recursion
        }
        cout << data << " ";
        if (rightNode != NULL)
        {
            rightNode->printtree(); // recursion
        }
    }
    int TotalNodes(Tree *countNode)
    {

        int x, y;
        if (countNode != NULL)
        {

            x = TotalNodes(countNode->leftNode);
            y = TotalNodes(countNode->rightNode);
            return x + y + 1;
        }
        else
            return 0;
    }
    int countLeafNodes(Tree *node)
    {
        if (node != NULL)
        {
            if (node->leftNode == NULL && node->rightNode == NULL)
            {
                return 1;
            }
            else
            {
                return countLeafNodes(node->leftNode) + countLeafNodes(node->rightNode);
            }
        }
        else
            return 0;
    }
    int countDegree(Tree *ptr)
    {
        int x, y;

        if (ptr != NULL)
        {
            x = countDegree(ptr->leftNode);
            y = countDegree(ptr->rightNode);
            if (ptr->leftNode && ptr->rightNode)
                return x + y + 1;
            else
                return x + y;
        }
        else
            return 0;
    }
    int countDegree1(Tree *ptr)
    {
        int x, y;

        if (ptr != NULL)
        {
            x = countDegree(ptr->leftNode);
            y = countDegree(ptr->rightNode);
            if (ptr->leftNode || ptr->rightNode)
                return x + y + 1;
            else
                return x + y;
        }
        else
            return 0;
    }
    int calHeight(Tree *root)
    {
        int xheight, yheight;
        if (root == NULL)
            return 0;
        if (root != NULL)
        {
            xheight = calHeight(root->leftNode);  // cal height for left side of a tree
            yheight = calHeight(root->rightNode); // calculate height for right side of tree
            if (xheight > yheight)
                return xheight + 1;
            else
                return yheight + 1;
        }
    }
    //-----By using Recursive method--->
    // int minumumNode(Tree *root)
    // {
    //     // by using recursive function
    //     if (root == NULL)
    //         return 0;
    //     else if (root->leftNode == NULL)
    //         return root->data;
    //     return minumumNode(root->leftNode);
    // }
    // int maxNode(Tree *root)
    // {
    //     // by using recursive function
    //     if (root == NULL)
    //         return 0;
    //     else if (root->rightNode == NULL)
    //         return root->data;
    //     return maxNode(root->rightNode);
    // }
    // By using loops---->Iterative methods
    int minNode(Tree *root)
    {
        int min = root->data;
        while (root->leftNode != NULL)
        {
            min = root->leftNode->data;
            root = root->leftNode;
        }
        return min;
    }
    int maxNode(Tree *root)
    {
        int max = root->data;
        while (root->rightNode != NULL)
        {
            max = root->rightNode->data;
            root = root->rightNode;
        }
        return max;
    }
    bool searchNode(Tree *root, int key)
    {
        if (root == NULL)
            return false;
        else if (key == root->data)
            return true;
        else if (key < root->data)
            return searchNode(root->leftNode, key);
        else if (key > root->data)
            return searchNode(root->rightNode, key);
        else
            return false;
    }
    Tree *predecessor(Tree *root)
    {
        while (root && root->rightNode != NULL)
            root = root->rightNode;
        return root;
    }
    Tree *Succesor(Tree *root)
    {
        while (root && root->leftNode != NULL)
            root = root->leftNode;
        return root;
    }
    Tree *DeleteNode(Tree *root, int key)
    {
        Tree *tempPtr;
        if (root == NULL)
            return NULL;
        // deleting leaf node
        if (root->leftNode == NULL && root->rightNode == NULL)
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
            root->leftNode = DeleteNode(root->leftNode, key);
        else if (key > root->data)
            root->rightNode = DeleteNode(root->rightNode, key);
        else
        {
            if (calHeight(root->leftNode) > calHeight(root->rightNode))
            {
                tempPtr = predecessor(root->leftNode);
                root->data = tempPtr->data;
                root->leftNode = DeleteNode(root->leftNode, tempPtr->data);
            }
            else
            {

                tempPtr = Succesor(root->rightNode);
                root->data = tempPtr->data;
                root->rightNode = DeleteNode(root->rightNode, tempPtr->data);
            }
        }
        return root;
    }
};

int main()
{
    Tree tree(30);
    tree.insertData(60);
    tree.insertData(10);
    tree.insertData(20);
    tree.insertData(40);
    tree.insertData(70);
    tree.insertData(80);
    tree.insertData(90);
    tree.printtree();
    cout << endl;
    tree.DeleteNode(&tree, 90);
    tree.DeleteNode(&tree, 30);
    tree.DeleteNode(&tree, 40);
    tree.DeleteNode(&tree, 70);
    tree.printtree();
#pragma region
    // cout << "\n Total Nodes in the Tree are " << tree.TotalNodes(&tree);
    // cout << "\n Total leaf nodes in the Tree are " << tree.countLeafNodes(&tree);
    // cout << "\n degree 2  of the tree:\t" << tree.countDegree(&tree);
    // cout << "\n degree 1  of the tree:\t" << tree.countDegree(&tree);
    // cout << "\n Height   of the tree:\t" << tree.calHeight(&tree);
    // cout << "\n min node of the tree:\t" << tree.minNode(&tree);
    // cout << "\n maxnode of the tree:\t" << tree.maxNode(&tree);
    // cout << "\n minimum node  of the tree:\t" << tree.minumumNode(&tree);
    // cout << "\n max node of the tree:\t" << tree.maxNode(&tree);
    // cout << "\n"
    //      << tree.searchNode(&tree, 95);
#pragma endregion
}
