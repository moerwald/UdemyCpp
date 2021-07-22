#pragma once
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

    Matrix(const double& a,
           const double& b,
           const double& c,
           const double& d)
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

    Matrix operator*(const double& rhs);
    Matrix& operator*=(const double& rhs);
    Matrix operator*(const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);
    Matrix operator/(const double& rhs);
    Matrix& operator/=(const double& rhs);

    void set_A(const double& a);
    void set_B(const double& b);
    void set_C(const double& c);
    void set_D(const double& d);

    double get_A() const;
    double get_B() const;
    double get_C() const;
    double get_D() const;

    void print();

private:
    double m_A;
    double m_B;
    double m_C;
    double m_D;
};

