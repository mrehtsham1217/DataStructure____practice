#include <iostream>
using namespace std;
const int SIZE = 10;
struct Array
{
    int array[SIZE];
    int length;
};
void InsertElement(Array *ptr, int element, int index)
{
    if (index >= 0 && index <= ptr->length) // is index valid or not
    {
        // for start from lenght and go to the specific index
        for (int i = ptr->length; i >= index; i--)
        { // data shift to next
            ptr->array[i + 1] = ptr->array[i];
        }
        ptr->array[ptr->length++];
        ptr->array[index] = element;
    }
}
void deleteData(Array *ptr, int index)
{
    if (index >= 0 && index <= ptr->length)
    {
        for (int i = index; i < ptr->length; i++)
        {
            ptr->array[i] = ptr->array[i + 1];
        }
        ptr->array[ptr->length--];
    }
}
void printData(Array *ptr)
{
    for (int i = 0; i < ptr->length; i++)
    {
        cout << ptr->array[i] << " ";
    }
}
int main()
{
    Array arr;
    cout << "Enter length:\t";
    cin >> arr.length;
    for (int i = 0; i < arr.length; i++)
    {
        cout << "Enter array:[" << i << "]\t";
        cin >> arr.array[i];
    }
    InsertElement(&arr, 100, 3);
    cout << endl;
    printData(&arr);
    cout << "\n-----------Delete data------------\n";
    deleteData(&arr, 4);
    printData(&arr);
}