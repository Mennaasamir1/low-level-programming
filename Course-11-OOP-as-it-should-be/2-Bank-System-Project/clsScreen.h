#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "global.h"
using namespace std;

class clsScreen
{
    protected:

       
        static void _DrawHeader(string String1, string String2 = "")
        {
            clsDate Date;
            cout << "\t\t\t\t\t_____________________________________________"<< endl;
            cout << "\n\n\t\t\t\t\t" << String1 << endl;

            if (String2 != "")
            {
                cout << "\t\t\t\t\t" << String2 << endl;
            }
            cout << "\n\t\t\t\t\t_____________________________________________"<< endl;

            cout << "\t\t\t\t\t       User: ";
            cout << CurrentUser.Username() << endl;
            cout << "\t\t\t\t\t       Date:";
            Date.Print();
        }

        static bool CheckPermissionRights(clsUser::enPermissions Permissions)
        {
            if (!CurrentUser.CheckPermissionAccess(Permissions))
            {
                cout << "\t\t\t\t\t______________________________";
                cout << "\n\n\t\t\t\t\t\tAccess Denied\n";
                cout << "\t\t\t\t\t______________________________\n";
                return (false);
            }
            else
            {
                return (true);
            }
        }
};