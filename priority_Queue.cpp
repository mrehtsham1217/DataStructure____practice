#include <iostream>
using namespace std;
 
const int MAX_SIZE  = 100;
 
class PriorityQueue
{
private:
    int arr[MAX_SIZE];
    int size;
 
public:
    PriorityQueue()
    {
        size = 0;
    }
    void insert(int data, int priority)
    {
        if (size == MAX_SIZE)
        {
 
            return;
        }
        int i = size - 1;
        while (i >= 0 && arr[i] < priority)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = priority;
        size++;
    }
    int remove()
    {
        if (size == 0)
        {
            return -1;
        }
        int highestPriorityIndex = 0;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > arr[highestPriorityIndex])
            {
                highestPriorityIndex = i;
            }
        }
        int result = arr[highestPriorityIndex];
        for (int i = highestPriorityIndex; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return result;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == MAX_SIZE;
    }
    void display()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
 
int main()
{
	system("color F4");
    PriorityQueue pq;
    //Greater  priority will remove first
    pq.insert(5, 2);
    pq.insert(3, 1);
    pq.insert(7, 31);
    pq.insert(71, 10);
    pq.insert(27, 0);
    pq.insert(17, 6);
    pq.display();
    while (!pq.isEmpty())
    {
        cout << pq.remove() << " ";
    }
    return 0;
}
 
