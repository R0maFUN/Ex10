// Copyright Roman Balayan @ 2021

#pragma once

#include <cassert>

using u_int = unsigned int;

template<class T>
class MyStack {
 private:
     T* values;
     u_int size;
     u_int reserved_size;
 public:
     MyStack(u_int sz) : reserved_size(sz) {
         this->size = 0;
         this->values = new T[reserved_size];
     }
     MyStack(const MyStack& rhv) {
         this->reserved_size = rhv.reserved_size;
         this->values = new T[this->reserved_size];
         for (int i = 0; i < rhv.size; ++i)
             this->values[i] = rhv.values[i];
         this->size = rhv.size;
     }
     ~MyStack() {
         delete[] this->values;
     }
     T& get() const;
     T& pop();
     void push(const T& val);
     bool isFull() const;
     bool isEmpty() const;
};

template <class T>
T& MyStack<T>::get() const {
    return this->values[this->size - 1];
}

template<class T>
T& MyStack<T>::pop() // Warning memory leak
{
    return this->values[--this->size];
}

template<class T>
void MyStack<T>::push(const T& val) // Warning memory leak
{
    assert(this->size < this->reserved_size);
    this->values[this->size] = val;
    this->size++;
}

template<class T>
inline bool MyStack<T>::isFull() const
{
    return this->size == this->reserved_size;
}

template<class T>
inline bool MyStack<T>::isEmpty() const
{
    return this->size == 0;
}

