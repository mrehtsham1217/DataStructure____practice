#include <iostream>
using namespace std;
struct Link
{
    int data;
    struct Link *next;
} *first = NULL;
void InsertData(int Array[], int size)
{
    struct Link *temp, *last;
    first = new Link();
    first->data = Array[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < size; i++)
    {
        temp = new Link();
        temp->data = Array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Display(Link *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Link link;
    int array[] = {1, 3};
    InsertData(array, 2);
    Display(first);
}