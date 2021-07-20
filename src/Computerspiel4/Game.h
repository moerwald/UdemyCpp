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
    void printGame(const PlayerCoordinates& playerIndex, const std::vector<Position>& obstacles);
    void movePlayer(PlayerCoordinates& playerIndex);
    bool is_player_dead(const PlayerCoordinates& playerIndex, const std::vector<Position>& obstacles);
    bool shouldEndgame(const PlayerCoordinates& playerIndex);
    void clearScreen();
};

