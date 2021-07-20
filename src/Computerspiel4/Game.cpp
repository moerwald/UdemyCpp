#include "Game.h"
#include <random>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


Obstacles Game::get_obstacles(const int& nr_of_obstacles, const int& max_x_value, const int& max_y_value)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_x(0, max_x_value);
    std::uniform_int_distribution<> distrib_y(0, max_y_value);

    Obstacles obstacles(nr_of_obstacles, Position(0,0));
    for (size_t i = 0; i < nr_of_obstacles; i++)
    {
        obstacles[i].first = distrib_x(gen);
        obstacles[i].second = distrib_y(gen);
    }

    return obstacles;
}

void Game::print_game(const PlayerCoordinates& playerIndex, const Obstacles& obstacles)
{
    auto&& game_board = std::vector<std::string>(NROFROWS, std::string(NROFELEMENTS, '.'));

    game_board[0][0] = '|';
    game_board[NROFROWS - 1][NROFELEMENTS - 1] = '|';

    game_board[playerIndex.first][playerIndex.second] = 'P';

    for (auto& p : obstacles)
        game_board[p.second][p.first] = 'X';

    for (const auto& row : game_board)
        cout << row << endl;

    cout << endl;
}

void Game::move_player(PlayerCoordinates& playerIndex)
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

bool Game::is_player_dead(const PlayerCoordinates& playerIndex, const Obstacles& obstacles)
{
    for (auto& p : obstacles)
    {
        if (playerIndex.second == p.first && playerIndex.first == p.second)
            return true;
    }

    return false;
}

bool Game::should_game_end(const PlayerCoordinates& playerIndex)
{
    if (playerIndex.second == LASTGAMEFIELD && playerIndex.first == NROFROWS - 1)
    {
        cout << "Your reached the end";
        return true;
    }
    return false;
}

void Game::clear_screen()
{
    system("cls");
}
