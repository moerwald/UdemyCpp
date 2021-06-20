#include "FileOperation.h"
#include <fstream>
#include <sstream>

std::string FileOperation::read_from_file(const std::string& file_path)
{
    std::ifstream ifstream(file_path);
    std::ostringstream oss;

    oss << ifstream.rdbuf();
    return oss.str();
}

void FileOperation::write_to_file(const std::string& file_path, std::string str_to_write)
{
    std::ofstream ofstream(file_path);
    ofstream << str_to_write;
}
