#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientFileName = "Clients.txt";

struct stBankAccount
{
    string AccountNum;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
};

namespace MyMain
{
    string ReadString(void)
    {
        string MyString;

        getline(cin, MyString);

        return (MyString);
    // Properly closing the namespace MyMain
    } // namespace MyMain


    string JoinString(vector <string> vString, string deli)
    {
        string S = "";

        for (string &i : vString)
        {
            S = S + i + deli;
        }

        return (S.substr(0, S.length() - deli.length()));
    }

    stBankAccount FillRecordData(void)
    {
        stBankAccount Account;
    
        cout << "Enter Account Number: ";
        getline(cin >> ws, Account.AccountNum);

        cout << "Enter PinCode: ";
        getline(cin, Account.PinCode);

        cout << "Enter your name: ";
        getline(cin, Account.Name);

        cout << "Enter phone number: ";
        getline(cin, Account.Phone);

        cout << "Enter Account balance: ";
        cin >> Account.AccountBalance;

        return (Account);
    }

    string ConvertRecordToLine(stBankAccount Account)
    {
        vector <string> vString;

        vString.push_back(Account.Name);
        vString.push_back(to_string(Account.AccountBalance));
        vString.push_back(Account.AccountNum);
        vString.push_back(Account.Phone);
        vString.push_back(Account.PinCode);

        return (JoinString(vString, "#//#"));
    }

    vector <string> SplitStringInVector(string S1, string deli)
    {
        short Pos = 0;
        string Token;
        vector <string> vTokens;

        while ((Pos = S1.find(deli)) != std::string::npos)
        {
            Token = S1.substr(0, Pos);

            if (Token != "")
            {
                vTokens.push_back(Token);
            }

            S1.erase(0, Pos + deli.length());
        }

        if (S1 != "")
        {
            vTokens.push_back(S1);
        }

        return (vTokens);
    }

    stBankAccount ConvertLineToRecord(string Line, string delimiter = "#//#")
    {
        stBankAccount Account;
        vector <string> vRecord;

        vRecord = SplitStringInVector(Line, delimiter);

        Account.Name = vRecord[0];
        Account.AccountBalance = stod(vRecord[1]);
        Account.AccountNum = vRecord[2];
        Account.Phone = vRecord[3];
        Account.PinCode = vRecord[4];

        return (Account);
    }

    void PrintClientRecord(stBankAccount Account)
    {
        cout << "|  " << left << setw(15) << Account.AccountNum;
        cout << "|  " << left << setw(10) << Account.PinCode;
        cout << "|  " << left << setw(40) << Account.Name;
        cout << "|  " << left << setw(12) << Account.Phone;
        cout << "|  " << left << setw(12) << Account.AccountBalance;
    }

    void PrintRecordData(stBankAccount Account)
    {
        cout << "\nThe following is the extracted client Record:" << endl;
        cout << "\nAccount number: " << Account.AccountNum << endl;
        cout << "Pin code: " << Account.PinCode << endl;
        cout << "Name: " << Account.Name << endl;
        cout << "Phone: " << Account.Phone << endl;
        cout << "Account Balance: " << Account.AccountBalance << endl;
    }

    void AppendToFile(string FileName, string Line)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void AddNewClient(void)
    {
        stBankAccount Account = FillRecordData();

        AppendToFile(ClientFileName, ConvertRecordToLine(Account));
    }

