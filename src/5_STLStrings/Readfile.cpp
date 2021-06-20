#include "Readfile.h"
#include <fstream>
#include <string>
#include <iostream>

int Readfile::main()
{
    std::ifstream stream;
    stream.open("Text.txt");
    if (stream.is_open())
    {
        std::string file_content;
        std::string str;
        while (std::getline(stream, str))
        {
            std::cout << str << std::endl;
            file_content += str + "\n";
        }

        std::cout << std::endl << "===============================" << std::endl;
        std::cout << "Full content: " << std::endl << file_content;
    }

    stream.close();
    return 0;
}
