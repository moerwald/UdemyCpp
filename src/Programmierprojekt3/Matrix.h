#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class Matrix
{
public:

    using MatrixDataType = std::vector<std::vector<T>>;
    Matrix() = delete;
    Matrix(std::size_t rows, std::size_t columns);
    Matrix(std::size_t rows, std::size_t columns, T& value);

    Matrix operator+(const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);

    Matrix operator*(const T& rhs);
    Matrix& operator*=(const T& rhs);
    Matrix operator*(const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);
    Matrix operator/(const T& rhs);
    Matrix& operator/=(const T& rhs);

    const T& get(std::size_t row, std::size_t column) const;

    void print();

private:
    std::size_t m_rows;
    std::size_t m_columns;
    MatrixDataType m_data;
};

template<typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t columns)
    : m_rows(rows)
    , m_columns(columns)
    , m_data(rows, std::vector<T>(columns))
{

}

template<typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t columns, T& value)
    : m_rows(rows)
    , m_columns(columns)
    , m_data(rows, std::vector<T>(columns, value))
{

}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
    Matrix<T> result(m_rows, m_columns);

    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            rhs.m_data[row].begin(),
            result.m_data[row].begin(),
            std::plus<T>()
        );
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            rhs.m_data[row].begin(),
            m_data[row].begin(),
            std::plus<T>()
        );
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
{
    Matrix<T> result(m_rows, m_columns);

    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            rhs.m_data[row].begin(),
            result.m_data[row].begin(),
            std::minus<T>()
        );
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
{
    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            rhs.m_data[row].begin(),
            m_data[row].begin(),
            std::minus<T>()
        );
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar)
{
    Matrix<T> result(m_rows, m_columns);
    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            result.m_data[row].begin(),
            [&scalar](const T& val) { return scalar * val; }
        );
    }
    return result;
}


template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& scalar)
{
    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            m_data[row].begin(),
            [&scalar](const T& val) { return scalar * val; }
        );
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
    Matrix<T> result(m_rows, m_columns);
    for (size_t row = 0; row < m_rows; row++)
    {
        for (size_t rhs_column = 0; rhs_column < rhs.m_columns; rhs_column++)
        {
            for (size_t rhs_row = 0; rhs_row < rhs.m_rows; rhs_row++)
            {
                result.m_data[row][rhs_column] = result.m_data[row][rhs_column] +
                                          m_data[row][rhs_row] * rhs.m_data[rhs_row][rhs_column];
            }
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
{
    *this = *this * rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& scalar)
{
    for (size_t row = 0; row < m_data.size(); row++)
    {
        std::transform(
            m_data[row].begin(),
            m_data[row].end(),
            m_data[row].begin(),
            [&scalar](const T& val) { return scalar / val; }
        );
    }

    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(const T& scalar)
{
    *this = *this / scalar;
    return *this;
}

template<typename T>
const T& Matrix<T>::get(std::size_t row, std::size_t column) const
{
    return m_data[row][column];
}

template<typename T>
void Matrix<T>::print()
{
    for (size_t row = 0; row < m_data.size(); row++)
    {
        for (size_t column = 0; column < m_data[row].size(); column++)
        {
            std::cout << m_data[row][column] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}


