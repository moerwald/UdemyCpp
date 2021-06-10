#include <iostream>
#include <string>;
#include "main.h"
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

const auto NROFELEMENTS = 10;
const auto LASTGAMEFIELD = NROFELEMENTS - 1;

void printGame(int playerIndex)
{
    char gameState[NROFELEMENTS];

    for (size_t i = 0; i < NROFELEMENTS; i++)
        gameState[i] = '.';

    gameState[0] = '|';
    gameState[NROFELEMENTS -1] = '|';
    gameState[playerIndex] = 'P';

    for (size_t i = 0; i < NROFELEMENTS; i++)
        cout << gameState[i];

    cout << endl;
}

int movePlayer(int playerIndex)
{
    std::string userInput{};
    cout << "Move (f)orward or (b)ackward?";
    cin >> userInput;

    if (userInput == "f")
        playerIndex++;
    else if (userInput == "b" && playerIndex > 0)
        playerIndex--;
    else
        cout << "Unrecognized move!";

    return playerIndex;
}

bool shouldEndgame(int playerIndex)
{
    if (playerIndex != LASTGAMEFIELD)
        return false;

    cout << "Your reached the end";
    return true;
}

void clearScreen()
{
    system("cls");
}

int main()
{
    auto quit = false;
    auto playerIndex = 0;
    const auto lastGameField = NROFELEMENTS - 1;

    while (!quit)
    {
        printGame(playerIndex);
        playerIndex = movePlayer(playerIndex);
        clearScreen();

        quit = shouldEndgame(playerIndex);
    }
    return 0;
}
