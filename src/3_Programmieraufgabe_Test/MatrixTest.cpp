#include "pch.h"
#include "../Programmierprojekt3/Matrix.h"

TEST(MatrixTests, FieldsAreCorrectlySet) {

    constexpr int rows = 3;
    constexpr int columns = rows;
    auto val = 2;
    Matrix<int> m1(rows, columns, val);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; i < columns; j++)
        {
            EXPECT_EQ(m1.get(i, j), 2);
        }
    }
}

TEST(MatrixTests, MatrixAddition) {

    constexpr int rows = 3;
    constexpr int columns = rows;
    auto val = 2;
    Matrix<int> m1(rows, columns, val);
    val = 3;
    Matrix<int> m2(rows, columns, val);

    auto& m3 = std::move(m1 + m2);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; i < columns; j++)
        {
            EXPECT_EQ(m1.get(i, j), 5);
        }
    }
}

TEST(MatrixTests, MatrixSubstraction) {

    constexpr int rows = 3;
    constexpr int columns = rows;
    auto val = 2;
    Matrix<int> m1(rows, columns, val);
    val = 3;
    Matrix<int> m2(rows, columns, val);

    auto& m3 = std::move(m1 + m2);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; i < columns; j++)
        {
            EXPECT_EQ(m1.get(i, j), -1);
        }
    }
}

TEST(MatrixTests, MatrixMultiplication) {

    constexpr int rows = 3;
    constexpr int columns = rows;
    auto val = 2;
    Matrix<int> m1(rows, columns, val);

    val = 3;
    Matrix<int> m2(rows, columns, val);

    auto m3 = std::move(m1 * m2);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; i < columns; j++)
        {
            EXPECT_EQ(m3.get(i, j), 2);
        }
    }
}

TEST(MatrixTests, ScalarMultiplication) {

    constexpr int rows = 3;
    constexpr int columns = rows;
    auto val = 2;
    Matrix<int> m1(rows, columns, val);

    auto& m3 = std::move(m1 * 2);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; i < columns; j++)
        {
            EXPECT_EQ(m3.get(i, j), 2);
        }
    }
}



