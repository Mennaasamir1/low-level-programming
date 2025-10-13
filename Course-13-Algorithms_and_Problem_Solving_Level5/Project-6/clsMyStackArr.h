#include <iostream>
#include "../Project-5/clsMyQueueArr.h"
using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr <T>
{

    public:
        void Push(T Value)
        {
            clsMyQueueArr<T>::_MyArray.InsertAtBeginning(Value);
        }


        T Top(void)
        {
            return (clsMyQueueArr<T>::GetItem(0));
        }

        T Bottom(void)
        {
            return (clsMyQueueArr<T>::Back());
        }
};
