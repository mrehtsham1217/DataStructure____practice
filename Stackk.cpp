#include <iostream>
#include <stack>
using namespace std;
// const int SIZE = 5;
// class Stack
// {
// private:
//     int Array[SIZE];
//     int Top;

// public:
//     Stack();
//     bool isEmpty();
//     bool IsFull();
//     void push(int data);
//     void pop();
//     void display();
//     int peek();
// };
// Stack::Stack()
// {
//     Top = -1; // if stack is empty than Top = -1
// }
// bool Stack::isEmpty()
// {
//     if (Top == -1) // if our stack(top==-1) is empty than return true
//         return true;
//     else
//         return false;
// }
// bool Stack::IsFull()
// {
//     if (Top == SIZE - 1)
//         return true;
//     else
//         return false;
// }
// void Stack::push(int data)
// {
//     if (IsFull() == true) // if stack is full you cannot add more
//         cout << "Stack is full:\t";
//     else
//     {
//         Top++;
//         Array[Top] = data;
//     }
// }
// void Stack::pop()
// {
//     if (isEmpty() == true)
//     {

//         cout << "Stack is empty:\t";
//     }
//     else
//     {

//         Top--;
//     }
// }
// int Stack::peek()
// {
//     return Top;
// }
// void Stack::display()
// {
//     for (int i = peek(); i >= 0; i--)
//     {
//         cout << Array[i] << " ";
//     }
// }

int main()
{
    // Stack stk;
    // stk.push(20);
    // stk.push(30);
    // stk.push(40);
    // stk.push(50);
    // stk.push(60);
    // stk.display();
    // cout << "\n\n";
    // stk.pop();
    // stk.pop();
    // stk.display();
    // cout << "\n\n";
    // cout << stk.peek();
    stack<int> stk;
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);
    stk.pop();
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
}