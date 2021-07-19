#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <string>
#include <map>
#include <random>
#include "main.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using PlayerCoordinates = std::pair<int, int>;
using Position = std::pair<int, int>;

const auto NROFELEMENTS = 10;
const auto NROFROWS = 5;
const auto LASTGAMEFIELD = NROFELEMENTS - 1;

std::vector<Position> get_obstacles(const int& nr_of_obstacles, const int& max_x_value, const int& max_y_value)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_x(0, max_x_value);
    std::uniform_int_distribution<> distrib_y(0, max_y_value);

    std::vector<Position> vec(nr_of_obstacles);
    for (size_t i = 0; i < nr_of_obstacles; i++)
    {
        vec[i] = Position(distrib_x(gen), distrib_y(gen));
    }

    return vec;
}

void printGame(const PlayerCoordinates& playerIndex, const std::vector<Position>& obstacles)
{
    auto&& game_board = vector<string>(NROFROWS, string(NROFELEMENTS, '.'));

    game_board[0][0] = '|';
    game_board[NROFROWS - 1][NROFELEMENTS - 1] = '|';

    game_board[playerIndex.first][playerIndex.second] = 'P';

    for (auto& p : obstacles)
        game_board[p.second][p.first] = 'X';

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


bool is_player_dead(const PlayerCoordinates& playerIndex, const std::vector<Position>& obstacles)
{

    for (auto& p : obstacles)
    {
        if (playerIndex.second == p.first && playerIndex.first == p.second)
            return true;
    }

    return false;

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
    auto&& obstacles = get_obstacles(3, lastGameField, NROFROWS - 1);

    while (!quit)
    {
        printGame(playerIndex, obstacles);
        movePlayer(playerIndex);
        if (is_player_dead(playerIndex, obstacles))
        {
            std::cout << "Player is dead!" << std::endl;
            std::cin.get();
            break;
        }

        clearScreen();

        quit = shouldEndgame(playerIndex);
    }
    return 0;
}
