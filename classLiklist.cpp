#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;
    Node *CurrentLocation;

public:
    Node();
    void setData(int data);
    int getData();
    void setNext(Node *);
    Node *getNext();
    void Print();
    void Insert(int data);
    void Delete(int data);
};
Node::Node()
{
    CurrentLocation = NULL;
}
void Node::Insert(int data)
{
    Node *newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    Node *tempNode = CurrentLocation;
    if (tempNode != NULL)
    {
        while (tempNode->getNext() != NULL)
        {
            tempNode = tempNode->getNext();
        }
        tempNode->setNext(newNode);
    }
    else
        CurrentLocation = newNode;
}
void Node::setData(int data)
{
    this->data = data;
}
int Node::getData()
{
    return data;
}
void Node::setNext(Node *next)
{
    this->next = next;
}
Node *Node::getNext()
{
    return next;
}
void Node::Print()
{
    Node *tempNode = CurrentLocation;
    if (tempNode == NULL)
    {
        cout << "List is empty:\n";
        return;
    }
    if (tempNode->getNext() == NULL)
    {
        cout << tempNode->getData() << endl;
        cout << "----->";
        cout << "NULL";
    }
    else
    {
        do
        {
            cout << tempNode->getData() << " ";
            tempNode = tempNode->getNext();
        } while (tempNode != NULL);
    }
}
int main()
{
    Node node1, node2, node3;
    node1.Insert(2000);
    node1.Insert(3000);
    node1.Insert(4000);
    node1.Insert(5000);
    node1.Insert(6000);
    node1.Print();
    // node1.setData(10);
    // node2.setData(20);
    // node3.setData(30);
    // node2.setNext(&node2);
    // cout << node1.getData() << "\t" << node2.getData() << "\t" << node3.getData();
}