#include "MoveSemantics2.h"
#include "OwnString.h"
#include <iostream>
#include <random>

int MoveSemantics2::main()
{
    OwnString string = "Hello";
    auto dest_copy_of_string = string;                                  // Creates a copy!!!
    auto dest_moved_from_string = std::move(string);                    // Lets convert string to a temporary, calls the move-CTOR!!! Therefore
                                                                        // dest_moved_from_string is a NEW object, which will take ownership
                                                                        // of string-object memory!!!
    // auto dest_moved_from_string_via_move_ctor(std::move(string));    // Equivalent as code above, BUT harder to read
    // auto dest_moved_from_string_via_move_ctor((String&&)string);     // Cast is also support, but std::move is more flexible
    dest_moved_from_string = std::move(string);                         // Object already created compiler will call move-assignment-operator!

    std::cout << "========================================" << std::endl;
    std::cout << "Use move assignment operator" << std::endl;
    OwnString apple = "Apple";
    OwnString dest;
    OwnString& dest1 = apple;

    std::cout << "apple: ";
    apple.Print();
    std::cout << "dest: ";
    dest.Print();

    std::cout << "After calling the move assignment operator values should be switched" << std::endl;
    dest = std::move(apple);

    std::cout << "apple: ";
    apple.Print();
    std::cout << "dest: ";
    dest.Print();

    dest1.Print();

    return 0;
}
