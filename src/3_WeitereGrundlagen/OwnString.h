#pragma once
class OwnString
{

public:
    OwnString();

    OwnString(const char* string);

    OwnString(const OwnString& other);

    OwnString(OwnString&& other) noexcept;

    OwnString& operator=(OwnString&& other) noexcept;

    ~OwnString();

    void Print();

private:
    char* m_Data;
    uint32_t m_Size;
    double m_Id;

    double GetRandom();
};

