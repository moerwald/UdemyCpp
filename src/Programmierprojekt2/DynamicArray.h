#pragma once
#include <cstddef>
template <typename T>
class DynamicArray
{
public:
    DynamicArray<T>(const T& value, const std::size_t& length);

    void push_back(const T& value);
    void pop_back();

    T& operator[](const std::size_t& index);
    const T& operator[](const std::size_t& index) const;

    std::size_t get_length() const;

private:
    double* m_data;
    std::size_t m_length;
};


template <typename T>
DynamicArray<T>::DynamicArray(const T& value, const std::size_t& length)
{
    m_length = length;
    m_data = new T[length];
    for (size_t i = 0; i < length; i++)
    {
        m_data[i] = value;
    }
}

template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    T* temp = new double[m_length + 1];

    for (size_t i = 0; i < m_length; i++)
    {
        temp[i] = m_data[i];
    }

    temp[m_length] = value;

    delete[] m_data;
    m_data = temp;
    m_length++;

}

template <typename T>
void DynamicArray<T>::pop_back()
{
    double* temp = new double[m_length - 1];

    for (size_t i = 0; i < m_length; i++)
    {
        temp[i] = m_data[i];
    }

    delete[] m_data;
    m_data = temp;
    m_length--;
}

template <typename T>
T& DynamicArray<T>::operator[](const std::size_t& index)
{
    return m_data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](const std::size_t& index) const
{
    return m_data[index];
}

template <typename T>
std::size_t  DynamicArray<T>::get_length() const
{
    return m_length;
}
