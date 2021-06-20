#include "WriteFile.h"
#include <fstream>
#include <iostream>
#include <string>

int WriteFile::main()
{

    std::ifstream stream;
    stream.open("Text.txt");
    if (stream.is_open())
    {
        std::string file_content;
        std::string str;

        stream >> file_content;

        std::cout << std::endl << "===============================" << std::endl;
        std::cout << "Full content: " << std::endl << file_content;
    }

    stream.close();
    return 0;
}
