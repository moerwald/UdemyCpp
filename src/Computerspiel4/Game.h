#pragma once
#include <vector>
#include <string>

using PlayerCoordinates = std::pair<int, int>;
using Position = std::pair<int, int>;
using Obstacles = std::vector<Position>;
using GameState = std::vector<std::string>;

constexpr auto NROFELEMENTS = 10;
constexpr auto NROFROWS = 5;
constexpr auto LASTGAMEFIELD = NROFELEMENTS - 1;

class Game
{
public:

    Obstacles get_obstacles(const int& nr_of_obstacles, const int& max_x_value, const int& max_y_value);
    void up_date_game(const PlayerCoordinates& playerIndex, const Obstacles& obstacles);
    void print_game();
    void move_player(PlayerCoordinates& playerIndex);
    bool is_player_dead(const PlayerCoordinates& playerIndex, const Obstacles& obstacles);
    bool should_game_end(const PlayerCoordinates& playerIndex);
    void clear_screen();

private:
    GameState m_game_state;
};

