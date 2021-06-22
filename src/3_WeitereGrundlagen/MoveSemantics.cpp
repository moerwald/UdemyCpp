#include "MoveSemantics.h"
#include <iostream>
#include <random>

class String
{
public:
    String() = default;
    String(const char* string)
    {
        m_Id = GetRandom();
        std::cout << m_Id << " Created" << std::endl;
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other)
    {
        m_Id = GetRandom();
        std::cout << m_Id <<  " Copied from id " << other.m_Id << std::endl;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other) noexcept
    {
        m_Id = GetRandom();
        std::cout << m_Id <<  " Moving from id " << other.m_Id << std::endl;
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    ~String()
    {
        std::cout << m_Id << " Destroyed" << std::endl;
        delete[] m_Data;
    }

    void Print()
    {
        for (size_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    char* m_Data;
    uint32_t m_Size;
    double m_Id;

    double GetRandom()
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 100.0);
        return dist(mt);
    }
};

class Entity
{
public:
    Entity(const String& name)
        :m_Name(name)
    {
    }

    Entity(String&& name)
        :m_Name(std::move(name))
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
