#include "clsMyQueue.h"

int main(void)
{
    clsMyQueue <int> MyQueue;

    MyQueue.Push(10);
    MyQueue.Push(20);
    MyQueue.Push(30);
    MyQueue.Push(40);
    MyQueue.Push(50);

    cout << "\nQueue: \n";
    MyQueue.Print();

    cout << "\nQueue size: " << MyQueue.Size() << endl;
    cout << "\nQueue front: " << MyQueue.front() << endl;
    cout << "\nQueue Back: " << MyQueue.Back() << endl;

    MyQueue.Pop();

    cout << "\nQueue after pop(): ";
    MyQueue.Print();

    return (0);
}