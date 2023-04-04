#include <iostream>
using namespace std;
const int SIZE = 5;
class Stack
{
private:
    char Array[SIZE];
    int Top;

public:
    Stack();
    bool isEmpty();
    bool IsFull();
    void push(char data);
    char pop();
    void display();
    int peek();
    int ParenthesisBalanced(char Array[]);
};
Stack::Stack()
{
    Top = -1; // if stack is empty than Top = -1
}
bool Stack::isEmpty()
{
    if (Top == -1) // if our stack(top==-1) is empty than return true
        return true;
    else
        return false;
}
bool Stack::IsFull()
{
    if (Top == SIZE - 1)
        return true;
    else
        return false;
}
void Stack::push(char data)
{
    if (IsFull() == true) // if stack is full you cannot add more
        cout << "Stack is full:\t";
    else
    {
        Top++;
        Array[Top] = data;
    }
}
char Stack::pop()
{
    if (isEmpty() == true)
    {

        cout << "Stack is empty:\t";
    }
    else
    {

        return Top--;
    }
}
int Stack::peek()
{
    return Top;
}
void Stack::display()
{
    for (int i = peek(); i >= 0; i--)
    {
        cout << Array[i] << " ";
    }
}
int Stack::ParenthesisBalanced(char Array[])
{
    for (int i = 0; Array[i] != '\0'; i++)
    {
        if (Array[i] == '(')
            push(Array[i]);
        else if (Array[i] == ')')
        {
            if (isEmpty() == true)
            {
                return 0;
            }
            pop();
        }
    }
    if (isEmpty() == true)
        return 1;
}

int main()
{
    Stack stk;
    char Array[] = "[{()}]";
    // cin >> Array;
    // if (stk.ParenthesisBalanced(Array))
    // {
    //     cout << "Equation is balanced:\n";
    // }
    // else
    //     cout << "Equation is not balanced";
}