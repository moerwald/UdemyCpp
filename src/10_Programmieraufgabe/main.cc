
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
    auto check_has_no_even = [](std::vector<int>::iterator it_begin, const std::vector<int>::iterator it_end) {
        while (it_begin != it_end)
        {
            if (*it_begin % 2 == 0)
            {
                return false;
            }

            it_begin++;
        }

        return true;
    };

    auto has_no_even = check_has_no_even(my_vector.begin(), my_vector.end());

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
    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), [](int x) { pow(x, 2.0); });

    for (const auto& val : my_result)
    {
        std::cout << val << std::endl;
    }

    std::cin.get();

    return 0;
}
