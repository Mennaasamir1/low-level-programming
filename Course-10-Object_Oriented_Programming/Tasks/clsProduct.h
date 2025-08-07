#pragma once
#include <iostream>
using namespace std;

class clsProduct
{
    string _Name;
    float _Price;
    short _Quantity;

    public:
        clsProduct(string Name, float Price, short Quantity)
        {
            _Name = Name;
            _Price = Price;
            _Quantity = Quantity;
        }

        float GetTotalPrice(void)
        {
            return (_Price * _Quantity);
        }

        short Quantity(void)
        {
            return (_Quantity);
        }

        void DisplayProductInfo(void)
        {
            cout << _Name << " - " << "$" << _Price << " x " << _Quantity
                << "= " << "$" << GetTotalPrice() << endl;
        }
};