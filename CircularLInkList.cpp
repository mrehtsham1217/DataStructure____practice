#include <iostream>
using namespace std;
class Node
{
private:
    int data;      // data part
    Node *address; // address of next node
    Node *head;    // current location of link list
public:
    Node()
    { // default constructor
        head = NULL;
    }
    void insertAtbegin(int data)
    {
        Node *headNode = new Node();
        headNode->data = data;
        headNode->address = NULL;
        Node *visitNode = head;
        while (visitNode->address != head)
        {
            visitNode = visitNode->address;
        }
        visitNode->address = headNode; // NEW NODE IS HEAD NOW
        headNode->address = head;
        head = headNode;
    }
    void InsertdataAtEnd(int data)
    {
        Node *NewNode = new Node();
        NewNode->data = data;
        NewNode->address = NULL;
        if (head == NULL)
        {
            head = NewNode; // newNode is boss/head now
            head->address = head;
            return;
        }
        Node *visitNode = head;
        while (visitNode->address != head) // circular list--->every last node is  connected to first node
        {
            visitNode = visitNode->address;
        }
        visitNode->address = NewNode;
        NewNode->address = head;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *printNode = head; // visit all the list to print data
        do
        {
            cout << "-->" << printNode->data;
            printNode = printNode->address;
        } while (printNode != head);
        cout << "-->Head\n";
    }
};

int main()
{
    Node node;
    node.InsertdataAtEnd(20);
    node.InsertdataAtEnd(30);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.InsertdataAtEnd(40);
    node.insertAtbegin(10);
    node.insertAtbegin(9);
    node.insertAtbegin(8);
    node.insertAtbegin(7);
    node.display();
}