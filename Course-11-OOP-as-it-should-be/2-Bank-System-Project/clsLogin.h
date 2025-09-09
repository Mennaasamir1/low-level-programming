#pragma once
#include <iostream>
#include "clsUser.h"
#include "global.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsDate.h"

class clsLogin : protected clsScreen
{
    private:

        static bool _Login(void)
        {
            bool LoginFailed = false;
            string Username = "";
            string Password = "";
            short Trials = 4;

            do
            {
                if (LoginFailed)
                {
                    cout << "\nInvalid Username/Password.\n";
                    cout << "You have " << Trials - 1 << " trials to login.\n";
                    Trials--;
                }

                if (Trials == 0)
                {
                    cout << "\nYou are locked after 3 failed trials.\n";
                    return (false);
                }

                cout << "\nEnter username: ";
                cin >> Username;

                cout << "\nEnter password: ";
                cin >> Password;

                CurrentUser = clsUser::Find(Username, Password);

                LoginFailed = CurrentUser.IsEmpty();

            } while (LoginFailed);

            CurrentUser.SaveToLoginRegister();
            clsMainScreen::ShowMainMenu();
            
            return (true);
        }

        public:

            static bool ShowLoginScreen(void)
            {
                system("clear");

                _DrawHeader("\t  Login Screen");

                if (_Login())
                {
                    return (true);
                }
                else
                {
                    return (false);
                }
            }

};