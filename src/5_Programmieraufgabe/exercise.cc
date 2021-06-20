
#include "exercise.h"
#include <algorithm>

std::vector<double> maw_row_values(Matrix& matrix)
{
    std::vector<double> max_vec;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        const auto &row = matrix[i];
        auto max = 0.0;

        for (auto val : row)
            if (val > max)
                max = val;

        max_vec.push_back(max);
    }

    return max_vec;
}

double sort_and_max(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end());
    vec.back();
}