    void AddClientsToFile(void)
    {
        char AddMore = 'Y';

        do
        {
            system("cls");
            cout << "Adding new client:\n\n";

            AddNewClient();
            cout << "Client added successfully! do you want to add more clients? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');
    }

    vector <stBankAccount> LoadDataFromFileToVector(string ClientFileName)
    {
        vector <stBankAccount> vClients;
        fstream File;
        stBankAccount Client;
        string Line;

        File.open(ClientFileName, ios::in);

        if (File.is_open())
        {
            while (getline(File, Line))
            {
                Client = ConvertLineToRecord(Line);
                vClients.push_back(Client);
            }

            File.close();
        }
        return (vClients);
    }
    
    void PrintAllClientsData(vector <stBankAccount> vClients)
    {
        stBankAccount Client;

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") client(s).";
        cout <<"\n________________________________________________________";
        cout << "________________________________________\n" << endl;

        cout << "|  " << left << setw(15) << "Account Number";
        cout << "|  " << left << setw(10) << "Pin Code";
        cout << "|  " << left << setw(40) << "Client Name";
        cout << "|  " << left << setw(12) << "Phone";
        cout << "|  " << left << setw(12) << "Balance";
        cout << "\n______________________________________________________";
        cout << "__________________________________________\n" << endl;
 
        for (stBankAccount Client : vClients)
        {
            PrintClientRecord(Client);
            cout << endl;
        }
        cout << "\n______________________________________________________";
        cout << "__________________________________________\n" << endl;
    }

    string ReadAccountNumber(void)
    {
        string Num;
    
        cout << "Please enter account number: ";
        getline(cin, Num);

        return (Num);
    }

    bool FindClientData(string AccountNum, stBankAccount &Account, vector <stBankAccount> vAccounts)
    {
        vAccounts = LoadDataFromFileToVector(ClientFileName);
        
        for (stBankAccount Client : vAccounts)
        {
            if (Client.AccountNum == AccountNum)
            {
                Account = Client;
                return (true);
            }
        }
        return (false);
    }

    bool MarkClientToDelete(string AccountNumber, vector <stBankAccount> &vClient)
    {
        for (stBankAccount &C : vClient)
        {
            if  (C.AccountNum == AccountNumber)
            {
                C.MarkForDelete = true;
                return (true);
            }
        }
        return (false);
    }

    vector <stBankAccount> SaveClientToFile(string FileName, vector <stBankAccount> vClients)
    {
        fstream File;
        string ClientInfo;
    
        File.open(FileName, ios::out);

        if (File.is_open())
        {
            for (stBankAccount C: vClients)
            {
                if (C.MarkForDelete == false)
                {
                    ClientInfo = ConvertRecordToLine(C);
                    File << ClientInfo << endl;
                }
            }
            File.close();
        }
        return (vClients);
    }

    bool DeleteClientByNumber(string AccountNumber, vector <stBankAccount> &vAccount)
    {
        char DeleteOrNot = 'n';
        stBankAccount Client;

        if (FindClientData(AccountNumber, Client, vAccount))
        {
            PrintRecordData(Client);

            cout << "\nAre you sure you want to delete this client? (y/n)? ";
            cin >> DeleteOrNot;

            if (DeleteOrNot == 'y' || DeleteOrNot == 'Y')
            {
                MarkClientToDelete(AccountNumber, vAccount);
                SaveClientToFile(ClientFileName, vAccount);

                vAccount = LoadDataFromFileToVector(ClientFileName);
                cout << "\nClient deleted successfully." << endl;

                return (true);
            }
        }
        else
        {
            cout << "\nClient with account number (" << AccountNumber << ") is not found\n";
        }
        return (false);
    }
    
    stBankAccount ChangeClientData(string AccountNumber)
    {
        stBankAccount Account;

        Account.AccountNum = AccountNumber;

        cout << "Enter Pin Code: ";
        getline(cin >> ws, Account.PinCode);

        cout << "Enter Name: ";
        getline (cin, Account.Name);

        cout << "Enter phone number: ";
        getline (cin, Account.Phone);

        cout << "Enter Balance: ";
        cin >> Account.AccountBalance;

        return (Account);
    }
    bool MarkClientToUpdate(string AccountNumber, vector <stBankAccount> &vClient)
    {
        for (stBankAccount &C : vClient)
        {
            if (C.AccountNum == AccountNumber)
            {
                C = ChangeClientData(AccountNumber);
                break;
                return (true);
            }
        }
        return (false);
    }

    bool UpdateClientInfo(string AccountNumber, vector <stBankAccount> vClient)
    {
        char UpdateOrNot = 'n';
        stBankAccount Client;

        if (FindClientData(AccountNumber, Client, vClient))
        {
            PrintRecordData(Client);

            cout << "\nDo you want to update the information of this client? (y/n)? ";
            cin >> UpdateOrNot;

            if (UpdateOrNot == 'y' || UpdateOrNot == 'Y')
            {
                MarkClientToUpdate(AccountNumber, vClient);

                SaveClientToFile(ClientFileName, vClient);

                cout << "\nClient updated successfully.\n";
                return (true);
            }
            else
            {
                cout << "\nClient with account number (" << AccountNumber << ") not found" << endl;
            }
        }
        return (false);
    }
}