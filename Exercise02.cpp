#include <iostream>
using namespace std;
class LinkedQueue
{
private:
    int data;
    LinkedQueue *next;
    LinkedQueue *first;
    LinkedQueue *last;

public:
    LinkedQueue();
    bool isEmpty();
    void Enqueue(int data);
    void Dequeue();
    void printData();
};
LinkedQueue::LinkedQueue()
{
    first = NULL;
    last = NULL;
}
bool LinkedQueue::isEmpty()
{
    if (last == NULL)
        return true;
    else
        return false;
}
void LinkedQueue::Enqueue(int data)
{
    LinkedQueue *Newnod = new LinkedQueue();
    Newnod->data = data;
    Newnod->next = NULL;
    if (last == NULL)
    {
        first = Newnod;
        last = Newnod;
    }
    last->next = Newnod;
    last = Newnod;
}
void LinkedQueue::Dequeue()
{
    if (isEmpty() == true)
        cout << "Queue is empty";
    else
    {
        LinkedQueue *deletePtr = first;
        first = first->next;
        delete deletePtr;
    }
}
void LinkedQueue::printData()
{
    LinkedQueue *printPtr = first;
    while (printPtr != NULL)
    {
        cout << "-->" << printPtr->data;
        printPtr = printPtr->next;
    }
    cout << "-->NULL";
}
int main()
{
    LinkedQueue list;
    cout << "\n [+]----------Enqueu data-------------\n";
    list.Enqueue(10);
    list.Enqueue(20);
    list.Enqueue(30);
    list.Enqueue(40);
    list.Enqueue(50);
    list.printData();
    cout << "\n[-]----------Dequeue data-------------\n";
    list.Dequeue();
    list.printData();
}