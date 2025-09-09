#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include "global.h"
using namespace std;

class clsBankClient : public clsPerson
{
    private:
        enum enMode {EmptyMode = 0, UpdateMode = 1, AddNew = 2};
        enMode _Mode;

        string _AccountNumber;
        string _PinCode;
        float _AccountBalance;
        bool _MarkForDel = false;

        

        static clsBankClient _ConvertLineToClientObject(string Line)
        {
            /* convert the string to vector then to object */
            vector <string> vClient = clsString::Split(Line, "#//#");

            return (clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
                vClient[3], vClient[5], vClient[4], stod(vClient[6])));
        }

        static string _ConvertObjectToLine(clsBankClient Client, string Sep = "#//#")
        {
            string NewString = "";

            NewString += Client.FirstName() + Sep;
            NewString += Client.LastName() + Sep;
            NewString += Client.Email() + Sep;
            NewString += Client.Phone() + Sep;
            NewString += Client.AccountNumber() + Sep;
            NewString += Client.PinCode() + Sep;
            NewString += to_string(Client.AccountBalance());

            return (NewString);
        }

        static clsBankClient _GetEmptyClientObject(void)
        {
            return (clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0));
        }

        static vector <clsBankClient> _LoadDataFromFile(void)
        {
            vector <clsBankClient> vClients;
            string Line;
            fstream File;

            File.open("Clients.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(Line);
                    vClients.push_back(Client);
                }

                File.close();
            }

            return (vClients);
        }

        static void _SaveClientsToFile(vector <clsBankClient> vClient)
        {
            fstream File;
            string Line;

            File.open("Clients.txt", ios::out);

            if (File.is_open())
            {
                for (clsBankClient &C : vClient)
                {
                    Line = _ConvertObjectToLine(C);

                    File << Line << endl;
                }

                File.close();
            }
        }

        void _SaveToFile(vector <clsBankClient> vClients)
        {
            fstream File;
            string Line;

            File.open("Clients.txt", ios::out);

            if (File.is_open())
            {
                for (clsBankClient &C : vClients)
                {
                    if (C._MarkForDel == false)
                    {
                        Line = _ConvertObjectToLine(C);
                        File << Line << endl;
                    }
                }
                File.close();
            }
        }

        string _PrepareTransferLineRecord(clsBankClient C2, double Amount, string UserName)
        {
            string Line = "";
            string Sep = "#//#";

            Line = clsDate::GetSystemDateAndTime() + Sep;
            Line += AccountNumber() + Sep;
            Line += C2.AccountNumber() + Sep;
            Line += to_string(Amount) + Sep;
            Line += to_string(AccountBalance()) + Sep;
            Line += to_string(C2.AccountBalance()) + Sep;
            Line += UserName;

            return (Line);
        }

        void _UpdateClient(void)
        {
            vector <clsBankClient> vClients = _LoadDataFromFile();

            for (clsBankClient &C : vClients)
            {
                if (C.AccountNumber() == AccountNumber())
                {
                    C = *this;
                    break;
                }
            }
            _SaveClientsToFile(vClients);
        }

        void _AddToFile(string Line)
        {
            fstream File;

            File.open("Clients.txt", ios::out | ios::app);

            if (File.is_open())
            {
                File << Line << endl;

                File.close();
            }
        }

        void _AddNewClient(void)
        {
            _AddToFile(_ConvertObjectToLine(*this));
        }

        


    public:

        clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
            string PinCode, string AccountNum, float AccountBalance) : 
            clsPerson(FirstName, LastName, Email, Phone)
        {
            _Mode = Mode;
            _AccountNumber = AccountNum;
            _PinCode = PinCode;
            _AccountBalance = AccountBalance;
        }

        struct stTransferLog
        {
            string DateTime, SourceAccount, DestAccount, UserName;
            double Amount;
            double SourceBalance;
            double DestBalance;
        };


        static stTransferLog ConvertLineToTransferRecord(string Line)
        {
            stTransferLog TransferLog;
            vector<string> vLogs = clsString::Split(Line, "#//#");

            TransferLog.DateTime = vLogs[0];
            TransferLog.SourceAccount = vLogs[1];
            TransferLog.DestAccount = vLogs[2];
            TransferLog.Amount = stoi(vLogs[3]);
            TransferLog.SourceBalance = stoi(vLogs[4]);
            TransferLog.DestBalance = stoi(vLogs[5]);
            TransferLog.UserName = vLogs[6];

            return (TransferLog);
        }

        static vector <stTransferLog> _LoadTransferLogFromFile(void)
        {
            fstream File;
            string Line;
            vector <stTransferLog> vLogs;

            File.open("TransferLog.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    stTransferLog Log = ConvertLineToTransferRecord(Line);
                    vLogs.push_back(Log);
                }
                File.close();
            }
            return (vLogs);
        }

        string AccountNumber(void)
        {
            return (_AccountNumber);
        }

        void SetPinCode(string PinCode)
        {
            _PinCode = PinCode;
        }
        string PinCode(void)
        {
            return (_PinCode);
        }

        void SetAccountBalance(float AccountBalance)
        {
            _AccountBalance = AccountBalance;
        }
        float AccountBalance(void)
        {
            return (_AccountBalance);
        }

        bool IsEmpty(void)
        {
            return (_Mode == enMode::EmptyMode);
        }

        void Print(void)
        {
            cout << "\nClient Card:";
            cout << "\n_______________________________";
            cout << "\nFirst Name   : " << FirstName();
            cout << "\nLast Name    : " << LastName();
            cout << "\nFull Name    : " << FullName();
            cout << "\nEmail        : " << Email();
            cout << "\nPhone        : " << Phone();
            cout << "\nAcc. Number  : " << _AccountNumber;
            cout << "\nPassword     : " << PinCode();
            cout << "\nBalance      : " << AccountBalance();
            cout << "\n_______________________________\n";
        }

        static clsBankClient Find(string AccountNumber)
        {
            vector<clsBankClient> vClient;
            fstream File;
            string Line;

            File.open("Clients.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    /* convert the string to vector then to object */
                    clsBankClient Client = _ConvertLineToClientObject(Line);

                    if (Client.AccountNumber() == AccountNumber)
                    {
                        File.close();
                        return (Client);
                    }
                    /*vClient.push_back(Client);*/
                }
                File.close();
            }
            return (_GetEmptyClientObject());
        }

        static clsBankClient Find(string AccountNumber, string PinCode)
        {
            vector <clsBankClient> vClients;
            fstream File;
            string Line;

            File.open("Clients.txt", ios::in);

            if (File.is_open())
            {
                while (getline(File, Line))
                {
                    clsBankClient Client = _ConvertLineToClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber 
                        &&
                        Client.PinCode() == PinCode)
                    {
                        File.close();
                        return (Client);
                    }
                    vClients.push_back(Client);
                }
                File.close();
            }
            return (_GetEmptyClientObject());
        }

        static bool IsClientExist(string AccountNumber)
        {
            clsBankClient Client = Find(AccountNumber);

            return (!Client.IsEmpty());
        }

        static clsBankClient GetNewClient(string AccountNumber)
        {
            return (clsBankClient(enMode::AddNew, "", "", "", "", "", AccountNumber, 0));
        }

        enum enSavedResult {svEmptyObject = 0, svSuccedded = 1};

        enSavedResult SaveInfo(void)
        {
            switch (_Mode)
            {
                case enMode::EmptyMode:
                    return (enSavedResult::svEmptyObject);

                case enMode::UpdateMode:
                    _UpdateClient();
                    return (enSavedResult::svSuccedded);
                    break;

                case enMode::AddNew:
                    if (IsClientExist(_AccountNumber))
                    {
                        return (enSavedResult::svEmptyObject);
                    }
                    else
                    {
                        _AddNewClient();
                        _Mode = enMode::UpdateMode;
                        return (enSavedResult::svSuccedded);
                    }
            }
            return (enSavedResult::svEmptyObject);
        }

        void Delete(void)
        {
            vector <clsBankClient> vClients = _LoadDataFromFile();
    
            for (clsBankClient &C : vClients)
            {
                if (C.AccountNumber() == AccountNumber())
                {
                    C._MarkForDel = true;
                    break;
                }
            }
            _SaveToFile(vClients);
            *this = _GetEmptyClientObject();
        }

        static vector <clsBankClient> GetClientsList(void)
        {
            return (_LoadDataFromFile());
        }

        static float GetTotalBalances(void)
        {
            float TotalBalances = 0;

            vector <clsBankClient> vClients = _LoadDataFromFile();

            for (clsBankClient &C : vClients)
            {
                TotalBalances += C.AccountBalance();
            }
            return (TotalBalances);
        }

        void Deposit(double Amount)
        {
            _AccountBalance += Amount;
            SaveInfo(); /* to activate the update mode => to update balance. */
        }

        bool Withdraw(double Amount)
        {

            if (Amount > AccountBalance())
            {
                return (false);
            }
            _AccountBalance -= Amount;
            SaveInfo(); /* to activate the update mode => to update balance. */
            return (true);
        }

        void SaveToTransferLog(clsBankClient C2, double Amount, string UserName)
        {
            fstream File;
            string Line;

            Line = _PrepareTransferLineRecord(C2, Amount, UserName);

            File.open("TransferLog.txt", ios::out | ios::app);

            if (File.is_open())
            {
                File << Line << endl;

                File.close();
            }
        }

        bool Transfer(double Amount, clsBankClient &DestClient)
        {
            if (Amount > AccountBalance())
            {
                return (false);
            }
            else
            {
                Withdraw(Amount);
                DestClient.Deposit(Amount);
                SaveToTransferLog(DestClient, Amount, CurrentUser.Username());

                return (true);
            }
        }

        static vector <stTransferLog> GetTransferLog(void)
        {
            return (_LoadTransferLogFromFile());
        }
};