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
            visitPtr = visitPtr->nextAddress;
            count++;
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
    node.insertData(60);
    node.insertData(70);
    node.insertData(57);
    node.insertData(51);
    node.insertData(52);
    node.insertData(53);
    node.insertData(54);
    node.insertData(55);
    node.insertData(56);
    // insert data at begining of list
    node.insertNodeAtLast(10);
    node.insertNodeAtLast(1000);
    node.insertNodeAtLast(9990);
    node.insertdataAtdesireLocation(4, 145);
    node.insertdataAtdesireLocation(9, 1145);
    node.printNode();
}