#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using PlayerCoordinates = std::pair<int, int>;

const auto NROFELEMENTS = 10;
const auto NROFROWS = 5;
const auto LASTGAMEFIELD = NROFELEMENTS - 1;

void printGame(const PlayerCoordinates& playerIndex)
{

    auto&& game_board = vector<string>(NROFROWS, string(NROFELEMENTS, '.'));

    game_board[0][0] = '|';
    game_board[NROFROWS - 1][NROFELEMENTS - 1] = '|';

    game_board[playerIndex.first][playerIndex.second] = 'P';

    for (const auto& row : game_board)
        cout << row << endl;

    cout << endl;
}

void movePlayer(PlayerCoordinates& playerIndex)
{
    std::string userInput{};
    cout << "Move (wasd): ";
    cin >> userInput;

    if (userInput == "d") // right
        playerIndex.second = ++playerIndex.second;
    else if (userInput == "a") // left
        playerIndex.second = --playerIndex.second;
    else if (userInput == "w") // up
        playerIndex.first = --playerIndex.first;
    else if (userInput == "s") // down
        playerIndex.first = ++playerIndex.first;
    else
        cout << "Unrecognized move!";
}

bool shouldEndgame(const PlayerCoordinates& playerIndex)
{
    if (playerIndex.second == LASTGAMEFIELD && playerIndex.first == NROFROWS - 1)
    {
        cout << "Your reached the end";
        return true;
    }
    return false;
}

void clearScreen()
{
    system("cls");
}

int main()
{
    auto quit = false;
    auto&& playerIndex = PlayerCoordinates(0, 0);
    const auto lastGameField = NROFELEMENTS - 1;

    while (!quit)
    {
        printGame(playerIndex);
        movePlayer(playerIndex);
        clearScreen();

        quit = shouldEndgame(playerIndex);
    }
    return 0;
}
