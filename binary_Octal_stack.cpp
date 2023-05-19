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
    void Octal(int num)
    {
        // jab tk num 0 se bara hai
        while (num > 0)
        {
            // 2 se us number ko divide kr k remainder jo b aay usse remainder k variable me store krwado
            int remainder = num % 8;
            // remainder ko stack me push krdo
            Push(remainder);
            // number ko 2 se divide krdo
            num = num / 8;
        }
    }
    // Check Equal Brackets Method
    
    
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
    stk.Octal(50);
    cout << endl;
    
}
