#include <iostream>
using namespace std;
const int SIZE = 10;
class Queue
{
private:
    int Array[SIZE];
    int front;
    int back;

public:
    Queue();
    bool isEmpty();
    bool isFull();
    void Enqueue(int data);
    void Dequeue();
    int getfirst();
    int getLast();
    void printData();
};
Queue::Queue()
{
    front = -1;
    back = -1;
}
bool Queue::isEmpty()
{
    if (back == -1 || front == back)
        return 1;
    else
        return 0;
}
bool Queue::isFull()
{
    if (back == SIZE - 1)
        return true;
    else
        return false;
}
void Queue::Enqueue(int data)
{
    if (isFull())
        cout << "QUEUE is full";
    else
    {
        back++;
        Array[back] = data;
    }
}
void Queue::Dequeue()
{
    if (isEmpty())
        cout << "Queue is empty:\n";
    else
        front++;
}
int Queue::getfirst()
{
    return Array[front + 1];
}
int Queue::getLast()
{
    return Array[back];
}
void Queue::printData()
{
    for (int i = front + 1; i <= back; i++)
    {
        cout << Array[i] << " ";
    }
}
int main()
{
    Queue q;
    cout << "\n ------Enqueue Data---------\n";
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.printData();
    cout << "\n ------Dequeue Data---------\n";
    q.Dequeue();
    q.printData();
    cout << "\n first element in Queue " << q.getfirst();
    cout << "\n Last element in Queue " << q.getLast();
}