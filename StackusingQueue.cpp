#include <iostream>
using namespace std;
const int SIZE = 10;
class Queue
{
private:
    int Array[SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        if (rear == -1 || front > rear)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == SIZE - 1)
            return true;
        else
            return false;
    }
    void enqueue(int data)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            Array[rear] = data;
        }
        else if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else
        {
            rear++;
            Array[rear] = data;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        front++;
    }
    int getfront()
    {
        return Array[front];
    }
};
class Stack
{
private:
    Queue q1, q2;

public:
    void push(int data)
    {
        q2.enqueue(data);
        while (!q1.isEmpty())
        {
            q2.enqueue(q1.getfront());
            q1.dequeue();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.dequeue();
    }
    int top()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.getfront();
    }
};

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40); // 40,30,20,10
    cout << "\n-----------Poping the element-------\n";
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
}
