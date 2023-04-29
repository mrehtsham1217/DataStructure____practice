#include <iostream>
using namespace std;
const int SIZE = 10;
class Stack
{
private:
    int array[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == SIZE - 1)
            return true;
        else
            return false;
    }
    void push(int data)
    {
        if (isFull())
            cout << "Stack is Full" << endl;
        else
        {
            top++;
            array[top] = data;
        }
    }
    int pop()
    {
        int result;
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
        {
            result = array[top];
            top--;
        }
        return result;
    }
};
class QUEUE
{
private:
    Stack s1, s2;

public:
    void Enqueu(int data)
    {
        s1.push(data);
    }
    int dequeue()
    {
        if (s1.isEmpty() && s2.isEmpty())
            return -1;
        else
        {
            if (s2.isEmpty())
            {
                while (!s1.isEmpty())
                {
                    int temp = s1.pop();
                    s2.push(temp);
                }
            }
            int result = s2.pop();
            return result;
        }
    }
};
int main()
{
    QUEUE q;
    q.Enqueu(10);
    q.Enqueu(20);
    q.Enqueu(30);
    q.Enqueu(40);
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
}
