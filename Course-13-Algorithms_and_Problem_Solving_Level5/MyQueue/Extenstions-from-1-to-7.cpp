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

    /* Extension 1 */

    cout << "\nItem(2): " << MyQueue.GetItem(2) << endl;

    /* Extension 2 */
    MyQueue.Reverse();
    cout << "\nQueue after reverse: ";
    MyQueue.Print();

    /* Extension 3 */
    MyQueue.UpdateItem(2, 600);
    cout << "\nQueue after updating Item(2) to 600 : \n";
    MyQueue.Print();

    /* Extension 4 */
    MyQueue.InsertAfter(2, 800);
    cout << "\nQueue after Inserting 800 after Item(2) : \n";
    MyQueue.Print();

    /* Extension 5 */
    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front: \n";
    MyQueue.Print();

    /* Extension 6 */
    MyQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at back: \n";
    MyQueue.Print();

    /* Extension 7 */
    MyQueue.Clear();
    cout << "\n\nQueue after Clear(): \n";
    MyQueue.Print();
    
    return (0);
}