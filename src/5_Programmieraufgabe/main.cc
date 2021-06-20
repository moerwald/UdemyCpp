#include "exercise.h"
#include <iostream>

int main()
{
    Matrix matrix{
        {3,1,2},
        {6,0,4},
        {9,7,2}
    };

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            std::cout << "[" << i << "][" << j << "]: " << matrix[i][j] << std::endl;
        }
    }

    auto max_row_vec = maw_row_values(matrix);
    for (auto val : max_row_vec)
        std::cout << "Max in row: " << val << std::endl;

    std::cout << "Overall max: " << sort_and_max(max_row_vec) << std::endl;





    return 0;
}
