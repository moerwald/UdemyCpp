#pragma once
#include <vector>
#include <string>

using PlayerCoordinates = std::pair<int, int>;
using Position = std::pair<int, int>;
using Obstacles = std::vector<Position>;
using GameState = std::vector<std::string>;


class Game
{
public:

    Game(const int nr_of_obstacles)
        : m_exit(NROFROWS - 1, NROFCOLUMNS - 1)
        , m_obstacles(nr_of_obstacles, Position(0, 0))
        , m_player_coordinates(0, 0)
//        , m_game_state(NROFROWS, std::string(NROFCOLUMNS, '.'))
    {
    }

    void get_obstacles();
    void up_date_game();
    void print_game();
    void move_player();
    bool is_player_dead();
    bool should_game_end();
    void clear_screen();

private:
    Position&& generate_random(const int x_min, const int x_max, const int y_min, const int y_max);

    GameState m_game_state;
    Position m_exit;
    Obstacles m_obstacles;
    PlayerCoordinates m_player_coordinates;

    static constexpr Position m_player_starting_position = Position(0, 0);
    static constexpr int NROFCOLUMNS = 10;
    static constexpr int NROFROWS = 5;
};

