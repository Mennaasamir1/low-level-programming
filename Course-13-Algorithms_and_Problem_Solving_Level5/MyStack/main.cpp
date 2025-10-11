#include "clsMyStack.h"

int main(void)
{
    clsMyStack <int> MyStack;

    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);
    MyStack.Push(40);
    MyStack.Push(50);

    cout << "\nStack Content: ";
    MyStack.Print();

    MyStack.Pop();

    cout << "\nStack after pop(): ";
    MyStack.Print();

    /* Extension 1 */
    cout << "\nItem(2): " << MyStack.GetItem(2);

    /* Extension 2 */
    MyStack.Reverse();
    cout << "\nStack after reverse:" << endl;
    MyStack.Print();

    /* Extension 3 */
    MyStack.UpdateItem(2, 600);
    cout << "\nStack after updating item(2) to 600: \n";
    MyStack.Print();

    /* Extension 4 */
    MyStack.InsertAfter(2, 800);
    cout << "\nStack after inserting 800 after item(2):\n";
    MyStack.Print();
    
    /* Extension 5 */
    MyStack.InsertAtTop(1000);
    cout << "\nStack after inserting 1000 at top of stack\n";
    MyStack.Print();

    /* Extension 6 */
    MyStack.InsertAtBottom(2000);
    cout << "\nStack after inserting 2000 at the bottom of stack\n";
    MyStack.Print();

    /* Extension 7 */
    MyStack.Clear();
    cout << "\nStack after clearing: ";
    MyStack.Print();

    return (0);
}