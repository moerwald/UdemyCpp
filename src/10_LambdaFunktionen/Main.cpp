
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

int main()
{
    std::vector<int> vec(10, 0);
    std::iota(vec.begin(), vec.end(), 0);

    std::vector<int> vec_copied;
    std::copy_if(vec.begin(),
        vec.end(),
        std::back_inserter(vec_copied),
        [](int val) { return val % 2 == 0 ? true : false; });

    constexpr auto upper_bound = 5;
    auto it_of_values_to_remove = std::remove_if(vec.begin(),
                   vec.end(),
                   [upper_bound](int val) {
                        if (val < upper_bound)
                            return true;
                        return false;
                   });

    vec.erase(it_of_values_to_remove, vec.end());
    return 0;
}
