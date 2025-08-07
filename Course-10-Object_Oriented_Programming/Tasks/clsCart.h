#pragma once
#include <iostream>
#include <vector>
#include "clsProduct.h"
#include <limits>
using namespace std;

class clsCart
{
    vector <clsProduct> vProductItems;

    public:
        void AddProductsToCart(clsProduct &Product)
        {
            vProductItems.push_back(Product);
            cout << "\nProduct added to cart!" << endl;
        }

        void EnterProductInfo(void)
        {
            string Name;
            float Price;
            short Quantity;

            cout << "\nEnter Product Name: ";
            getline(cin, Name);

            cout << "Enter Product price: ";
            cin >> Price;

            cout << "Enter Product quantity: ";
            cin >> Quantity;

            cin.ignore();

            clsProduct Product(Name, Price, Quantity);
            AddProductsToCart(Product);
        }

        void ViewCart(void)
        {
            short ItemsNum = 0;
            short index = 0;
            float TotalPrice = 0;

            if (vProductItems.empty())
            {
                cout << "\nYour cart is empty. any products you add will show here.\n";
                //return;
            }

            else
            {
                cout << "\nYour Cart:\n";
                cout << "----------------------------\n";
                for (clsProduct &i : vProductItems)
                {
                    index++;
                    cout << index << ". ";
                    i.DisplayProductInfo();
                    TotalPrice += i.GetTotalPrice();
                    ItemsNum += i.Quantity();
                }
                cout << "----------------------------\n";
                cout << "\nTotal items: " << ItemsNum << endl;
                cout << "Total Price: " << TotalPrice << endl;
            }
            string dummy;
            getline(cin, dummy); 
        }

        void Checkout(void)
        {
            float TotalPrice = 0;

            if (vProductItems.empty())
            {
                cout << "\nYour cart is empty. Add items first.\n";
                //return;
            }

            else
            {
                cout << "Checkout\n";
                cout << "------------------------\n";
                for (clsProduct &i : vProductItems)
                {
                    i.DisplayProductInfo();
                    TotalPrice += i.GetTotalPrice();
                }
                cout << "--------------------------\n";
                cout << "\nTotal to pay: " << TotalPrice << endl;
                cout << "\n\nThanks for shopping with us!" << endl;
                cout << "Have a great day!" << endl;
            }

            string dummy;
            getline(cin, dummy); 
        }
};