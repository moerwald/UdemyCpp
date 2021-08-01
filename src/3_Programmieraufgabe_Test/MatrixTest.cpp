#include "pch.h"
#include "../Programmierprojekt3/Matrix.h"

TEST(MatrixTests, FieldsAreCorrectlySet) {

    Matrix<int> m1(1, 2, 3, 4);

    EXPECT_EQ(m1.get_A(), 1);
    EXPECT_EQ(m1.get_B(), 2);
    EXPECT_EQ(m1.get_C(), 3);
    EXPECT_EQ(m1.get_D(), 4);
}

TEST(MatrixTests, MatrixAddition) {

    Matrix<int> m1(1, 2, 3, 4);
    Matrix<int> m2(1, 2, 3, 4);

    m1 += m2;

    EXPECT_EQ(m1.get_A(), 2);
    EXPECT_EQ(m1.get_B(), 4);
    EXPECT_EQ(m1.get_C(), 6);
    EXPECT_EQ(m1.get_D(), 8);
}

TEST(MatrixTests, MatrixSubstraction) {

    Matrix<int> m1(1, 2, 3, 4);
    Matrix<int> m2(1, 2, 3, 4);

    m1 -= m2;

    EXPECT_EQ(m1.get_A(), 0);
    EXPECT_EQ(m1.get_B(), 0);
    EXPECT_EQ(m1.get_C(), 0);
    EXPECT_EQ(m1.get_D(), 0);
}

TEST(MatrixTests, MatrixMultiplication) {

    Matrix<int> m1(1, 2, 3, 4);
    Matrix<int> m2(5, 6, 7, 8);

    auto m3 = m1 * m2;

    EXPECT_EQ(m3.get_A(), 19);
    EXPECT_EQ(m3.get_B(), 22);
    EXPECT_EQ(m3.get_C(), 43);
    EXPECT_EQ(m3.get_D(), 53);
}

TEST(MatrixTests, ScalarMultiplication) {

    Matrix<int> m1(1, 2, 3, 4);

    auto m3 = m1 * 2;

    EXPECT_EQ(m3.get_A(), 2);
    EXPECT_EQ(m3.get_B(), 4);
    EXPECT_EQ(m3.get_C(), 6);
    EXPECT_EQ(m3.get_D(), 8);
}



