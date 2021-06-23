#include "MoveSemantics2.h"
#include <iostream>
#include <random>

class String
{
public:
    String()
    {
        m_Id = GetRandom();
        std::cout << m_Id << " Created via default CTOR" << std::endl;
    }

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
        std::cout << m_Id << " Copied from id " << other.m_Id << std::endl;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other) noexcept
    {
        m_Id = GetRandom();
        std::cout << m_Id << " Moving from id " << other.m_Id << std::endl;
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    String& operator=(String&& other) noexcept
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


int MoveSemantics2::main()
{
    String string = "Hello";
    auto dest_copy_of_string = string;                                  // Creates a copy!!!
    auto dest_moved_from_string = std::move(string);                    // Lets convert string to a temporary, calls the move-CTOR!!! Therefore
                                                                        // dest_moved_from_string is a NEW object, which will take ownership
                                                                        // of string-object memory!!!
    // auto dest_moved_from_string_via_move_ctor(std::move(string));    // Equivalent as code above, BUT harder to read
    // auto dest_moved_from_string_via_move_ctor((String&&)string);     // Cast is also support, but std::move is more flexible
    dest_moved_from_string = std::move(string);                         // Object already created compiler will call move-assignment-operator!

    String apple = "Apple";
    String dest;
    String& dest1 = apple;

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
