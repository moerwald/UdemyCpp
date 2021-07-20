#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <string>
#include <map>
#include "main.h"
#include "Game.h"


int main()
{
    Game game;
    auto quit = false;
    auto&& playerIndex = PlayerCoordinates(0, 0);
    auto&& obstacles = game.get_obstacles(3, LASTGAMEFIELD, NROFROWS - 1);

    while (!quit)
    {
        game.up_date_game(playerIndex, obstacles);
        game.print_game();
        game.move_player(playerIndex);
        if (game.is_player_dead(playerIndex, obstacles))
        {
            std::cout << "Player is dead!" << std::endl;
            std::cin.get();
            break;
        }

        game.clear_screen();

        quit = game.should_game_end(playerIndex);
    }
    return 0;
}
