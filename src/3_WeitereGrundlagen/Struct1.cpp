#include "Struct1.h"
#include <iostream>

struct Movie
{
    const int year;
    const char* title;
    const char* director;
};


void PrintMovie(Movie& movie)
{
    std::cout << movie.year << std::endl;
    std::cout << movie.title << std::endl;
    std::cout << movie.director << std::endl;
}

void PrintMovie(Movie* movie)
{
    std::cout << movie->year << std::endl;
    std::cout << movie->title << std::endl;
    std::cout << movie->director << std::endl;
}

int Struct1::Main()
{
    Movie starwars7{ 2015, "Star Wars the Force Awakens", "J. J. Abrams" };
    PrintMovie(starwars7);

    Movie starwars8{ 2017, "Star Wars the last Jedi", "Rian Johnson" };
    PrintMovie(&starwars8);

    Movie starwars9{ 2019, "Star Wars the Rise of the Skywalker", "J. J. Abrams" };
    PrintMovie(&starwars9);

    return 0;
}
