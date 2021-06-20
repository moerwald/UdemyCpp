#include "WriteFile.h"
#include <fstream>
#include <iostream>
#include <string>

int WriteFile::main()
{

    std::ifstream stream;
    stream.open("Text.txt");
    std::string file_content;
    if (stream.is_open())
    {
        std::string str;

        while (std::getline(stream, str))
            file_content += str + "\n";

        std::cout << std::endl << "===============================" << std::endl;
        std::cout << "Full content: " << std::endl << file_content;
    }
    stream.close();

    std::string search_str = "one";
    auto replace_str = "xxxxx";

    auto idx = file_content.find(search_str);
    if (idx != std::string::npos)
    {
        file_content.replace(idx, search_str.size(), replace_str);

        std::ofstream ofstream;
        ofstream.open("TextOutput.txt");
        if (ofstream.is_open())
        {
            ofstream << file_content;
        }
        ofstream.close();
    }

    return 0;
}
