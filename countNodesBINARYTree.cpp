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
        if (rightNode != NULL)
        {
            rightNode->printtree(); // recursion
        }
        cout << data << " ";
    }
    int count(Tree *ptr)
    {
        int x, y;
        if (ptr != NULL)
        {
            x = count(ptr->leftNode);  // recursion for left nodes
            y = count(ptr->rightNode); // recursion for right nodes
            return x + y + 1;
        }
        return 0;
    }
    int countDegree2(Tree *ptr)
    {
        int x, y;
        if (ptr != NULL)
        {
            x = countDegree2(ptr->leftNode);  // recursion for left nodes
            y = countDegree2(ptr->rightNode); // recursion for right nodes
            if (ptr->leftNode && ptr->rightNode)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }
    int countDegree1(Tree *ptr)
    {
        int x, y;
        if (ptr != NULL)
        {
            x = countDegree1(ptr->leftNode);  // recursion for left nodes
            y = countDegree1(ptr->rightNode); // recursion for right nodes
            if (ptr->leftNode || ptr->rightNode)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }
    int countLeafNodes(Tree *ptr)
    {
        int x, y;
        if (ptr != NULL)
        {
            x = countLeafNodes(ptr->leftNode);  // recursion for left nodes
            y = countLeafNodes(ptr->rightNode); // recursion for right nodes
            if (ptr->leftNode == NULL && ptr->rightNode == NULL)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }
};

int main()
{
    Tree tree(30);
    tree.insertData(60);
    tree.insertData(10);
    tree.insertData(20);
    tree.insertData(40);
    tree.insertData(5);
    tree.insertData(6);
    tree.insertData(7);
    tree.insertData(70);
    tree.insertData(80);
    tree.insertData(90);
    tree.printtree();
    cout << "\n Total numbers of Nodes in binary tree:\t" << tree.count(&tree);
    cout << "\n Total numbers of Nodes having 2 degree:\t" << tree.countDegree2(&tree);
    cout << "\n Total numbers of Nodes having 1 degree:\t" << tree.countDegree1(&tree);
    cout << "\n Total numbers of Nodes having 0 degree:\t" << tree.countLeafNodes(&tree);
}
