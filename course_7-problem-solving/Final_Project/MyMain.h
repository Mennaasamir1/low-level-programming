#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

const string ClientFileName = "Client.txt";
enum enList 
{
    Show = 1, Add = 2,
    Delete = 3, Update = 4,
    Find = 5, Transactions = 6,
    Exit = 7
};

enum enTrans
{
    Deposit = 1, Withdraw = 2, TotalBalances = 3, Main = 4
};


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
    vector <stBankAccount> LoadDataFromFileToVector(string ClientFileName);

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

    bool ClientExistsOrNot(string AccountNum, string FileName);

    stBankAccount FillRecordData(void)
    {
        stBankAccount Account;
    
        cout << "Enter Account Number: ";
        getline(cin >> ws, Account.AccountNum);

        while (ClientExistsOrNot(Account.AccountNum, ClientFileName))
        {
            cout << "Client with account number " << Account.AccountNum << " already exits. Enter another account number: ";
            getline(cin, Account.AccountNum);
        }

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

    bool ClientExistsOrNot(string AccountNum, string FileName)
    {
        vector <stBankAccount> vFile = LoadDataFromFileToVector(ClientFileName);
        stBankAccount Clients;
        fstream File;
        string Line;

        File.open(ClientFileName, ios::in);

        if (File.is_open())
        {
            while (getline(File, Line))
            {
                Clients = ConvertLineToRecord(Line);
            
                if (Clients.AccountNum == AccountNum)
                {
                    File.close();
                    return (true);
                }
                vFile.push_back(Clients);
            }

            File.close();
        }
        return (false);
    }

    void AddNewClient(void)
    {
        stBankAccount Account = FillRecordData();

        AppendToFile(ClientFileName, ConvertRecordToLine(Account));
    }

    void AddClientsToFile(void)
    {
        char AddMore = 'Y';

        cout << "--------------------------------------------\n";
        cout << "\t\tAdd New Clients Screen\n";
        cout << "--------------------------------------------\n";
        cout << "Adding New Client:" << endl;

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

    double CalculateTotalBalances(vector <stBankAccount> vClients)
    {
        double Count = 0;
    
        for (stBankAccount C : vClients)
        {
            Count += C.AccountBalance;
        }
        return (Count);
    }

    void PrintAllClientsData(vector <stBankAccount> vClients)
    {
        vClients = LoadDataFromFileToVector(ClientFileName);
        stBankAccount Client;
        double Total = 0;

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

        if (vClients.size() == 0)
        {
            cout << "\nNo Clients Available in this system." << endl;
        }
 
        for (stBankAccount Client : vClients)
        {
            PrintClientRecord(Client);
            Total += Client.AccountBalance;
            cout << endl;
        }
        cout << "\n______________________________________________________";
        cout << "__________________________________________\n" << endl;
        cout << "\t\t\tTotal Balances = " << Total << endl;
    }

    string ReadAccountNumber(void)
    {
        string Num;
    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cout << "Client with account number (" << AccountNumber << ") is not found." << endl;
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
        }
        else
        {
            cout << "Client with account number (" << AccountNumber << ") is not found." << endl;
        }
        return (false);
    }


    void ShowMainMenuScreen(void);

    
    void ShowEndProgram(void)
    {
        cout << "\nProgram exited\n";
    }

    enList ReadChoice(void)
    {
        short ChoiceOfUser;

        cout << "\nWhat do you want to do? ";
        cin >> ChoiceOfUser;

        return ((enList) ChoiceOfUser);
    }

    void GoBackToMainMenu(void)
    {
        cin.ignore();
        cout << "\nPress Any key to go back to main menu...";
        std::cin.get();
        ShowMainMenuScreen();
    }

    void ShowDeleteClientScreen(void)
    {
        cout << "---------------------------------------\n";
        cout << "\t\tDelete Client screen\n";
        cout << "---------------------------------------\n";

        vector <stBankAccount> vString = LoadDataFromFileToVector(ClientFileName);
        string AccountNumber = ReadAccountNumber();
        
        DeleteClientByNumber(AccountNumber, vString);
    }

    void ShowUpdateClientScreen(void)
    {
        vector <stBankAccount> vClient = LoadDataFromFileToVector(ClientFileName);
        string AccountNumber;

        cout << "---------------------------------------\n";
        cout << "\t\tUpdate Client Screen" << endl;
        cout << "---------------------------------------\n";

        AccountNumber = ReadAccountNumber();

        UpdateClientInfo(AccountNumber, vClient);
    }

    void ShowFindClientScreen(void)
    {
        vector <stBankAccount> vClient;
        string AccountNum;
        stBankAccount Client;

        cout << "----------------------------------------\n";
        cout << "\t\tFind Client Screen" << endl;
        cout << "----------------------------------------\n";

        vClient = LoadDataFromFileToVector(ClientFileName);
        AccountNum = ReadAccountNumber();

        if (FindClientData(AccountNum, Client, vClient))
        {
            PrintRecordData(Client);
        }
        else
        {
            cout << "\nClient with account number (" << AccountNum << ") is not found." << endl;
        }

    }

    void ShowTransactionsScreen(void);
    bool DepositMoney(string AccountNum, vector <stBankAccount> &vClient);
    void GoBackToTransactionScreen(void);


    void ShowTotalBalancesScreen(void)
    {

    }
    void ShowDepositScreen(void)
    {
        vector vClient = LoadDataFromFileToVector(ClientFileName);
        string AccountNumber;

        cout << "-----------------------------------\n";
        cout << "\t\tDeposit Screen\n";
        cout << "-----------------------------------\n";

        AccountNumber = ReadAccountNumber();

        DepositMoney(AccountNumber, vClient); // Ensure this matches the intended overload
    }

    void GoBackToTransactionScreen(void)
    {
        cin.ignore();
        cout << "\nPress any key to go back to the transactions screen...";
        std::cin.get();
        ShowTransactionsScreen();
    }


    bool DepositMoney(string AccountNum, vector <stBankAccount> &vClient)
    {
        stBankAccount Client;
        double DepositAmount;
        char DepositOrNot = 'y';

        if (FindClientData(AccountNum, Client, vClient))
        {
            PrintRecordData(Client);

            cout << "\nPlease enter deposit amount: ";
            cin >> DepositAmount;

            cout << "\nAre you sure to want to perform this transaction? ";
            cin >> DepositOrNot;

            if (DepositOrNot == 'y' || DepositOrNot == 'Y')
            {
                for (stBankAccount &C : vClient)
                {
                    if (C.AccountNum == AccountNum)
                    {
                        C.AccountBalance += DepositAmount;
                        SaveClientToFile(ClientFileName, vClient);
                        cout << "\nDone successfully! Your new balance is: "
                        << C.AccountBalance << endl;
                        return (true);
                    }
                }
            }
        }

        else
        {
            cout << "\nClient with account number (" << AccountNum << ") is not found\n";
        }
        return (false);
    }

    bool WithDrawMoney(string AccountNumber, vector <stBankAccount> &vClient)
    {
        stBankAccount Client;
        double WithdrawAmount;
        char WithdrawOrNot = 'y';

        if (FindClientData(AccountNumber, Client, vClient))
        {
            PrintRecordData(Client);

            cout << "\nPlease enter withdraw amount: ";
            cin >> WithdrawAmount;

            cout << "\nAre you sure to want to perform this transaction? ";
            cin >> WithdrawOrNot;

            if (WithdrawOrNot == 'y' || WithdrawOrNot == 'Y')
            {
                while (WithdrawAmount > Client.AccountBalance)
                {
                    cout << "\nAmount Exceeds the balance. You can only withdraw up to "
                        << Client.AccountBalance << "\nPlease enter amount: ";
                    cin >> WithdrawAmount;
                }

                for (stBankAccount C : vClient)
                {
                    if (C.AccountNum == AccountNumber)
                    {
                        C.AccountBalance -= WithdrawAmount;
                        SaveClientToFile(ClientFileName, vClient);
                        cout << "\nDone successfully! Your account balance is " << C.AccountBalance << endl;
                        return (true);
                    }
                }
            }
        }
        else
        {
            cout << "\nClient with account number (" << AccountNumber << ") is not found\n";
        }
        return (false);
    }

    void ShowWithdrawScreen(void)
    {
        string AccountNum;
        vector <stBankAccount> vClient;

        vClient = LoadDataFromFileToVector(ClientFileName);

        cout << "---------------------------------------\n";
        cout << "\t\tWithdraw Screen\n";
        cout << "---------------------------------------\n";

        AccountNum = ReadAccountNumber();
        WithDrawMoney(AccountNum, vClient);
    }

    void ShowTotalBalances(vector <stBankAccount> vClient)
    {
        stBankAccount Client;
        double Total = 0;

        cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ") client(s).";
        cout <<"\n________________________________________________________";
        cout << "________________________________________\n" << endl;

        cout << "|  " << left << setw(15) << "Account Number";
        cout << "|  " << left << setw(10) << "Pin Code";
        cout << "|  " << left << setw(40) << "Client Name";
        cout << "|  " << left << setw(12) << "Phone";
        cout << "|  " << left << setw(12) << "Balance";
        cout << "\n______________________________________________________";
        cout << "__________________________________________\n" << endl;

        if (vClient.size() == 0)
        {
            cout << "\nNo Clients Available in this system." << endl;
        }
 
        for (stBankAccount Client : vClient)
        {
            PrintClientRecord(Client);
            Total += Client.AccountBalance;
            cout << endl;
        }
        cout << "\n______________________________________________________";
        cout << "__________________________________________\n" << endl;
        cout << "\t\t\tTotal Balances = " << Total << endl;
    }

    void PerformTransactions(enTrans Transaction)
    {
        vector <stBankAccount> vClient = LoadDataFromFileToVector(ClientFileName);
        stBankAccount Client;

        switch(Transaction)
        {
            case enTrans::Deposit:
                system("clear");
                ShowDepositScreen();
                GoBackToTransactionScreen();
                break;

            case enTrans::Withdraw:
                system("clear");
                ShowWithdrawScreen();
                GoBackToTransactionScreen();
                break;

            case enTrans::Main:
                system("clear");
                GoBackToMainMenu();
                break;
            
            case enTrans::TotalBalances:
                system("clear");
                ShowTotalBalances(vClient);
                GoBackToTransactionScreen();
                break;
        }


    }
    void ShowTransactionsScreen(void)
    {
        system("clear");
        cout << "==========================================\n";
        cout << "\t\tTransactions Screen" << endl;
        cout << "==========================================\n";
        cout << "\t\t[1] Deposit.\n";
        cout << "\t\t[2] Withdraw.\n";
        cout << "\t\t[3] Total Balances.\n";
        cout << "\t\t[4] Main Menu.\n";
        cout << "==========================================\n";

        PerformTransactions((enTrans)ReadChoice());
    }

    
    void ExecuteProgram(enList Choice)
    {
        stBankAccount Account;
        vector <stBankAccount> vFile = LoadDataFromFileToVector(ClientFileName);
        

        switch (Choice)
        {
            case enList::Add:
                system("clear");
                AddClientsToFile();
                GoBackToMainMenu();
                break;
            
            case enList::Delete:
                system("clear");
                ShowDeleteClientScreen();
                GoBackToMainMenu();
                break;
            
            case enList::Show:
                system("clear");
                PrintAllClientsData(vFile);
                GoBackToMainMenu();
                break;
            
            case enList::Update:
                system("clear");
                ShowUpdateClientScreen();
                GoBackToMainMenu();
                break;
            
            case enList::Find:
                system("clear");
                ShowFindClientScreen();
                GoBackToMainMenu();
                break;

            case enList::Transactions:
                system("clear");
                ShowTransactionsScreen();
                GoBackToMainMenu();
                break;

            case enList::Exit:
                system("clear");
                ShowEndProgram();
                break;
        }
    }

    void ShowMainMenuScreen(void)
    {
        system("clear");
        cout << "==============================================\n";
        cout << "\t\tMain Menu screen\n";
        cout << "==============================================\n";
        cout << "\t\t[1] Show clients list\n";
        cout << "\t\t[2] Add new clients\n";
        cout << "\t\t[3] Delete client\n";
        cout << "\t\t[4] Update client\n";
        cout << "\t\t[5] Find client\n";
        cout << "\t\t[6] Transactions\n";
        cout << "\t\t[7] Exit\n";
        cout << "==============================================\n";

        ExecuteProgram(ReadChoice());
    }



}