#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void InsertData(int Array[], int Size)
{
    Node *last, *temp;
    first = new Node();
    first->data = Array[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < Size; i++)
    {
        temp = new Node();
        temp->data = Array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
// recursion display method
// void display(Node *ptr)
// {
//     if (ptr != NULL)
//         cout << ptr->data << " ";
//     display(ptr->next);
// }
void display(Node *ptr)
{
    int count = 0, sum = 0;
    while (ptr != NULL)
    {
        count++;
        cout << ptr->data << " ";
        sum = sum + ptr->data;
        ptr = ptr->next;
    }
    cout << "\n Total element is link list:\t" << count << endl;
    cout << "\n Sum of link list:\t" << sum << endl;
}
// Recursive count
// int Rcount(Node *ptr)
// {
//     if (ptr != 0)
//     {
//         return Rcount(ptr->next) + 1;
//     }
//     else
//         return 0;
// }

int main()
{
    Node *node;
    int Array[] = {0, 1, 2, 3, 4, 5, 6, 7};
    InsertData(Array, 8);
    display(first);
    // cout << Rcount(first);

    return 0;
}