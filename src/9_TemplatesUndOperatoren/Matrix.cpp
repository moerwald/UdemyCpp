#include "Matrix.h"
#include <iostream>

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

