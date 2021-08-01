#pragma once

#include <iostream>
#include <vector>

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
Matrix<T>:: Matrix(std::size_t rows, std::size_t columns, T& value)
     : m_rows(rows)
     , m_columns(columns)
     , m_data(rows, std::vector<T>(columns, value))
{

}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
    return Matrix(
        get_A() + rhs.get_A(),
        get_B() + rhs.get_B(),
        get_C() + rhs.get_C(),
        get_D() + rhs.get_D()
    );
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
    set_A(get_A() + rhs.get_A());
    set_B(get_B() + rhs.get_B());
    set_C(get_C() + rhs.get_C());
    set_D(get_D() + rhs.get_D());

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
{
    return Matrix(
        get_A() - rhs.get_A(),
        get_B() - rhs.get_B(),
        get_C() - rhs.get_C(),
        get_D() - rhs.get_D()
    );
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
{
    set_A(get_A() - rhs.get_A());
    set_B(get_B() - rhs.get_B());
    set_C(get_C() - rhs.get_C());
    set_D(get_D() - rhs.get_D());
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs)
{
    return Matrix(
        get_A() * rhs,
        get_B() * rhs,
        get_C() * rhs,
        get_D() * rhs
    );
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& rhs)
{
    set_A(get_A() * rhs);
    set_B(get_B() * rhs);
    set_C(get_C() * rhs);
    set_D(get_D() * rhs);

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
    return Matrix(
        get_A() * rhs.get_A() + get_B() * rhs.get_C(),
        get_A() * rhs.get_B() + get_B() * rhs.get_D(),
        get_C() * rhs.get_A() + get_D() * rhs.get_C(),
        get_C() * rhs.get_C() + get_D() * rhs.get_D()
    );
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
{
    *this = *this * rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs)
{
    return Matrix(
        get_A() / rhs,
        get_B() / rhs,
        get_C() / rhs,
        get_D() / rhs
    );
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(const T& rhs)
{
    set_A(get_A() / rhs);
    set_B(get_B() / rhs);
    set_C(get_C() / rhs);
    set_D(get_D() / rhs);
    return *this;
}

template<typename T>
void Matrix<T>::set_A(const T& a)
{
    m_A = a;
}

template<typename T>
void Matrix<T>::set_B(const T& b)
{
    m_B = b;
}

template<typename T>
void Matrix<T>::set_C(const T& c)
{
    m_C = c;
}

template<typename T>
void Matrix<T>::set_D(const T& d)
{
    m_D = d;
}

template<typename T>
T Matrix<T>::get_A() const
{
    return m_A;
}

template<typename T>
T Matrix<T>::get_B() const
{
    return m_B;
}

template<typename T>
T Matrix<T>::get_C() const
{
    return m_C;
}

template<typename T>
T Matrix<T>::get_D() const
{
    return m_D;
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


