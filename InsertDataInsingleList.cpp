#include <iostream>
using namespace std;
class Node // creation of class
{
private:
    int data;          // data part of link list
    Node *nextAddress; // address of next node
    Node *head;        // current location of link list

public:
    Node() // default constructor
    {
        head = NULL;
    }
    void insertData(int data)
    {
        // step--01---->creation of a node
        Node *NewNode = new Node(); // one node is created
        NewNode->data = data;       // data has assigned
        NewNode->nextAddress = NULL;
        Node *visitNode = head;
        if (visitNode != NULL)
        {

            while (visitNode->nextAddress != NULL)
            {
                visitNode = visitNode->nextAddress;
            }
            visitNode->nextAddress = NewNode;
        }
        else
        {
            head = NewNode; // when there is no node in the list
        }
    }
    void printNode()
    {
        Node *printNode = head;
        if (printNode == NULL)
        {
            cout << "List is empty:\n";
        }
        else
        {
            while (printNode != NULL)
            {
                cout << "-->" << printNode->data;   // print this
                printNode = printNode->nextAddress; // i++-->same move to next address
            }
            cout << "-->NULL";
        }
    }
};

int main()
{
    Node node;
    node.insertData(20);
    node.insertData(30);
    node.insertData(40);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.insertData(50);
    node.printNode();
}