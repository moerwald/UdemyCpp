#pragma once
#include <cstddef>
#include <iostream>
#include <utility>

template <typename T>
class DynamicArray
{
public:
    DynamicArray(const T& value, const std::size_t& length);
    DynamicArray();

    // Rule of five
    ~DynamicArray() noexcept;
    DynamicArray(const DynamicArray<T>& rhs);
    DynamicArray<T>& operator=(const DynamicArray<T>& rhs);
    DynamicArray(DynamicArray<T>&& rhs) noexcept;
    DynamicArray<T>& operator=(DynamicArray<T>&& rhs) noexcept;

    void push_back(const T& value);
    void pop_back();

    T& operator[](const std::size_t& index);
    const T& operator[](const std::size_t& index) const;

    std::size_t length() const;

private:
    std::size_t m_length;
    std::size_t m_capacity;
    T* m_data;
};

template <typename T>
DynamicArray<T>::DynamicArray()
    : m_length(0)
    , m_capacity(1)
    , m_data(new T[m_capacity])
{
}

template <typename T>
DynamicArray<T>::DynamicArray(const T& value, const std::size_t& length)
    : m_length(length)
    , m_capacity(length == 0 ? 1 : m_length)
    , m_data(new T[m_capacity])

{
    for (size_t i = 0; i < length; i++)
    {
        m_data[i] = value;
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& rhs)
    : m_length(rhs.m_length)
    , m_capacity(rhs.m_capacity)
    , m_data(rhs.m_length > 0 ? new T[rhs.m_length] : nullptr)
{
    std::cout << "copy CTOR" << std::endl;
}


template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& rhs) noexcept :
    m_length(std::move(rhs.m_length)),
    m_capacity(std::move(rhs.m_capacity)),
    m_data(std::move(rhs.m_data))
{
    rhs.m_length = 0;
    rhs.m_capacity = 0;
    rhs.m_data = nullptr;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& rhs) noexcept
{
    if (this != &rhs)
    {
        delete[] m_data;

        m_length = std::move(rhs.m_length);
        m_capacity = std::move(rhs.m_capacity);
        m_data = std::move(rhs.m_data);

        rhs.m_length = 0;
        rhs.m_capacity = 0;
        rhs.m_data = nullptr;
    }

    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    if (m_length != rhs.m_length)
    {
        delete[] m_data;
        m_data = nullptr;

        m_length = rhs.m_length;
        m_capacity = rhs.m_capacity;

        if (m_length > 0)
        {
            m_data = new T[m_length];
        }
    }

    for (size_t i = 0; i < m_length; i++)
    {
        m_data[i] = rhs.m_data[i];
    }

    std::cout << "assignment operator" << std::endl;

    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() noexcept
{
    delete[] m_data;
}

template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    if (m_length == m_capacity)
    {
        // Increase capacity
        m_capacity *= 2;
        T* temp = new T[m_capacity];

        // Copy memory to new one
        for (size_t i = 0; i < m_length; i++)
        {
            temp[i] = m_data[i];
        }

        // delete old memory
        delete[] m_data;
        m_data = temp;
    }

    // Append to the end
    m_data[m_length] = value;
    m_length++;

}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (m_length == 0)
    {
        return;
    }

    m_length--;
    if (m_length < (m_capacity / 2))
    {
        m_capacity /= 2;
        T* temp = new T[m_capacity];

        for (size_t i = 0; i < m_length; i++)
        {
            temp[i] = m_data[i];
        }

        delete[] m_data;
        m_data = temp;
    }

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
std::size_t  DynamicArray<T>::length() const
{
    return m_length;
}
