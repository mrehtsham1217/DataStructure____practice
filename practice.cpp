#include <iostream>
using namespace std;
class List
{
private:
    int data;
    List *next;
    List *currentLocation;

public:
    List();
    void insertData(int data);
    void printData();
    int MAx();
    int Minimum();
};
List::List()
{
    currentLocation = NULL;
}
int List::MAx()
{
    List *Max = currentLocation;
    int max = 0;
    while (Max != NULL)
    {

        if (Max->data > max)
            max = Max->data;
        Max = Max->next;
    }
    return max;
}
int List::Minimum()
{
    List *Mini = currentLocation;
    int minimum = 5000;
    while (Mini != NULL)
    {

        if (Mini->data < minimum)
            minimum = Mini->data;
        Mini = Mini->next;
    }
    return minimum;
}

void List::insertData(int data)
{
    List *newNode = new List();
    List *tempNode;
    newNode->data = data;
    newNode->next = NULL;
    tempNode = currentLocation;
    if (tempNode != NULL)
    {
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
    else
        currentLocation = newNode;
}
void List::printData()
{
    List *tempNode = currentLocation;
    while (tempNode != NULL)
    {
        cout << tempNode->data;
        cout << endl;
        tempNode = tempNode->next;
    }
}
int main()
{
    List l1;
    l1.insertData(100);
    l1.insertData(200);
    l1.insertData(300);
    l1.insertData(400);
    l1.insertData(500);
    l1.insertData(600);
    l1.insertData(700);
    l1.printData();
    cout << "Max " << l1.MAx();
    cout << "Min " << l1.Minimum();
    // l1.printData();
}