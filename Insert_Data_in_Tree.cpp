#include <iostream>
using namespace std;
class Tree
{
private:
    int data;
    Tree *leftNode;
    Tree *rightNode;

public:
    Tree(int data);
    void insertData(int data);
    void printdata();
    void inorderPrint();
    void preorderPrint();
    void postorderPrint();
};
Tree::Tree(int data) // parameterized constructor
{
    this->data = data;
    leftNode = NULL;
    rightNode = NULL;
}
void Tree::insertData(int data)
{
    if (data < this->data)
    {
        if (leftNode == NULL) // if leftnoide is NULL than we will create the node
        {
            leftNode = new Tree(data); // creating new Nodes
        }
        else

        {
            leftNode->insertData(data); // recursive function
        }
    }
    else
    {
        if (rightNode == NULL)
        {
            rightNode = new Tree(data); // creating new Nodes
        }
        else
        {
            rightNode->insertData(data); // recursive function
        }
    }
}
void Tree::inorderPrint() // function when calls itself is called recursion
{
    if (leftNode != NULL)
    {
        leftNode->inorderPrint(); // recursive function
    }
    cout << data << " "; //-----Root
    if (rightNode != NULL)
    {
        rightNode->inorderPrint(); // recursive function
    }
}
void Tree::preorderPrint() // first Root--->left---->right
{
    cout << data << " "; //----Root data
    if (leftNode != NULL)
    {
        leftNode->preorderPrint(); // recursive function
    }
    if (rightNode != NULL)
    {
        rightNode->preorderPrint(); // recursive function
    }
}
void Tree::postorderPrint() // left--->Right---->Root
{

    if (leftNode != NULL)
    {
        leftNode->postorderPrint(); // recursive function
    }
    if (rightNode != NULL)
    {
        rightNode->postorderPrint(); // recursive function
    }
    cout << data << " ";
}

int main()
{
    Tree tree(10);
    tree.insertData(7);
    tree.insertData(8);
    tree.insertData(9);
    tree.insertData(10);
    tree.insertData(13);
    tree.insertData(14);
    tree.insertData(15);
    tree.insertData(21);
    tree.insertData(40);
    tree.insertData(50);
    // tree.insertData(60);
    cout << "\n--------Inorder Method-----------------\n";
    tree.inorderPrint();
    cout << "\n--------pre-order Method-----------------\n";
    tree.preorderPrint();
    cout << "\n--------post-order Method-----------------\n";
    tree.postorderPrint();
}