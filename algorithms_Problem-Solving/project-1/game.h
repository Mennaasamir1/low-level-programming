#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

enum enChoice {Stone = 1, Paper = 2, Scissors = 3};
enum enWinner {player = 1, Computer = 2, Draw = 3};

struct stRound
{
    short RoundNumber = 0;
    enChoice PlayerChoice;
    enChoice ComputerChoice;
    enWinner Winner;
    string NameOfWinner;
};

struct stGameResults
{
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName;
};

int RandomNumberGenerator(int From, int To);
short HowManyRounds(void);
enChoice GetPlayerChoice(void);
enChoice ComputerChoice(void);
void ResetScreen(void);
stGameResults PlayGame(short Rounds);
void ShowGameOverScreen(void);
void PrintFinalGameResults(stGameResults Game);
string Tabs(short NumberOfTabs);
stGameResults FillGameResults(int RoundsNum, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes);
enWinner WhoWonGame(short PlayerWinTimes, short ComputerWinTimes);
void PrintRoundResults(stRound Round);
string ChoiceOfPlayers(enChoice Choice);
string WinnerName(enWinner Winner);
enWinner WhoWonRound(stRound Round);
void StartGame(void);

#endif