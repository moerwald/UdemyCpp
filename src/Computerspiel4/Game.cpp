#include "Game.h"
#include <random>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


void Game::get_obstacles()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_x(0, NROFCOLUMNS - 1);
    std::uniform_int_distribution<> distrib_y(0, NROFROWS - 1);

    for (size_t i = 0; i < m_obstacles.size(); i++)
    {
        m_obstacles[i].second = distrib_x(gen);
        m_obstacles[i].first = distrib_y(gen);

        if (m_obstacles[i] == m_exit || m_obstacles[i] == m_player_starting_position)
        {
            --i;
        }
    }

}

void Game::up_date_game()
{
    m_game_state = GameState(NROFROWS, std::string(NROFCOLUMNS, '.'));

    m_game_state[0][0] = '|';
    m_game_state[NROFROWS - 1][NROFCOLUMNS - 1] = '|';

    m_game_state[m_player_coordinates.first][m_player_coordinates.second] = 'P';

    for (auto& p : m_obstacles)
    {
        m_game_state[p.first][p.second] = 'X';
    }
}

void Game::print_game()
{
    for (const auto& row : m_game_state)
    {
        cout << row << endl;
    }

    cout << endl;
}

void Game::move_player()
{
    std::string userInput{};
    cout << "Move (wasd): ";
    cin >> userInput;

    if (userInput == "d") // right
    {
        if (m_player_coordinates.second + 1 < NROFCOLUMNS)
            ++m_player_coordinates.second;
    }
    else if (userInput == "a") // left
    {
        if (m_player_coordinates.second - 1 > 0)
            --m_player_coordinates.second;
    }
    else if (userInput == "w") // up
    {
        if (m_player_coordinates.first - 1 > 0)
            --m_player_coordinates.first;
    }
    else if (userInput == "s") // down
    {
        if (m_player_coordinates.first + 1 < NROFROWS)
            ++m_player_coordinates.first;
    }
    else
    {
        cout << "Unrecognized move!";
    }
}

bool Game::is_player_dead()
{
    for (auto& obstacle : m_obstacles)
    {
        if (m_player_coordinates == obstacle)
        {
            return true;
        }
    }

    return false;
}

bool Game::should_game_end()
{
    if (m_player_coordinates == m_exit)
    {
        return true;
    }
    return false;
}

void Game::clear_screen()
{
    system("cls");
}
