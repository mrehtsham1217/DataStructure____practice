#include <iostream>
using namespace std;
const int SIZE = 10;
class Heap
{
private:
    int Array[SIZE];
    int length;

public:
    Heap()
    {
        length = 0;
    }
    int getParentNode(int index)
    {
        return (index - 1) / 2;
    }
    int getLeftChild(int index)
    {
        return (2 * index) + 1;
    }
    int getRightChild(int index)
    {
        return (2 * index) + 2;
    }

    void createHeap(int index)
    {
        if (index == 0)
            return;
        int parentIndex = getParentNode(index);
        if (Array[index] > Array[parentIndex])
        {
            swap(Array[index], Array[parentIndex]);
            createHeap(parentIndex);
        }
    }
    void deleteHeap(int index)
    {
        int leftchild = getLeftChild(index);
        int rightchild = getRightChild(index);
        int temp = index;
        if (leftchild < length && Array[leftchild] > Array[temp])
        {
            temp = leftchild;
        }
        if (rightchild < length && Array[rightchild] > Array[temp])
        {
            temp = rightchild;
        }
        if (temp > index)
        {
            swap(Array[index], Array[temp]);
            deleteHeap(index);
        }
    }
    int remove()
    {
        if (length == 0)
            return 0;
        else
        {
            int del = Array[0];
            length--;
            Array[0] = Array[length];
            deleteHeap(0);
            return del;
        }
    }
    void insertData(int data)
    {
        if (length == SIZE)
        {
            cout << "Heap memory is full!" << endl;
            return;
        }
        else
        {
            Array[length] = data;
            createHeap(length);
            length++;
        }
    }

    void displayHeap()
    {
        for (int i = 0; i < length; i++)
        {
            cout << Array[i] << ' ';
        }
        cout << endl;
    }
    int search(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (Array[i] == key)
                return i;
        }
        return -1;
    }
    int FindMax()
    {
        return Array[0];
        cout << endl;
    }
    int FindMin()
    {
        if (length == 0)
        {
            cout << "\n Array is Empty:" << endl;
            return -1;
        }
        int min = Array[0];
        for (int i = 0; i < length; i++)
        {
            if (Array[i] < min)
                min = Array[i];
        }
        return min;
        cout << endl;
    }
};

int main()
{
    Heap heap;
    int choice;
    int length;
    int dataInsert;
    cout << "Enter length for Array elements:\t";
    cin >> length;
    while (true)
    {
        cout << "\n--------------------------Heap Data Structure---------------------\n";
        cout << "Enter 1 For Data Insertion:\n";
        cout << "Enter 2 For Searching:\n";
        cout << "Enter 3 For Finding Maximum:\n";
        cout << "Enter 4 For Finding Minimum:\n";
        cout << "Enter 5 For Deletion:\n";
        cout << "Enter 6 For Display:\n";
        cout << "Enter -1 For Exit:\n";

        cout << "Enter choice:\t";
        cin >> choice;
        if (choice == 1)
        {
            for (int i = 0; i < length; i++)
            {

                cout << "Enter data for insertion:\t";
                cin >> dataInsert;
                heap.insertData(dataInsert);
            }
        }
        else if (choice == 2)
        {
            int searchdata;
            cout << "ENter element for search:\t";
            cin >> searchdata;
            cout << heap.search(searchdata);
        }
        else if (choice == 3)
        {
            cout << "\n-----------------Searching in Max heap----------------\n";
            cout << "Maximum number in max heap:\t" << heap.FindMax();
        }
        else if (choice == 4)
        {

            cout << "\n-----------------Miniimum number in MAx heap----------------\n";
            cout << "Minimum No. in max heap:\t" << heap.FindMin();
        }
        else if (choice == 5)
        {
            cout << "\n-----------------Deletion in MAx heap----------------\n";
            cout << "Deleted element in heap:\t" << heap.remove() << "\n";
        }
        else if (choice == 6)
        {
            cout << "\n-----------Displaying data---------------\n";
            heap.displayHeap();
        }
        else if (choice == -1)
        {
            cout << "\nThanks for using heap data Structures------------------\n";
            break;
        }
        else
            cout << "\n Invalid choice\n";
    }
}
