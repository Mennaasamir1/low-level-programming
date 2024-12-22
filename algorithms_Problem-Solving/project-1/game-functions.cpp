#include "game.h"

/**
 * RandomNumberGenerator - function that generates random numbers
 * within a range
 * @From: Min range
 * @To: Max Range
 * Return: a random number
 */
int RandomNumberGenerator(int From, int To)
{
    int RandomNumber;

    RandomNumber = rand() % (To - From + 1) + From;

    return (RandomNumber);
}

/**
 * HowManyRounds - function that reads the number of rounds
 *
 * Return: number of input rounds
 */
short HowManyRounds(void)
{
    short Rounds = 1;

    do
    {
        cout << "How many rounds?\n";
        cin >> Rounds;
    } while (Rounds < 1 || Rounds > 10);

    return (Rounds);
    
}

/**
 * GetPlayerChoice - gets the player choice (stone, paper, scissors)
 *
 * Return: the player's choice
 */
enChoice GetPlayerChoice(void)
{
    short Choice;

   do
   {
        cout << "What's your Choice? [1]: Stone, [2]: Paper, [3]: Scissors" << endl;
        cin >> Choice;

   } while (Choice < 1 || Choice > 10);
    
    return ((enChoice)Choice);
}

/**
 * ComputerChoice - generates the computer's random choice
 *
 * Return: the computer's choice
 */
enChoice ComputerChoice(void)
{
    return ((enChoice)RandomNumberGenerator(1, 3));
}

/**
 * ResetScreen - restarts the screen
 */
void ResetScreen(void)
{
    system("clear");
}

/**
 * WhoWonRound - decides the winner of the round based on each player choice
 * @Round: variable to the structure of round info
 * Return: the winner of the round based on an enum.
 */
enWinner WhoWonRound(stRound Round)
{
    if (Round.PlayerChoice == Round.ComputerChoice)
    {
        return (enWinner::Draw);
    }

    switch (Round.PlayerChoice)
    {
    case enChoice::Paper:
        if (Round.ComputerChoice == enChoice::Scissors)
        {
            return (enWinner::Computer);
        }
        break;
    
    case enChoice::Scissors:
        if (Round.ComputerChoice == enChoice::Stone)
        {
            return (enWinner::Computer);
        }
        break;

    case enChoice::Stone:
       if (Round.ComputerChoice == enChoice::Paper)
        {
            return (enWinner::Computer);
        }
        break;
    }
    return (enWinner::player);
}

/**
 * WinnerName - returns a string of the winner's name
 * @Winner: a variable of the enum enWinner
 * Return: a string of the winner name
 */
string WinnerName(enWinner Winner)
{
    string WinnerName[3] = {"Player", "Computer", "Draw"};

    return (WinnerName[Winner - 1]);
}

/**
 * Tabs - returns a string of tabs (to make the game look structured)
 * @TabsNum: number of tabs to be printed
 * Return: a string of tabs.
 */
string Tabs(short TabsNum)
{
    string Tabs = "";
    int i;

    for (i = 1; i <= TabsNum; i++)
    {
        Tabs = Tabs + '\t';
        cout << Tabs;
    }

    return (Tabs);
}

/**
 * ChoiceOfPlayers - returns a string of the choice name
 * @Choice: variable of the enum enChoice
 * Return: a string of the choice name
 */
string ChoiceOfPlayers(enChoice Choice)
{
    string Choices[3] = {"Stone", "Paper", "Scissors"};

    return (Choices[Choice - 1]);
}

/**
 * PrintRoundResults - prints the round results
 * Round: variable of the structure stRound
 */
void PrintRoundResults(stRound Round)
{
    cout << "\n______ Round info ______" << endl;
    cout << "Player Choice: " << ChoiceOfPlayers(Round.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceOfPlayers(Round.ComputerChoice) << endl;
    cout << "Round Winner: [" << WinnerName(Round.Winner) << "]" << endl;
    cout << "_____________________________________\n" << endl;
}

/**
 * WhoWonGame - determines the winner of the game based on win times
 * @PlayerWinTimes: how many times the player won
 * @ComputerWinTimes: how many times the computer won
 * Return: the winner of the game
 */
enWinner WhoWonGame(short PlayerWinTimes, short ComputerWinTimes)
{
    if (PlayerWinTimes > ComputerWinTimes)
    {
        return (enWinner::player);
    }
    else if (ComputerWinTimes > PlayerWinTimes)
    {
        return (enWinner::Computer);
    }
    else
    {
        return (enWinner::Draw);
    }
}

/**
 * PlayGame - function that starts each round
 * @RoundsNumber: number of rounds
 * Return: a variable of a strucure full of the game information
 */
stGameResults PlayGame(short RoundsNumber)
{
    int i;
    stRound Round;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (i = 1; i <= RoundsNumber; i++)
    {
        cout << "Round [" << i << "] begins: " << endl;
        Round.RoundNumber = i;
        Round.PlayerChoice = GetPlayerChoice();
        Round.ComputerChoice = ComputerChoice();
        Round.Winner = WhoWonRound(Round);
        Round.NameOfWinner = WinnerName(Round.Winner);

        if (Round.Winner == enWinner::Computer)
        {
            ComputerWinTimes++;
        }
        else if (Round.Winner == enWinner::player)
        {
            PlayerWinTimes++;
        }
        else
        {
            DrawTimes++;
        }

        PrintRoundResults(Round);
    }

    return (FillGameResults(RoundsNumber, PlayerWinTimes, ComputerWinTimes, DrawTimes));
}

/**
 * FillGameResults - function that fills the structure of the game info
 * @RoundsNum: number of rounds played
 * @PlayerWinTimes: win times of the player
 * @ComputerWinTimes: win times of computer
 * @DrawTimes: draw times
 * Return: a variable to a structure of the game info
 */
stGameResults FillGameResults(int RoundsNum, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults Game;

    Game.ComputerWinTimes = ComputerWinTimes;
    Game.PlayerWinTimes = PlayerWinTimes;
    Game.DrawTimes = DrawTimes;
    Game.GameRounds = RoundsNum;
    Game.GameWinner = WhoWonGame(PlayerWinTimes, ComputerWinTimes);
    Game.WinnerName = WinnerName(Game.GameWinner);

    return (Game);
}

/**
 * ShowGameOverScreen - displayes "game over" on the screen
 */
void ShowGameOverScreen(void)
{
    cout << Tabs(2) <<
    "__________________________________________________________\n\n";
    cout << Tabs(2) << " +++ G a m e O v e r +++\n";
    cout << Tabs(2) <<
    "__________________________________________________________\n\n";

}

/**
 * PrintFinalGameResults - prints the final game results
 * @Game: variable to structre that contains the game info
 */
void PrintFinalGameResults(stGameResults Game)
{
    cout << Tabs(2) << "________[Game Results]_______\n\n";
    cout << Tabs(2) << " Game Rounds: " << Game.GameRounds << endl;
    cout << Tabs(2) << "Player Win Times: " << Game.PlayerWinTimes << endl;
    cout << Tabs(2) << "Computer Win Times: " << Game.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times: " << Game.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner: " << Game.WinnerName << endl;
}

/**
 * StartGame - function that starts the game
 */
void StartGame(void)
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(HowManyRounds());
        ShowGameOverScreen();
        PrintFinalGameResults(GameResults);
        cout << endl << Tabs(2) << "Do you want to Play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


