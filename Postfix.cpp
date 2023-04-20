#include <iostream>
using namespace std;
class Stack
{
private:
    char *array; // pointer for dynamically allocated
    int top;
    int size;

public:
    Stack(int n) // parameterize constructor
    {
        array = new char[n]; // dynamically memory allocation
        top = -1;
        size = n;
    }
    void push(char data)
    {
        if (top == size - 1)
        {

            cout << "stack overflow";
            return;
        }
        else
        {
            top++;
            array[top] = data; // important notice
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    void pop()
    {
        if (top == -1)
        {

            cout << "Stack is empty";
            return;
        }
        else
            top--;
    }
    char peek()
    {
        if (top == -1)
        {

            return '\0';
        }
        return array[top];
    }
    bool isBalanced(char exp[])
    {
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
                push(exp[i]);
            else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
            {
                if (isEmpty())
                {
                    return false;
                }
                if ((exp[i] == ')' && peek() == '(') ||
                    (exp[i] == '}' && peek() == '{') ||
                    (exp[i] == ']' && peek() == '['))
                {
                    pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return isEmpty();
    }
    int checkPrecedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 3;
        else
            return 0;
    }
    void postfixConversion(char infix[], char postfix[])
    {
        int j = 0; // for postfix array--->incrementation
        for (int i = 0; infix[i] != '\0'; i++)
        {
            if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
                postfix[j++] = infix[i];
            else if (infix[i] == '(')
                push(infix[i]);
            else if (infix[i] == ')')
            {
                while (isEmpty() == false && peek() != '(')
                {
                    postfix[j++] = peek();
                    pop();
                }
                if (isEmpty() == false && peek() == '(')
                    pop();
            }
            else
            {
                while (isEmpty() == false && checkPrecedence(infix[i]) <= checkPrecedence(peek()))
                {
                    postfix[j++] = peek();
                    pop();
                }
                push(infix[i]);
            }
        }
        while (isEmpty() == false)
        {
            postfix[j++] = peek();
            pop();
        }
        postfix[j] = '\0';
    }
};

int main()
{
    Stack stk(100);
    char infix[] = "a+b-c+d*f"; // ab+-cd+df*//ab+cd-+df*
    char postfix[100];
    stk.postfixConversion(infix, postfix);
    cout << "Postfix conversion:\t" << postfix;

    // char Array[] = "[{()}]";
    // cout << "orignal exp \t" << Array << endl;
    // if (stk.isBalanced(Array))
    //     cout << "Brackets are  balanced";
    // else
    //     cout << "Brackets are not balanced";
}
