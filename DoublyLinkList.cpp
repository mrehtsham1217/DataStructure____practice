#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *nextAddres;
    Node *prevAddres;
    Node *head;

public:
    Node()
    {
        head = NULL;
    }
    void insertData(int data)
    {
        Node *newNode = new Node(); // default constructor
        newNode->data = data;
        newNode->nextAddres = NULL;
        Node *visitPtr = head;
        if (visitPtr != NULL)
        {

            while (visitPtr->nextAddres != NULL)
            {
                visitPtr = visitPtr->nextAddres;
            }
            visitPtr->nextAddres = newNode;
            newNode->prevAddres = visitPtr; // extra step for doubly link list
        }
        else
            head = newNode; // if this is first node in the list
    }
    void printList()
    {
        Node *printNode = head;
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        else
        {
            while (printNode != NULL)
            {
                cout << "-->" << printNode->data;
                printNode = printNode->nextAddres;
            }
            cout << "-->NULL";
        }
    }
    void insertAtHead(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->nextAddres = head;
        // if (head != NULL)
        head->prevAddres = newNode;
        head = newNode;
    }
};

int main()
{
    Node node;
    node.insertData(20);
    node.insertData(30);
    node.insertData(40);
    node.insertAtHead(10);
    node.insertAtHead(5);
    node.printList();
}