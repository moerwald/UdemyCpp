
#include <iostream>
#include "Enum.h"


enum PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    ADMIN = 3
};

struct User
{
    int id;
    PermissionLevel permission;

};

int Enum::Main()
{

    User user1{ 1, PermissionLevel::STUDENT};

    switch (user1.permission)
    {
    case PermissionLevel::STUDENT:
        std::cout << "User is student" << std::endl;
        break;

    case PermissionLevel::ADMIN:
        std::cout << "User is admin" << std::endl;
        break;

    case PermissionLevel::TUTOR:
        std::cout << "User is tutor" << std::endl;
        break;
    default:
        break;
    }

    return 0;
}
