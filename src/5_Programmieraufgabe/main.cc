#include "exercise.h"
#include <iostream>

int main()
{
    Matrix matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; i < matrix[i].size(); i++)
        {
            std::cout << "[" << i << "][" << j << "]: " << matrix[i][j] << std::endl;
        }
    }

    auto max_row_vals = maw_row_values(matrix);



    return 0;
}
