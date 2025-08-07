#pragma once
#include <iostream>
#include <vector>
#include "clsProduct.h"
#include "clsCart.h"
using namespace std;

enum enShoppingOptions
{
    enAdd = 1, enView = 2,
    enCheckOut = 3, enExit = 0
};



class clsStore
{
    public:
        clsCart Cart;

        int ReadChoice(void)
        {
            int Choice = 0;

            cout << "\nEnter Choice: ";
            cin >> Choice;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return ((enShoppingOptions)Choice);
        }

        void ShowMainMenu(void)
        {
            system("clear");
            cout << "\n=============================" << endl;
            cout << "Welcome to Mini shop!" << endl;
            cout << "\n=============================" << endl;

            cout << "\n\n[1] Add product to cart" << endl;
            cout << "[2] View cart" << endl;
            cout << "[3] Checkout\n";
            cout << "[0] Exit\n";
        }
       
        void HandleShoppingOptions(enShoppingOptions Choice)
        {
            switch (Choice)
            {
                case enShoppingOptions::enAdd:
                    Cart.EnterProductInfo();
                    break;

                case enShoppingOptions::enView:
                    Cart.ViewCart();
                    break;

                case enShoppingOptions::enCheckOut:
                    Cart.Checkout();
                    break;
            }
        }

        void StartShopping(void)
        {
            enShoppingOptions Choice;

            do
            {
                ShowMainMenu();
                Choice = (enShoppingOptions)ReadChoice();
                HandleShoppingOptions(Choice);
                
            } while (Choice != enShoppingOptions::enExit);

            cout << "Exiting Mini Shop. Goodbye!\n";
        }
    
};
