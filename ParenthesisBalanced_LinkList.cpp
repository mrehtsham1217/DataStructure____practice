#include <iostream>
using namespace std;
class Stack
{
private:
    int data;    // data for linklsit
    Stack *Next; // next address of link list--->node
    Stack *Top;  // top most element in stack
public:
    Stack()
    {
        Top = NULL;
    }
    void push(int data)
    {
        Stack *NewNode = new Stack();
        NewNode->data = data;
        NewNode->Next = Top;
        Top = NewNode;
    }
    void pop()
    {
        if (Top == NULL)
        {

            cout << "Stack is empty!" << endl;
            return;
        }
        Stack *popPtr = Top; // assign top value to the ptr
        Top = Top->Next;     // Top++---->Move to the next
        delete popPtr;       // delete ptr
    }
    int peek()
    {
        if (Top == NULL)
            return 0;
        else
            return Top->data;
    }
    bool IsEmpty()
    {
        if (Top == NULL)
            return 1;
        else
            return 0;
    }
    void display()
    {
        Stack *printPtr = Top;
        while (printPtr != NULL)
        {
            cout << "-->" << printPtr->data;
            printPtr = printPtr->Next;
        }
        cout << "-->NULL";
    }
    int IsBalanced(char Array[])
    {
        for (int i = 0; Array[i] != '\0'; i++)
        {
            if (Array[i] == '(')
                push(Array[i]);
            else if (Array[i] == ')')
            {

                if (IsEmpty() == true)
                {
                    return 0;
                }
                pop();
            }
        }
        if (IsEmpty() == true)
            return 1;
    }
};

int main()
{
    Stack stk;
    char Array[] = "((2 * 3) + (2 * 5) + (2 + 3))";
    if (stk.IsBalanced(Array))
        cout << "Equation is balanced:\n";
    else
        cout << "Equation is not balanced";
    // stk.push(20);
    // stk.push(30);
    // stk.push(40);
    // stk.push(50);
    // stk.pop();
    // stk.display();
    // if (stk.IsEmpty() == true)
    //     cout << "Stack is empty!" << endl;
    // else
    //     cout << "\n Stack is not empty!" << endl;
    // cout << "\n The peek element in the list is:\t" << stk.peek();
}