#include "OwnString.h"
#include <iostream>
#include <random>


OwnString::OwnString()
{
    m_Id = GetRandom();
    std::cout << m_Id << " Created via default CTOR" << std::endl;
}

OwnString::OwnString(const char* string)
{
    m_Id = GetRandom();
    std::cout << m_Id << " Created" << std::endl;
    m_Size = strlen(string);
    m_Data = new char[m_Size];
    memcpy(m_Data, string, m_Size);
}

OwnString::OwnString(const OwnString& other)
{
    m_Id = GetRandom();
    std::cout << m_Id << " Copied from id " << other.m_Id << std::endl;
    m_Size = other.m_Size;
    m_Data = new char[m_Size];
    memcpy(m_Data, other.m_Data, m_Size);
}

OwnString::OwnString(OwnString&& other) noexcept
{
    m_Id = GetRandom();
    std::cout << m_Id << " Moving from id " << other.m_Id << std::endl;
    m_Size = other.m_Size;
    m_Data = other.m_Data;

    other.m_Data = nullptr;
    other.m_Size = 0;
}

OwnString& OwnString::operator=(OwnString&& other) noexcept
{
    std::cout << m_Id << " Moving via =-operator from id " << other.m_Id << std::endl;
    if (this != &other)
    {
        delete[] m_Data;
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0;
    }
    return *this;
}

OwnString::~OwnString()
{
    std::cout << m_Id << " Destroyed" << std::endl;
    delete[] m_Data;
}

void OwnString::Print()
{
    for (size_t i = 0; i < m_Size; i++)
    {
        printf("%c", m_Data[i]);
    }
    printf("\n");
}


double OwnString::GetRandom()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 100.0);
    return dist(mt);
}
