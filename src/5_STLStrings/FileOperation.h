#pragma once
#include<string>;
class FileOperation
{
public: static std::string read_from_file(const std::string& file_path);
public: static void write_to_file(const std::string& file_path, std::string str_to_write);
};

