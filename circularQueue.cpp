#include <iostream>
using namespace std;
const int SIZE = 5;
class CircularQueue
{
private:
    int Array[SIZE];
    int front;
    int last;

public:
    CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int data);
    void dequeue();
    int getFront();
    void printdata();
};
CircularQueue::CircularQueue()
{
    front = -1;
    last = -1;
}
bool CircularQueue::isEmpty()
{
    if (last == -1)
        return true;
    else
        return false;
}
bool CircularQueue::isFull()
{
    return (last + 1) % SIZE == front; // this condition is for full queqe
}
void CircularQueue::enqueue(int data)
{
    if (isFull())
        cout << "Queue is full!" << endl;
    else if (isEmpty())
        front = last = 0;
    else
    {
        last = (last + 1) % SIZE;
    }
    Array[last] = data; // 1--20,2-->30,3--->40
}
void CircularQueue::dequeue()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else if (front == last)
        front = last = -1;
    else
    {
        front = (front + 1) % SIZE;//make front in circular motion
    }
}
void CircularQueue::printdata()
{
    if (isEmpty())
        cout << "Nothing to display." << endl;
    else
    {
        int i = front;
        while (i != last)
        {
            cout << Array[i] << " ";
            i = (i + 1) % SIZE;//make i in circular motion
        }
        cout << Array[last] << " ";
    }
}
int main()
{
    CircularQueue q;
    cout << "--------Enqueue Data---------------\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.printdata();
    cout << "\n--------Dequeue Data---------------\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.printdata();
    cout << "\n------After Dequeue Data (Enqueue data)-----------\n";
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);
    q.enqueue(500);
    q.printdata();
}
