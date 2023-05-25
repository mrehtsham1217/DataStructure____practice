#include<iostream>

using namespace std;
const int SIZE = 10;
class HeapTree
{
    private:
        int length;
        int heapArray[SIZE]; 
    public:
    
    HeapTree()
    {
        length = 0;
    }
   
    int ParentIndex(int index)
    {
        return (index - 1)/2;
    }
   
    int LeftChild(int index)
    {
        return (index * 2) + 1;
    }
   
    int RightChild(int index)
    {
        return (index * 2) + 2;
    }
    //Create Heap
    void CreateMinHeap(int index)
    {
        if(index == 0)
            return;

        if(heapArray[index] < heapArray[ParentIndex(index)])
        {
            swap(heapArray[index],heapArray [ParentIndex(index)]);
            CreateMinHeap(ParentIndex(index));
        }    
    }
//data insert in the heap
    void InsertDataInHeap(int data)
    {
        if(length == SIZE)
        {
            cout << "Heap is Full" << endl;
            return;
        }    
        else
        {
            heapArray[length] = data;
            CreateMinHeap(length);//length = index
            length++;    
        }   
    }  
    //display heap
    void DisplayHeap()
    {
        for (int i =0; i < length;i++)
        {
            cout << heapArray[i] << "\t";
        }
        cout <<endl;
    }
    //search data
    int SearchData(int data)
    {
        for(int i =0; i < length;i++)
        {
            if(heapArray[i] == data)
            {
                return data;
            }
        }

        return -1;
    }
    //minimum number = first index in min heap
    int MinimumNumber()
    {
        return heapArray[0];
    }
    //maximum number
    int MaximumNumber()
    {
        if(length == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        else
        {
            int max = heapArray[0];
            for (int i =0; i < length;i++)
            {
                if(heapArray[i] > max)
                {
                    max = heapArray[i];
                }
            }
            return max;
        }
    }
//delete heap
    void DeleteHeap(int index)
   {
        //find left right child
        int left = LeftChild(index);
        int right = RightChild(index);
        int temp = index; 
        //check the left child is smaller or not
        if(left < length && heapArray[left] < heapArray[temp])
        {
            temp = left;
        }
        //check the right child is smaller or not
        if(right < length && heapArray[right] < heapArray[temp])
        {
            temp = right;
        }
        //compare parent index and left or right child index
        if(temp != index || index > temp)
        {
            swap(heapArray[index],heapArray[temp]);
            DeleteHeap(index);
        }
   }
     //remove the head node
   int remove()
   {
    if(length == 0)
    {
        return -1;
    }
    else
    {
        int del = heapArray[0];
        length--;
        //give last index value to first index
        heapArray[0] = heapArray[length];
        DeleteHeap(0); // give index one;
        return del;
    }
 }
};

int main()
{ 
        //making object
        HeapTree tree;
        int choice ;
        int length;
        int data;
        cout << "Enter the length of heap 1 - 10-->\t";
        cin >> length;
        if(length == SIZE || length < SIZE)
        {
            cout << "\nFisrtly,Enter the data in heap" << endl << endl;
            for (int i =0; i < length;i++)
            {
                cout << "Enter data in heap[ " << i + 1 << " ]->\t";
                cin >> data;
                tree.InsertDataInHeap(data);
            }
            while (choice != -1)
            {
                cout << "\n\n1) For Search\n2) For Display\n3) For Maximum\n4) For Minimum\n";
                cout << "5) Delete the element\n-1) For Exit\t" ;
                cin >> choice ;

                switch (choice)
                {
                    case 1:
                        int search;
                        cout << "Enter data for Search\t";
                        cin >> search;
                        cout << "Element are\t" << tree.SearchData(search) << endl << endl;
                        break;
                    case 2:
                        cout << "Min Heap are\t";
                        tree.DisplayHeap();
                        break;
                    case 3:
                        cout << "Maximum number is-->\t" << tree.MaximumNumber() << endl << endl;
                        break;
                    case 4:
                        cout << "Minimum number is-->\t" << tree.MinimumNumber() << endl << endl;  
                        break; 
                    case 5:
                        cout << "Element are deleted in min heap-->\t" << tree.remove() << endl << endl; 
                        tree.DisplayHeap();   
                        break;
                    case -1:
                        cout << "Exit From Function" << endl << endl;
                        break;         
                default:
                    cout << "Invalid input!!" <<endl << endl;
                    break;
                }
            }
    }
    else
    {
            cout << "Size Excceed of Heap\n" << endl;
    }   
}
