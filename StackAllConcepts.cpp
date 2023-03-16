#include <iostream>
using namespace std;
// constant array size
const int Size = 100;
// stack class (Same for every concept pehle yh bnani implement krni)
class Stack
{
private:
    // Array k phle value/address ko represet krta top
    int Top;
    int stackArray[Size];

public:
    // Constructor
    Stack()
    {
        // kisse b value se initialize krlo
        Top = -1;
    }
    // Top me pari value return krdyga
    int TopSize()
    {
        return Top;
    }
    // Agar stack me koe value na hue to true return krega yani stack khali hai
    bool isEmpty()
    {
        if (Top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Agar stack me jga na hue size complete hgya to true return krega yani stack full hochuka
    bool isFull()
    {
        if (Top == Size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Stack me value enter krne ka method
    void Push(int element)
    {
        // Agar stack full ho chuka to msg genertae hojay
        if (isFull() == true)
        {
            cout << "Stack is full" << endl;
        }
        // Agar space hai to value enter hojay
        else
        {
            Top++;
            stackArray[Top] = element;
        }
    }
    // Stack se value bahar nikalne k leye
    void Pop()
    {
        // Agar stack khali hai to msg generate hojay
        if (isEmpty() == true)
        {
            cout << "Stack is empty" << endl;
        }
        // Nahi to value bahr ajay
        else
        {
            Top--;
        }
    }
    void display()
    {
        if (Top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            // reverse loop beacuse first in last out in stack
            for (int i = TopSize(); i >= 0; i--)
            {
                cout << stackArray[i] << " ";
            }
        }
    }
    // Convert number(decimal) to binary
    void Binary(int num)
    {
        // jab tk num 0 se bara hai
        while (num > 0)
        {
            // 2 se us number ko divide kr k remainder jo b aay usse remainder k variable me store krwado
            int remainder = num % 2;
            // remainder ko stack me push krdo
            Push(remainder);
            // number ko 2 se divide krdo
            num = num / 2;
        }
    }
    // Check Equal Brackets Method
    int EqualBracket(char array[])
    {
        // jab tk array last character yani \0 k equal na hojay
        for (int i = 0; array[i] != '\0'; i++)
        {
            // agar opening bracket mily to stack me push krdy
            if (array[i] == '(')
            {
                Push(array[i]);
            }
            // agar closing bracket mily to stacck se aik opening bracket pop krly
            else if (array[i] == ')')
            {
                // agar stack khali hai to false/0 return krdy
                if (isEmpty() == true)
                {
                    return 0;
                }
                Pop();
            }
        }
        // end py stack khali ho to true/1 return krdy
        if (isEmpty() == true)
        {
            return 1;
        }
    }
    // function to set operator precedence (konsa operator phle solve hoga)
    int checkPresedence(char op)
    {
        if (op == '+' || op == '-')
        {
            return 1;
        }
        if (op == '*' || op == '/')
        {
            return 2;
        }
        else
            return -1;
    }
    // method to convert infix to postfix
    // 2 arrays aik stack ki or aik output ki
    void infixTopostfix(char infixArray[], char outArray[])
    {
        int i, j = 0;
        while (infixArray[i] != '\0')
        {
            // koe b character ho to direct output array me jay
            if (infixArray[i] == 'a' || infixArray[i] == 'z' || infixArray[i] == 'A' || infixArray[i] == 'Z')
            {
                outArray[j++] = infixArray[i];
            }
            // takreban same as bracketequal function above
            else if (infixArray[i] == '(')
            {
                Push(outArray[j++]);
            }
            else if (infixArray[i] == ')')
            {
                if (isEmpty() == false && TopSize() == '(')
                {
                    outArray[j++] = infixArray[i];
                    Pop();
                }
            }
            else
            {
                // kam precedemce wale operator ko stack se output me shift krdena
                while (isEmpty() == false && checkPresedence(infixArray[i] <= checkPresedence(TopSize())))
                {
                    outArray[j++] = infixArray[i];
                    Pop();
                }
                Push(infixArray[i]);
            }
            i++;
        }
        // jab tk stack khali nhi hta
        while (isEmpty() == false)
        {
            outArray[j++] = infixArray[i];
            Pop();
        }
        outArray[j] != '\0';
    }
};
int main()
{
    // Object creation
    Stack stk;
    // Insert element
    stk.Push(1);
    stk.Push(2);
    // display
    stk.display();
    // Remove first element
    cout << endl;
    stk.Pop();
    stk.display();
    cout << endl;
    // call binary function
    stk.Binary(10);
    stk.display();
    cout << endl;
    char array[] = "(((4+8)+4))";
    if (stk.EqualBracket(array) == 1)
    {
        cout << "Equal Brackets" << endl;
    }
    else
    {
        cout << "Not Equal Brackets" << endl;
    }
    cout << endl;
    // 2 arrays
    char infixArray[Size] = "a*b*c+d-f*e";
    char PostfixOutput[Size];
    stk.infixTopostfix(infixArray, PostfixOutput);
    cout << PostfixOutput << " ";
}