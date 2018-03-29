#include <iostream>
using namespace std;

template <class T>
class stackhere{
public:
    stackhere();
    ~stackhere();
    void push(T value);
    T pop();
    T top();
    int size();
    stackhere & operator<<(T value);
    stackhere & operator>>(T value);
    T * m_data;
private:
    void expand();

    int m_size;
    int m_capacity;
};
template <class T>
stackhere<T>::stackhere()
{
    m_size = 0;
    m_capacity = 8;
    m_data = new T[m_capacity];
}

template <class T>
stackhere<T>::~stackhere()
{
    delete[] m_data;
}

template <class T>
void stackhere<T>::push(T value)
{
    if (m_size == m_capacity) {
        expand ();
    }
    m_data[m_size] = value;
    ++m_size;
}

template <class T>
T stackhere<T>::pop()
{
    if (0 == m_size) {
        cout<<"Perepolneno"<<endl;
    }
    return m_data[--m_size];
}

template <class T>
T stackhere<T>::top()
{
    if (0 == m_size) {
        cout<<"Perepolneno"<<endl;

    }
    return m_data[m_size - 1];
}

template <class T>
int stackhere<T>::size()
{
    return m_size;
}

template <class T>
void stackhere<T>::expand()
{
    m_capacity *= 2;
    T * new_data = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
}

template <class T>
stackhere<T>&stackhere<T>::operator<<(T value)
{
    push (value);
    return *this;
}

template <class T>
stackhere<T>&stackhere<T>::operator>>(T value)
{
    value = pop ();
    return *this;
}
