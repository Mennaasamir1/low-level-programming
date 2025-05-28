#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

const string ClientFileName = "Client.txt";
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

stBankAccount LoggedInClient;

enum enAtmOptions
{
    QuickWithdraw = 1, NormalWithdraw = 2,
    Deposit = 3, CheckBalance = 4,
    Logout = 5
};

enum enQuickWithdraw
{
    Twenty =  1, Fifty = 2,
    Hundred = 3, TwoHundred = 4,
    FourHundred = 5, SixHundred = 6,
    EightHundred = 7, Thousand = 8,
    Exit = 9
};

enum enQuickWithdrawAmount
{
    enTwenty =  20, enFifty = 50,
    enHundred = 100, enTwoHundred = 200,
    enFourHundred = 400, enSixHundred = 600,
    enEightHundred = 800, enThousand = 1000,
};

namespace System
{
    void GoBackToMainMenu(void);
    void ShowMainMenuScreen(void);
    void ExecuteATM(enAtmOptions Option);
    void Login(void);
    bool FindClientByNumberAndPN(string AccountNum, string PIN, stBankAccount &LoggedInClient);
    void ShowQuickWithdrawMenu(void);
    void ShowNormalWithdrawScreen(void);
    void ShowDepositScreen(void);


    string JoinString(vector<string> vString, string deli)
    {
        string S = "";

        for (string &i : vString)
        {
            S = S + i + deli;
        }

        return (S.substr(0, S.length() - deli.length()));
    }

    string ConvertRecordToLine(stBankAccount Account)
    {
        vector<string> vString;

        vString.push_back(Account.Name);
        vString.push_back(to_string(Account.AccountBalance));
        vString.push_back(Account.AccountNum);
        vString.push_back(Account.Phone);
        vString.push_back(Account.PinCode);

        return (JoinString(vString, "#//#"));
    }

