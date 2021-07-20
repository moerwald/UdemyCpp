#include "Game.h"
#include <random>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

Position&& Game::generate_random(const int x_min, const int x_max, const int y_min, const int y_max)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_x(x_min, x_max);
    std::uniform_int_distribution<> distrib_y(y_min, y_max);

    return Position(distrib_y(gen), distrib_x(gen));
}

void Game::start()
{
    auto quit = false;
    auto&& playerIndex = PlayerCoordinates(0, 0);
    auto player_dead = false;
    get_obstacles();

    while (!quit)
    {
        clear_screen();
        up_date_game();
        print_game();

        move_player();
        player_dead = is_player_dead();
        move_obstacles();
        player_dead = is_player_dead();

        if (player_dead)
        {
            clear_screen();
            up_date_game();
            print_game();
            std::cout << "Player is dead!" << std::endl;
            std::cin.get();
            break;
        }

        quit = should_game_end();
        if (quit)
        {
            std::cout << "Your reached the end";
        }
    }
}

void Game::get_obstacles()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_x(0, NROFCOLUMNS - 1);
    std::uniform_int_distribution<> distrib_y(0, NROFROWS - 1);

    for (size_t i = 0; i < m_obstacles.size(); i++)
    {
        auto&& pos = generate_random(0, NROFCOLUMNS - 1, 0, NROFROWS - 1);
        m_obstacles[i].second = pos.second;
        m_obstacles[i].first = pos.first;

        if (m_obstacles[i] == m_exit || m_obstacles[i] == m_player_starting_position)
        {
            --i;
        }
    }
}

void Game::move_obstacles()
{
    for (auto& obstacle : m_obstacles)
    {
        auto&& pos = generate_random(-1, 1, -1, 1);
        auto new_y = obstacle.first + pos.first;
        auto new_x = obstacle.second + pos.second;
        // Max bound check
        if ((new_x <= LAST_X)
            && (new_y <= LAST_Y)
            // Min bound check
            && (new_x >= 0)
            && (new_y >= 0)
            // Obstacle not on player check
            //&& (new_x != m_player_coordinates.first)
            //&& (new_y != m_player_coordinates.second))
            )
        {
            obstacle.first = new_y;
            obstacle.second = new_x;
        }
    }
}

void Game::up_date_game()
{
    m_game_state = GameState(NROFROWS, std::string(NROFCOLUMNS, '.'));

    m_game_state[0][0] = '|';
    m_game_state[NROFROWS - 1][NROFCOLUMNS - 1] = '|';

    m_game_state[m_player_coordinates.first][m_player_coordinates.second] = 'P';

    for (auto& obstacle : m_obstacles)
    {
        m_game_state[obstacle.first][obstacle.second] = 'X';
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
