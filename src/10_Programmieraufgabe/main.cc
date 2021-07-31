
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

//int main()
int main()
{
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(1, 52);

    std::vector<int> my_vector(10, 0);
    std::vector<int> my_result(10, 0);
    std::generate(my_vector.begin(), my_vector.end(), [&] { return dist(gen); });

    for (const auto& val : my_vector)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    // Aufgabe 1

    auto has_no_even = std::ranges::none_of(my_vector.begin(), my_vector.end(), [](auto x) {return x % 2 == 0; });
    if (has_no_even)
    {
        std::cout << "None of them are even" << std::endl;
    }
    else
    {
        std::cout << "Has even numbers" << std::endl;
    }

    // Aufgabe 2
    //...
    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), [](auto x) { return pow(x, 2.0); });

    for (const auto& val : my_result)
    {
        std::cout << val << std::endl;
    }

    std::cin.get();

    return 0;
}