    vector<stBankAccount> SaveClientToFile(string FileName, vector<stBankAccount> vClients)
    {
        fstream File;
        string ClientInfo;

        File.open(FileName, ios::out);

        if (File.is_open())
        {
            for (stBankAccount C : vClients)
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

    vector<string> SplitStringInVector(string S1, string deli)
    {
        short Pos = 0;
        string Token;
        vector<string> vTokens;

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
        vector<string> vRecord;

        vRecord = SplitStringInVector(Line, delimiter);

        Account.Name = vRecord[0];
        Account.AccountBalance = stod(vRecord[1]);
        Account.AccountNum = vRecord[2];
        Account.Phone = vRecord[3];
        Account.PinCode = vRecord[4];

        return (Account);
    }

    vector<stBankAccount> LoadDataFromFileToVector(string ClientFileName)
    {
        vector<stBankAccount> vClients;
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

    string ReadAccountNumber(void)
    {
        string Num;

        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter account number: ";
        getline(cin >> ws, Num);

        return (Num);
    }

    string ReadPINCode(void)
    {
        string Code;

        cout << "Please enter PIN code: ";
        getline(cin >> ws, Code);

        return (Code);
    }

    void ShowCheckBalanceScreen(void)
    {
        cout << "==============================================\n";
        cout << "\t\tCheck Balance Screen." << endl;
        cout << "==============================================\n";

        if (FindClientByNumberAndPN(LoggedInClient.AccountNum, LoggedInClient.PinCode, LoggedInClient))
        {
            cout << "\nYour Balance is " << LoggedInClient.AccountBalance << endl;
        }
    }

    void ExecuteATM(enAtmOptions Option)
    {
        switch (Option)
        {
            case enAtmOptions::Logout:
                Login();
                break;

            case enAtmOptions::CheckBalance:
                system("clear");
                ShowCheckBalanceScreen();
                GoBackToMainMenu();
                break;

            case enAtmOptions::QuickWithdraw:
                system("clear");
                ShowQuickWithdrawMenu();
                GoBackToMainMenu();
                break;

            case enAtmOptions::NormalWithdraw:
                system("clear");
                ShowNormalWithdrawScreen();
                GoBackToMainMenu();
                break;

            case enAtmOptions::Deposit:
                system("clear");
                ShowDepositScreen();
                GoBackToMainMenu();
                break;
        }
    }

    short ReadChoice(void)
    {
        short ChoiceOfUser;

        cout << "\nWhat do you want to do? ";
        cin >> ChoiceOfUser;

        return ((enAtmOptions)ChoiceOfUser);
    }

    bool QuickWithdraw(enQuickWithdrawAmount Amount)
    {
        char Perform = 'n';
        vector <stBankAccount> vFile = LoadDataFromFileToVector(ClientFileName);

        cout << "\nAre you sure you want to perform this transaction (y/n)? ";
        cin >> Perform;

        if (FindClientByNumberAndPN(LoggedInClient.AccountNum, LoggedInClient.PinCode, LoggedInClient))
        {
            if (toupper(Perform) == 'Y')
            {
                while (Amount > LoggedInClient.AccountBalance)
                {
                    cout << "\nAmount Exceeds the balance. You can only withdraw up to "
                            << LoggedInClient.AccountBalance << "\nPlease enter amount: ";
                    (enQuickWithdrawAmount) ReadChoice();
                }

                for (stBankAccount &C : vFile)
                {
                    if (C.AccountNum == LoggedInClient.AccountNum)
                    {
                        C.AccountBalance -= Amount;
                        SaveClientToFile(ClientFileName, vFile);
                        cout << "\nDone successfully! New Balance is: " << C.AccountBalance << endl;
                        return (true);
                    }
                }
            }
        }
        return (false);
    }

    void PerformQuickWithdraw(enQuickWithdraw Operation)
    {
        switch (Operation)
        {
            case enQuickWithdraw::Twenty:
                QuickWithdraw(enQuickWithdrawAmount::enTwenty);
                GoBackToMainMenu();
                break;

            case enQuickWithdraw::Fifty:
                QuickWithdraw(enQuickWithdrawAmount::enFifty);
                GoBackToMainMenu();
                break;
            
            case enQuickWithdraw::Hundred:
                QuickWithdraw(enQuickWithdrawAmount::enHundred);
                GoBackToMainMenu();
                break;
            
            case enQuickWithdraw::TwoHundred:
                QuickWithdraw(enQuickWithdrawAmount::enTwoHundred);
                GoBackToMainMenu();
                break;
            
            case enQuickWithdraw::FourHundred:
                QuickWithdraw(enQuickWithdrawAmount::enFourHundred);
                GoBackToMainMenu();
                break;
            
            case enQuickWithdraw::SixHundred:
                QuickWithdraw(enQuickWithdrawAmount::enSixHundred);
                GoBackToMainMenu();
                break;
            
            case enQuickWithdraw::EightHundred:
                QuickWithdraw(enQuickWithdrawAmount::enEightHundred);
                GoBackToMainMenu();
                break;

            case enQuickWithdraw::Thousand:
                QuickWithdraw(enQuickWithdrawAmount::enThousand);
                GoBackToMainMenu();
                break;

            case enQuickWithdraw::Exit:
                GoBackToMainMenu();
                break;
        }
    }
    void ShowMainMenuScreen(void)
    {
        system("clear");
        cout << "===========================================\n";
        cout << "\t\tATM Main Menu Screen\n";
        cout << "===========================================\n";
        cout << "\t\t[1] Quick Withdraw." << endl;
        cout << "\t\t[2] Normal Withdraw." << endl;
        cout << "\t\t[3] Deposit." << endl;
        cout << "\t\t[4] Check Balance." << endl;
        cout << "\t\t[5] Logout." << endl;
        cout << "===========================================\n";

        ExecuteATM((enAtmOptions)ReadChoice());
    }


    void ShowQuickWithdrawMenu(void)
    {
        system("clear");
        cout << "===========================================" << endl;
        cout << "\t\tQuick withdraw Menu\n";
        cout << "===========================================" << endl;
        cout << "\t\t[1] 20              [2] 50" << endl;
        cout << "\t\t[3] 100             [4] 200" << endl;
        cout << "\t\t[5] 400             [6] 600" << endl;
        cout << "\t\t[7] 800             [8] 1000" << endl;
        cout << "\t\t[9] Exit" << endl;
        cout << "===========================================" << endl;

        cout << "Your Balance is " << LoggedInClient.AccountBalance << endl;
        PerformQuickWithdraw((enQuickWithdraw) ReadChoice());
    }

    bool NormalWithdraw(int Amount)
    {
        char Perform = 'n';
        vector <stBankAccount> vFile = LoadDataFromFileToVector(ClientFileName);

        if (FindClientByNumberAndPN(LoggedInClient.AccountNum,
            LoggedInClient.PinCode, LoggedInClient))
        {
            while (Amount % 5 != 0)
            {
                cout << "Enter a money amount that is multiple of 5's: ";
                cin >> Amount;
            }

            cout << "\nAre you sure you want to perform this transaction (y/n)? ";
            cin >> Perform;

            if (toupper(Perform) == 'Y')
            {
                while (Amount > LoggedInClient.AccountBalance)
                {
                    cout << "\nAmount Exceeds the balance. You can only withdraw up to "
                        << LoggedInClient.AccountBalance << "\n\nEnter a money amount that is multiple of 5's: ";
                    cin >> Amount;
                }

                for (stBankAccount &C : vFile)
                {
                    if (C.AccountNum == LoggedInClient.AccountNum)
                    {
                        C.AccountBalance -= Amount;
                        SaveClientToFile(ClientFileName, vFile);
                        cout << "\nDone successfully! New balance is " << C.AccountBalance << endl;
                        return (true);
                    }
                }
            }
        }
        return (false);
    }

    void ShowNormalWithdrawScreen(void)
    {
        int Amount  = 0;

        cout << "=========================================\n";
        cout << "\t\tNormal Withdraw Screen" << endl;
        cout << "=========================================\n";

        cout << "Enter a money amount that is multiple of 5's: ";
        cin >> Amount;

        NormalWithdraw(Amount);
    }

    bool DepositMoney(int MoneyAmount)
    {
        vector <stBankAccount> vFile = LoadDataFromFileToVector(ClientFileName);
        char Perform = 'n';

        if (FindClientByNumberAndPN(LoggedInClient.AccountNum, LoggedInClient.PinCode, LoggedInClient))
        {
            cout << "\nAre you sure you want to perform this transaction (y/n)? ";
            cin >> Perform;

            if (toupper(Perform) == 'Y')
            {
                for (stBankAccount &C : vFile)
                {
                    if (C.AccountNum == LoggedInClient.AccountNum)
                    {
                        C.AccountBalance += MoneyAmount;
                        SaveClientToFile(ClientFileName, vFile);
                        cout << "\nDone successfully! New balance is " << C.AccountBalance << endl;
                        return (true);
                    }
                }
            }
        }
        return (false);
    }
    void ShowDepositScreen(void)
    {
        int Amount = 0;

        cout << "=============================================\n";
        cout << "\t\tDeposit Screen" << endl;
        cout << "=============================================\n";

        cout << "\nEnter a positive deposit amount: ";
        cin >> Amount;

        DepositMoney(Amount);
    }

    void GoBackToMainMenu(void)
    {
        cin.ignore();
        cout << "\nPress Any key to go back to main menu...";
        std::cin.get();
        ShowMainMenuScreen();
    }

    bool FindClientByNumberAndPN(string AccountNum, string PIN, stBankAccount &LoggedInClient)
    {
        vector <stBankAccount> vFile = LoadDataFromFileToVector(ClientFileName);

        for (stBankAccount &C : vFile)
        {
            if (C.AccountNum == AccountNum && C.PinCode == PIN)
            {
                LoggedInClient = C;
                return (true);
            }
        }
        return (false);
    }

    void Login(void)
    {
        system("clear");
        cout << "============================================\n";
        cout << "\t\tLogin Screen\n";
        cout << "============================================\n";

        LoggedInClient.AccountNum = ReadAccountNumber();
        LoggedInClient.PinCode = ReadPINCode();

        while (!FindClientByNumberAndPN(LoggedInClient.AccountNum, LoggedInClient.PinCode, LoggedInClient))
        {
            cout << "Invalid Account Number/ PIN Code. try again." << endl;
            LoggedInClient.AccountNum = ReadAccountNumber();
            LoggedInClient.PinCode = ReadPINCode();
        }
        ShowMainMenuScreen();
    }


}