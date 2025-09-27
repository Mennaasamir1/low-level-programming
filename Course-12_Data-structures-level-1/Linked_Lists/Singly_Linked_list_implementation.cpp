#include <iostream>
using namespace std;

template <class type>

class Node
{
    public:
        type Data;
        Node *Next;
};

int main(void)
{
    Node <int> *head;

    Node <int> *Node1 = new Node <int>;
    Node <int> *Node2 = new Node <int>;
    Node <int> *Node3 = new Node <int>;

    Node1->Data = 10;
    Node2->Data = 20;
    Node3->Data = 30;

    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = NULL;

    head = Node1;

    cout << "\nLinked list elements: ";
    while (head != NULL)
    {
        cout << head->Data << " ";
        head = head->Next; /* to move to the next element in the list */
    }
    cout << endl;

    return (0);
}