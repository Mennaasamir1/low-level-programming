#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsString.h"

class clsUser : public clsPerson
{
    enum _enMode {enEmpty = 1, enUpdate = 2, enAdd = 3};

    string _UserName;
    string _Password;
    int _Permissions;
    _enMode _Mode;
    bool _MarkForDelete = false;

   
       
        string PerpareLoginRecord(string Sep = "#//#")
        {
            string Line = "";

            Line = clsDate::GetSystemDateAndTime() + Sep;
            Line += _UserName + Sep;
            Line += clsUtil::EncryptText(_Password) + Sep;
            Line += to_string(_Permissions);

            return (Line);
        }
    

    static clsUser _ConvertLineToObject(string Line)
    {
        vector <string> vUsers = clsString::Split(Line, "#//#");

        return (clsUser(_enMode::enUpdate, vUsers[0], vUsers[1], vUsers[2],
            vUsers[3], vUsers[4], clsUtil::decryptText(vUsers[5]), stoi(vUsers[6])));
    }

    static string _ConverObjectToLine(clsUser User, string deli = "#//#")
    {
        string Line = "";

        Line += User.FirstName() + deli;
        Line += User.LastName() + deli;
        Line += User.Email() + deli;
        Line += User.Phone() + deli;
        Line += User.Username() + deli;
        Line += clsUtil::EncryptText(User.Password()) + deli;
        Line += to_string(User.Permissions());

        return (Line);
    }

    static clsUser _GetEmptyObject(void)
    {
        return (clsUser(_enMode::enEmpty, "", "", "", "", "", "", 0));
    }

    static vector <clsUser> _LoadData(void)
    {
        fstream File;
        string Line;
        vector <clsUser> vUsers;

        File.open("Users.txt", ios::in);

        if (File.is_open())
        {
            while (getline(File, Line))
            {
                clsUser User = _ConvertLineToObject(Line);
                vUsers.push_back(User);
            }
            File.close();
        }

        return (vUsers);
    }


    static void SaveToFile(vector <clsUser> vUsers)
    {
        fstream File;
        string Line;

        File.open("Users.txt", ios::out);

        if (File.is_open())
        {
            for (clsUser &User : vUsers)
            {
                Line = _ConverObjectToLine(User);
                File << Line << endl;
            }
            File.close();
        }
    }

    void SaveExistentUsers(vector <clsUser> vUsers)
    {
        fstream File;
        string Line;

        File.open("Users.txt", ios::out);

        if (File.is_open())
        {
            for (clsUser &User : vUsers)
            {
                if (User._MarkForDelete == false)
                {
                    Line = _ConverObjectToLine(User);
                    File << Line << endl;
                }
            }
            File.close();
        }
    }

    void _Update(void)
    {
        vector <clsUser> vUsers = _LoadData();

        for (clsUser &User : vUsers)
        {
            if (User.Username() == Username())
            {
                User = *this;
                break;
            }
        }
        SaveToFile(vUsers);
    }

    void _AddToFile(string Line)
    {
        fstream File;

        File.open("Users.txt", ios::out | ios::app);

        if (File.is_open())
        {
            File << Line << endl;

            File.close();
        }
    }

    void _AddNewUser(void)
    {
        _AddToFile(_ConverObjectToLine(*this));
    }



    public:

        struct stLoginRegister
        {
            string DateTime;
            string UserName;
            string Password;
            int Permissions;
        };


        enum enPermissions
        {
            enAll = -1, pList = 1, pAdd = 2, pDelete = 4,
            pUpdate = 8, pFind = 16, pTransactions = 32,
            pManageUsers = 64, pShowLoginRegister = 128
        };

        clsUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone,
            string UserName, string Password, int Permissions) :
            clsPerson(FirstName, LastName, Email, Phone)
        {
            _Mode = Mode;
            _UserName = UserName;
            _Password = Password;
            _Permissions = Permissions;
        }

        void SetUserName(string Username)
        {
            _UserName = Username;
        }
        string Username(void)
        {
            return (_UserName);
        }

        void SetPassword(string Password)
        {
            _Password = Password;
        }
        string Password(void)
        {
            return (_Password);
        }

        void SetPermission(int Permissions)
        {
            _Permissions = Permissions;
        }
        int Permissions(void)
        {
            return (_Permissions);
        }

        bool IsEmpty(void)
        {
            return (_Mode == _enMode::enEmpty);
        }

        static clsUser Find(string UserName)
        {
            fstream File;
            string Line;

            File.open("Users.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    clsUser User = _ConvertLineToObject(Line);

                    if (User.Username() == UserName)
                    {
                        File.close();
                        return (User);
                    }
                }
                File.close();
            }
            return (_GetEmptyObject());
        }

        static clsUser Find(string Username, string Password)
        {
            fstream File;
            string Line;

            File.open("Users.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    clsUser User = _ConvertLineToObject(Line);

                    if (User.Username() == Username
                        && User.Password() == Password)
                    {
                        File.close();
                        return (User);
                    }
                }
                File.close();
            }
            return (_GetEmptyObject());
        }

        static bool DoesUserExist(string Username)
        {
            clsUser User = Find(Username);

            return (!User.IsEmpty());
        }

        static clsUser GetNewUser(string Username)
        {
            return (clsUser(_enMode::enAdd, "", "", "", "", Username, "", 0));
        }

        enum enSavedResult {enFailed = 1, enSuccessful = 2, enExists = 3};

        enSavedResult Save(void)
        {
            switch (_Mode)
            {
                case _enMode::enEmpty:
                {
                    return (enSavedResult::enFailed);
                }

                case _enMode::enUpdate:
                {
                    _Update();
                    return (enSavedResult::enSuccessful);
                    break;
                }
                case _enMode::enAdd:
                {
                    if (DoesUserExist(_UserName))
                    {
                        return (enSavedResult::enExists);
                    }
                    else
                    {
                        _AddNewUser();
                        _Mode = _enMode::enUpdate;
                        return (enSavedResult::enSuccessful);
                    }
                }
            }
            return (enSavedResult::enFailed);
        }

        static vector <clsUser> GetUsersList(void)
        {
            return (_LoadData());
        }

        void Delete(void)
        {
            vector <clsUser> vUsers = _LoadData();

            for (clsUser &User : vUsers)
            {
                if (User.Username() == Username())
                {
                    User._MarkForDelete = true;
                    break;
                }
            }
            SaveExistentUsers(vUsers);
            *this = _GetEmptyObject();
        }

        bool CheckPermissionAccess(enPermissions Permissions)
        {
            if (Permissions == enPermissions::enAll)
            {
                return (true);
            }

            if ((Permissions & this->Permissions()) == Permissions)
            {
                return (true);
            }
            else
            {
                return (false);
            }
        }

        void SaveToLoginRegister(void)
        {
            string Line = PerpareLoginRecord();
            fstream File;
           
            File.open("LoginRegister.txt", ios::out | ios::app);

            if (File.is_open())
            {

                File << Line << endl;

                File.close();
            }
        }

        static stLoginRegister ConvertLoginUserToRecord(string Line, string Sep = "#//#")
        {
            vector <string> vInfo = clsString::Split(Line, Sep);
            stLoginRegister LoginRegister;

            LoginRegister.DateTime = vInfo[0];
            LoginRegister.UserName = vInfo[1];
            LoginRegister.Password =  clsUtil::decryptText(vInfo[2]);
            LoginRegister.Permissions = stoi(vInfo[3]);

            return (LoginRegister);
        }

        static vector <stLoginRegister> LoadLoginUsersToFile(void)
        {
            fstream File;
            string Line;
            stLoginRegister LoginRegister;
            vector <stLoginRegister> vLoginUsers;

            File.open("LoginRegister.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    LoginRegister = ConvertLoginUserToRecord(Line);
                    vLoginUsers.push_back(LoginRegister);
                }
                File.close();
            }
            return (vLoginUsers);
        }
        

};