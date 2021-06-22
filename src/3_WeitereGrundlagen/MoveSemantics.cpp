#include "MoveSemantics.h"
#include <iostream>

class String
{
public:
    String() = default;
    String(const char* string)
    {
        std::cout << "Created" << std::endl;
        m_Size = strlen(string);
        m_Data = new char[m_Size];
    }

    String(const String& other)
    {
        std::cout << "Created" << std::endl;
        m_Size = other.m_Size;
        m_Data = other.m_Data;
    }

    ~String()
    {
        delete[]m_Data;
    }

    void Print()
    {
        for (size_t i = 0; i < m_Size; i++)
        {
            std::cout << m_Data[i];
        }
        std::cout << std::endl;
    }

private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    Entity(const String& name)
        :m_Name(name)
    {

    }

    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int MoveSemantics::main()
{
    Entity entity(String("Andy"));
    entity.PrintName();
    return 0;
}
