#include <iostream>
#include <string>;
#include "main.h"
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

void printGame(int playerIndex, int nrOfElements)
{
    const auto lastElement = nrOfElements - 1;
    static const auto PlayerSymbol = "P";

    auto getSymbol = [](bool getPlayer, std::string otherSym = "|")
    { 
        return getPlayer ? PlayerSymbol : otherSym;
    };

    for (size_t i = 0; i < nrOfElements; i++)
    {
        if (i == 0)
            cout << getSymbol(0 == playerIndex);
        else if (i == lastElement)
        {
            cout << getSymbol(i == playerIndex);
            cout << endl;
        }
        else
            cout << getSymbol(i == playerIndex, ".");
    }
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

bool shouldEndgame(int playerIndex, int lastGameFieldElement)
{
    if (playerIndex != lastGameFieldElement)
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
    static const auto nrOfElements = 10;
    const auto lastGameField = nrOfElements - 1;

    while (!quit)
    {
        printGame(playerIndex, nrOfElements);

        playerIndex = movePlayer(playerIndex);

        clearScreen();

        quit = shouldEndgame(playerIndex, lastGameField);
    }
    return 0;
}
