#include "Struct1.h"
#include <iostream>

struct Movie
{
    const int year;
    const char* title;
    const char* director;
};

int Struct1::Main()
{
    Movie starwars7{ 2015, "Star Wars the Force Awakens", "J. J. Abrams" };
    std::cout << starwars7.year << std::endl;
    std::cout << starwars7.title << std::endl;
    std::cout << starwars7.director << std::endl;

    Movie starwars8{ 2017, "Star Wars the last Jedi", "Rian Johnson" };
    std::cout << starwars8.year << std::endl;
    std::cout << starwars8.title << std::endl;
    std::cout << starwars8.director << std::endl;

    Movie starwars9{ 2019, "Star Wars the Rise of the Skywalker", "J. J. Abrams" };
    std::cout << starwars9.year << std::endl;
    std::cout << starwars9.title << std::endl;
    std::cout << starwars9.director << std::endl;
    return 0;
}
