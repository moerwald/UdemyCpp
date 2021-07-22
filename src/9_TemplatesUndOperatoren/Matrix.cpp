#include "Matrix.h"
#include <iostream>

Matrix Matrix::operator+(const Matrix& rhs)
{
    return Matrix(
        get_A() + rhs.get_A(),
        get_B() + rhs.get_B(),
        get_C() + rhs.get_C(),
        get_D() + rhs.get_D()
    );
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    set_A(get_A() + rhs.get_A());
    set_B(get_B() + rhs.get_B());
    set_C(get_C() + rhs.get_C());
    set_D(get_D() + rhs.get_D());

    return *this;
}

Matrix Matrix::operator-(const Matrix& rhs)
{
    return Matrix(
        get_A() - rhs.get_A(),
        get_B() - rhs.get_B(),
        get_C() - rhs.get_C(),
        get_D() - rhs.get_D()
    );
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    set_A(get_A() - rhs.get_A());
    set_B(get_B() - rhs.get_B());
    set_C(get_C() - rhs.get_C());
    set_D(get_D() - rhs.get_D());
    return *this;
}

Matrix Matrix::operator*(const double& rhs)
{
    return Matrix(
        get_A() * rhs,
        get_B() * rhs,
        get_C() * rhs,
        get_D() * rhs
    );
}

Matrix& Matrix::operator*=(const double& rhs)
{
    // TODO: insert return statement here
}

Matrix Matrix::operator*(const Matrix& rhs)
{
    return Matrix();
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
    // TODO: insert return statement here
}

Matrix Matrix::operator/(const double& rhs)
{
    return Matrix();
}

Matrix& Matrix::operator/=(const double& rhs)
{
    // TODO: insert return statement here
}

Matrix Matrix::operator/(const Matrix& rhs)
{
    return Matrix();
}

Matrix& Matrix::operator/=(const Matrix& rhs)
{
    // TODO: insert return statement here
}

void Matrix::set_A(const double& a)
{
    m_A = a;
}

void Matrix::set_B(const double& b)
{
    m_B = b;
}

void Matrix::set_C(const double& c)
{
    m_C = c;
}

void Matrix::set_D(const double& d)
{
    m_D = d;
}

double Matrix::get_A() const
{
    return m_A;
}

double Matrix::get_B() const
{
    return m_B;
}

double Matrix::get_C() const
{
    return m_C;
}

double Matrix::get_D() const
{
    return m_D;
}

void Matrix::print()
{
    std::cout << m_A << ", " << m_B << std::endl;
    std::cout << m_C << ", " << m_D << std::endl;
    std::cout << std::endl;
}

