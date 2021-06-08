#include <iostream>
#include <string>;
#include "main.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    auto quit = false;
    std::string userInput{};
    const auto nrOfElements = 10;
    auto playerIndex = 0; 

    while (!quit)
    {
        for (size_t i = 0; i < nrOfElements; i++)
        {
            switch (i)
            {
                // first element
            case 0:
                cout << (playerIndex == 0 ? "P" : "|");
                break;

                // last element
            case nrOfElements - 1:
                if (playerIndex == i)
                    cout << "P";
                else
                    cout << "|";
                break;

                // other elements
            default:
                cout << (i == playerIndex ? "P" : ".");
                break;
            }
        }

        cout << "Move (f)orward or (b)ackward?";
        cin >> userInput;

        if (userInput == "f")
            playerIndex++;
        else if (userInput == "b" && playerIndex > 0)
            playerIndex--;

        // End game
        if (playerIndex == nrOfElements - 1)
        {
            quit = true;
            cout << "Your reached the end";

        }
    }

    return 0;
}
