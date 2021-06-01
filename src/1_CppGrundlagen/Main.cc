#include <iostream>

int AddVars()
{
    int zahl1{};
    int zahl2{};
    int ergebnis;

    ergebnis = zahl1 + zahl2;

    return ergebnis;
}

void DataTypes()
{
    // bools are represented as numeric value. True = 1, false = 0;
    bool boolIsFalse = false;
    auto boolIsTrue = !boolIsFalse;

    std::cout << boolIsFalse << std::endl;
    std::cout << boolIsTrue << std::endl;

    // chars represent single letters, for UTF other types are needed
    auto letter = 'a';
    std::cout << letter << std::endl;

    unsigned char uLetter = 97;
    std::cout << uLetter << std::endl;

}

int main(void)
{
	std::cout << "Hello World!" << std::endl;
    AddVars();
    DataTypes();

	return 0;
}


