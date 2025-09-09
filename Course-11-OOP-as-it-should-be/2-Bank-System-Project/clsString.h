#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum enWhatToCount {All = 1, Capital = 2, Small = 3};

class clsString
{
    string _Value;

    public:
    clsString(void)
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetString(string MyString)
    {
        _Value = MyString;
    }

    string GetStringVal(void)
    {
        return (_Value);
    }

    static short Length(string S2)
    {
        return (S2.length());
    }

    short Length(void)
    {
        return (Length(_Value));
    }

    static string UpperCaseFirstLetter(string MyString)
    {
        short i;
        bool FirstLetter = true;

        cout << "\nString after capitalization: ";
        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ' && FirstLetter)
            {
                MyString[i] = toupper(MyString[i]);
            }

            FirstLetter = (MyString[i] == ' ' ? true : false);
        }

        return (MyString);
    }

    void UpperCaseFirstLetter(void)
    {
        _Value = UpperCaseFirstLetter(_Value);
    }

    static string LowercaseFirstLetter(string MyString)
    {
        int i;
        bool IsFirstLetter = true;

        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ' && IsFirstLetter)
            {
                MyString[i] = tolower(MyString[i]);
            }

            IsFirstLetter = (MyString[i] == ' ' ? true : false);
        }
        return (MyString);
    }

    void LowercaseFirstLetter(void)
    {
        _Value = LowercaseFirstLetter(_Value);
    }

    static string stringInLowercase(string MyString)
    {
        int i;

        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ')
            {
                MyString[i] = tolower(MyString[i]);
            }
        }
        return (MyString);
    }

    void stringInLowercase(void)
    {
        _Value = stringInLowercase(_Value);
    }

    static string StringInUppercase(string S1)
    {
        int i;

        for (i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return (S1);
    }

    void StringInUppercase(void)
    {
        _Value = StringInUppercase(_Value);
    }

    static short CountUppercase(string S1)
    {
        short i;
        short WordCount = 0;

        for (i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
            {
                WordCount++;
            }
        }
        return (WordCount);
    }

    short CountUppercase(void)
    {
        return (CountUppercase(_Value));
    }

    static short CountLowercase(string S1)
    {
        short i;
        short WordCount = 0;

        for (i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
            {
                WordCount++;
            }
        }
        return (WordCount);
    }

    short CountLowercase(void)
    {
        return (CountLowercase(_Value));
    }

    static short CountWordsInString(string S)
    {
        short i, Pos = 0, Count = 0;
        string Word;
        string Delimiter = " ";

        while ((Pos = S.find(Delimiter)) != std::string::npos)
        {
            Word = S.substr(0, Pos);

            if (Word != " ")
            {
                Count++;
            }
            S.erase(0, Pos + Delimiter.length());
        }
       
        if (S != "")
        {
            Count++;
        }

        return (Count);
    }

    short CountWordsInString(void)
    {
        return (CountWordsInString(_Value));
    }

    static string ReplaceWord(string S, string Source, string Target)
    {
        short Pos = S.find(Source);

        while (Pos != string::npos)
        {
            S = S.replace(Pos, Source.length(), Target);

            Pos = S.find(Source);
        }
        return (S);
    }

    void ReplaceWord(string Source, string Target)
    {
       _Value = ReplaceWord(_Value, Source, Target);
    }

    static bool IsVowel(char S)
    {
        S = tolower(S);

        return ((S == 'i') || (S == 'o') || (S == 'u') || (S == 'e') || (S == 'a'));
    }

    static short CountVowels(string S1)
    {
        short i, Count = 0;

        for (i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
            {
                Count++;
            }
        }
        return (Count);
    }

    short CountVowels(void)
    {
        return (CountVowels(_Value));
    }


    static string Joinstring(string S[], string delimiter, short Length)
    {
        short i;
        string S1 = "";

        for (i = 0; i < Length; i++)
        {
            S1 = S1 + S[i] + delimiter;
        }
        return (S1);
    }

    static string JoinString(vector <string> vString, string deli)
    {
        string S = "";

        for (string &i : vString)
        {
            S = S + i + deli;
        }

        return (S.substr(0, S.length() - deli.length()));
    }


    static short CountLettersInWord(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        short i, Count = 0;

        if (WhatToCount == enWhatToCount::All)
        {
            return (S1.length());
        }

        for (i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::Capital && isupper(S1[i]))
            {
                Count++;
            }

            else if (WhatToCount == enWhatToCount::Small && islower(S1[i]))
            {
                Count++;
            }
        }
        return (Count);
    }

    static short CountLowerCaseLetters(string MyString)
    {
        short i, Count = 0;

        for (i = 0; i < MyString.length(); i++)
        {
            if (islower(MyString[i]))
            {
                Count++;
            }
        }

        return (Count);
    }

    short CountLowerCaseLetters(void)
    {
        return (CountLowerCaseLetters(_Value));
    }

    static short CountSpecificLetterInWord(string MyString, char C, bool Match = true)
    {
        short i, Count = 0;

        for (i = 0; i < MyString.length(); i++)
        {
            if (Match)
            {
                if (MyString[i] == C)
                {
                    Count++;
                }
            }

            else
            {
                if (toupper(MyString[i]) == toupper(C))
                {
                    Count++;
                }
            }
        }
        return (Count);
    }

    short CountSpecificLetterInWord(char C, bool Match = true)
    {
        return (CountSpecificLetterInWord(_Value, C, Match));
    }

    static vector <string> Split(string S1, string deli = " ")
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

    vector <string> Split(string deli)
    {
        return (Split(_Value, deli));
    }

    static string TrimLeft(string MyString)
    {
        short i;

        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ')
            { /*s = "  Hello"*/
                return (MyString.substr(i, MyString.length() - i));
            }
        }
        return ("");
    }

    void TrimLeft(void)
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string MyString)
    {
        short i;

        for (i = MyString.length() - 1; i >= 0; i--)
        {
            if (MyString[i] != ' ')
            {
                return (MyString.substr(0, i + 1));
            }
        }
        return ("");
    }

    void TrimRight(void)
    {
        _Value = TrimRight(_Value);
    }

    static string TrimAll(string MyString)
    {
        return (TrimLeft(TrimRight(MyString)));
    }

    void TrimAll(void)
    {
        _Value = TrimAll(_Value);
    }

    static string ReverseString(string S)
    {
        vector <string> vString;
        string S1 = "";

        vString = Split(S, " ");

        vector <string>::iterator it = vString.end();

        while (it != vString.begin())
        {
            --it;
            S1 += *it + " ";
        }
        return (TrimRight(S1));
    }

    void ReverseString(void)
    {
        _Value = ReverseString(_Value);
    }

    static char InvertCharacter(char C)
    {
        return (islower(C) ? toupper(C) : tolower(C));
    }

    static string InvertAllLetters(string S1)
    {
        short i;

        for (i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertCharacter(S1[i]);
        }

        return (S1);
    }

    void InvertAllLetters(void)
    {
        _Value = InvertAllLetters(_Value);
    }

    static string RemovePunctuation(string S)
    {
        string NewString = "";
        short i;
    
        for (i = 0; i < S.length(); i++)
        {
            if (!ispunct(S[i]))
            {
                NewString += S[i];
            }
        }
        return (NewString);
    }

    void RemovePunctuation(void)
    {
        _Value = RemovePunctuation(_Value);
    }

    static string ReadString(void)
    {
        string S1 = "";

        getline(cin >> ws, S1);

        return (S1);
    }

};