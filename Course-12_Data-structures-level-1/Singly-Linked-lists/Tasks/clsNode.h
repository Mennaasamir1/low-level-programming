#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node *Next;


    static void Display(Node *head)
    {
        while (head != NULL)
        {
            cout << head->Data << " ";
            head = head->Next;
        }

        cout << endl;
    }
};