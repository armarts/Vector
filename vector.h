#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "exception.h"
#include <initializer_list>
#include <cstdlib>

template <typename T>
class Vector {
  public:

    typedef T value_type;

    class Iterator {

      public:

        explicit Iterator(value_type*  ptr) : m_ptr(ptr) {}
        ~Iterator() {}

        value_type& operator*() { return *m_ptr; }
        value_type* operator->() { return m_ptr; }

        void operator++() { ++m_ptr; }
        void operator--() { --m_ptr; }
        bool operator==(const Iterator& other) const { return (m_ptr == other.m_ptr); }
        bool operator!=(const Iterator& other) const { return !(*this == other); }

      private:

        value_type* m_ptr;

    };

    Vector();
    Vector(std::size_t count, const value_type& value);
    explicit Vector(const std::size_t count);
    Vector(const Vector& other);
    Vector(std::initializer_list<value_type> init);
    ~Vector();

    const Vector& operator = (const Vector& other);

    // Element Access

    value_type& operator [](const int pos);
    const value_type& operator [](const int pos) const;

    value_type& front();
    const value_type& front() const;

    value_type& back();
    const value_type& back() const;

    // Iterator

    Iterator begin() const {
        Iterator tmp(m_data);
        return tmp;
    }

    Iterator end() const {
        Iterator tmp(m_data + size());
        return tmp;
    }

    // Capacity

    bool empty() const;

    std::size_t size() const;

    std::size_t capacity() const;

    // Modifiers

    void clear();

    void push_back(const value_type& value);
    void pop_back();
    void resize(std::size_t count);
    void resize(std::size_t count, const value_type& value);
    void swap(Vector& other);

    template<typename TT>
    friend bool operator == (Vector<TT>& lhs, Vector<TT>& rhs);

    template<typename TT>
    friend bool operator != (Vector<TT>& lhs, Vector<TT>& rhs);

    template<typename TT>
    friend bool operator <  (Vector<TT>& lhs, Vector<TT>& rhs);

    template<typename TT>
    friend bool operator <= (Vector<TT>& lhs, Vector<TT>& rhs);

    template<typename TT>
    friend bool operator >  (Vector<TT>& lhs, Vector<TT>& rhs);

    template<typename TT>
    friend bool operator >= (Vector<TT>& lhs, Vector<TT>& rhs);

  private:

    size_t m_capacity;
    size_t m_size;

    T *m_data;

};

#include "vector.hpp"

#endif
