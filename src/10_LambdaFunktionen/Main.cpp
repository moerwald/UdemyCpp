
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>

int main()
{
    auto print_vec = [](const std::vector<int>& v) {
        for (auto& el : v)
        {
            std::cout << el << ", ";
        }
        std::cout << std::endl;
    };

    std::vector<int> vec(10, 0);
    std::iota(vec.begin(), vec.end(), 0);

    print_vec(vec);

    std::vector<int> vec_copied;
    std::copy_if(vec.begin(),
        vec.end(),
        std::back_inserter(vec_copied),
        [](const int& val) { return val % 2 == 0 ? true : false; });
    print_vec(vec_copied);

    constexpr auto upper_bound = 5;
    auto it_of_values_to_remove = std::remove_if(vec.begin(),
        vec.end(),
        [upper_bound](const int& val) {
            if (val < upper_bound)
                return true;
            return false;
        });

    vec.erase(it_of_values_to_remove, vec.end());
    print_vec(vec);
    return 0;
}
