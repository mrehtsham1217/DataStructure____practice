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
    void insertNodeAtLast(int data) // insertion node at start of the list
    {
        Node *headNode = new Node(); // creation of new node
        headNode->data = data;
        headNode->nextAddress = head;
        head = headNode; // now  boss is the new node
    }
    void insertdataAtdesireLocation(int position, int data)
    {
        Node *newNode = new Node(); // create new node
        newNode->data = data;
        // if list has no node than 👇👇
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        // if list has ,many nodes👇👇
        Node *visitPtr = head; // read all the list of nodes
        int count = 0;
        while (visitPtr != NULL)
        {
            if (count == position - 1) // 3-->0->1-->2->3
            {
                newNode->nextAddress = visitPtr->nextAddress;
                visitPtr->nextAddress = newNode;
            }
            visitPtr = visitPtr->nextAddress; // i++
            count++;
        }
    }
    void DeleteNodeLOcation(int position)
    {
        Node *deleteNode = head; // first step
        if (head == NULL)        // if there is no node in the list
            return;
        else
        {
            if (position == 0) // if we want to delete the first node
            {
                head = head->nextAddress; // simple make boss to the next node
                delete deleteNode;
            }
            for (int i = 0; deleteNode != NULL && i < position - 1; i++) // deletednode --->NULL && i<position-1)
            {
                deleteNode = deleteNode->nextAddress; // visiting
            }
            if (deleteNode == NULL || deleteNode->nextAddress == NULL)
                return; // out of range or already deleted node
            Node *nextNode = deleteNode->nextAddress->nextAddress;
            delete deleteNode->nextAddress; // delete the node
            deleteNode->nextAddress = nextNode;
        }
    }
};

int main()
{
    Node node;
    node.insertData(20);
    node.insertData(30);
    node.insertData(50);
    node.insertData(40);
    node.insertData(60);
    node.DeleteNodeLOcation(3);
    node.DeleteNodeLOcation(1);
    node.printNode();
}