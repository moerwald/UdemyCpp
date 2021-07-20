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
    Game game(3);
    auto quit = false;
    auto&& playerIndex = PlayerCoordinates(0, 0);
    game.get_obstacles();

    while (!quit)
    {
        game.up_date_game();
        if (game.is_player_dead())
        {
            std::cout << "Player is dead!" << std::endl;
            std::cin.get();
            break;
        }

        game.clear_screen();

        game.print_game();
        game.move_player();

        quit = game.should_game_end();
        if (quit)
        {
            std::cout << "Your reached the end";
        }

    }
    return 0;
}
