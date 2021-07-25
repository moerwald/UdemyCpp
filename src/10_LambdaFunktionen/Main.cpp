
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
    return 0;
}
