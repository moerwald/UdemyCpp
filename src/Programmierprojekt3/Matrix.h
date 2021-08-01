#pragma once

#include <iostream>

template <typename T>
class Matrix
{
    public:
    Matrix()
        : m_A(0)
        , m_B(0)
        , m_C(0)
        , m_D(0)
    {
    }

    Matrix(const T& a,
           const T& b,
           const T& c,
           const T& d)
        : m_A(a)
        , m_B(b)
        , m_C(c)
        , m_D(d)
    {
    }

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

    void set_A(const T& a);
    void set_B(const T& b);
    void set_C(const T& c);
    void set_D(const T& d);

    T get_A() const;
    T get_B() const;
    T get_C() const;
    T get_D() const;

    void print();

private:
    T m_A;
    T m_B;
    T m_C;
    T m_D;
};


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
    std::cout << m_A << ", " << m_B << std::endl;
    std::cout << m_C << ", " << m_D << std::endl;
    std::cout << std::endl;
}


