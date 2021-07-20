#pragma once
#include <vector>

using PlayerCoordinates = std::pair<int, int>;
using Position = std::pair<int, int>;

constexpr auto NROFELEMENTS = 10;
constexpr auto NROFROWS = 5;
constexpr auto LASTGAMEFIELD = NROFELEMENTS - 1;

class Game
{
public:

    std::vector<Position> get_obstacles(const int& nr_of_obstacles, const int& max_x_value, const int& max_y_value);
    void print_game(const PlayerCoordinates& playerIndex, const std::vector<Position>& obstacles);
    void move_player(PlayerCoordinates& playerIndex);
    bool is_player_dead(const PlayerCoordinates& playerIndex, const std::vector<Position>& obstacles);
    bool should_game_end(const PlayerCoordinates& playerIndex);
    void clear_screen();
};

