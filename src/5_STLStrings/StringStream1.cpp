#include "StringStream1.h"
#include <string>
#include <sstream>
#include <iostream>

int StringStream1::main()
{
    std::string birthday;

    std::cout << "Please enter your birthday (DD.MM.YYYY): ";
    std::cin >> birthday;

    std::stringstream birthday_ss(birthday);

    unsigned int day, month, year;
    char delimiter;

    birthday_ss >> day >> delimiter >> month >> delimiter >> year;

    std::cout << "Your birthday is: " << birthday << std::endl;

    return 0;
}
