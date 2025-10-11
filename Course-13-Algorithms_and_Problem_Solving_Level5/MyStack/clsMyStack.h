#include "../MyQueue/clsMyQueue.h"
#include <iostream>
using namespace std;

template <class T>
class clsMyStack : public clsMyQueue <T>
{
    public:
        void Push(T Value)
        {
            clsMyQueue <T>::_MyList.InsertAtBeginning(Value);
        }

        void Print(void)
        {
            clsMyQueue <T>::Print();
        }

        int Size(void)
        {
            return (clsMyQueue <T>::Size());
        }

        T Top(void)
        {
            clsMyQueue <T>::Front();
        }

        T Bottom(void)
        {
            clsMyQueue <T>::Back();
        }

        void Pop(void)
        {
            clsMyQueue <T>::Pop();
        }

       
        T GetItem(T Index)
        {
            return (clsMyQueue <T>::GetItem(Index));
        }

        void Reverse(void)
        {
            clsMyQueue <T>::Reverse();
        }

        void UpdateItem(int Index, T value)
        {
            clsMyQueue <T>::UpdateItem(Index, value);
        }

        void InsertAfter(int Index, T Value)
        {
            clsMyQueue <T>::InsertAfter(Index, Value);
        }

        void InsertAtTop(int Value)
        {
            clsMyQueue <T>::InsertAtFront(Value);
        }

        void InsertAtBottom(int Value)
        {
            clsMyQueue <T>::InsertAtBack(Value);
        }

        void Clear(void)
        {
            clsMyQueue <T>::Clear();
        }



};