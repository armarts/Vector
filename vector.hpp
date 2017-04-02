#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

template <typename value_type>
Vector<value_type>::Vector() : m_capacity(0), m_size(0), m_data(NULL) {

}

template <typename value_type>
Vector<value_type>::Vector(const std::size_t count, const value_type& value) : m_capacity(count), m_size(count), m_data(new value_type[count]) {
  for (std::size_t i = 0; i < count; i++)
    m_data[i] = value;
}

template <typename value_type>
Vector<value_type>::Vector(const std::size_t count) : m_capacity(count), m_size(count), m_data(new value_type[count]) {

}

template <typename value_type>
Vector<value_type>::Vector(const Vector<value_type>& other) : m_capacity(other.size()), m_size(other.size()), m_data(new value_type[m_capacity]) {
  for (std::size_t i = 0; i < other.size(); i++)
    m_data[i] = other[i];
}

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> init) : m_capacity(init.size()), m_size(init.size()), m_data(new value_type[m_capacity]) {
  std::size_t j = 0;
  for (auto i = init.begin(); i != init.end(); i++) {
    m_data[j] = *i;
    j++;
  }
}

template <typename value_type>
Vector<value_type>::~Vector() {
  if (m_data)
    delete [] m_data;
  m_data = NULL;
  m_capacity = -1;
  m_size = -1;
}

template <typename value_type>
const Vector<value_type>& Vector<value_type>::operator = (const Vector<value_type>& other) {
  for (std::size_t i = 0; i < other.size(); i++)
    m_data[i] = other[i];
}

template <typename value_type>
value_type& Vector<value_type>::operator [] (const int pos) {
  if (pos < 0 || pos >= int(m_size))
    throw Exception(OUT_OF_BOUNDS, "\nError Vector []: OUT_OF_BOUNDS\n");
  return m_data[pos];
}


template <typename value_type>
const value_type& Vector<value_type>::operator [] (const int pos) const {
  if (pos < 0 || pos >= int(m_size))
    throw Exception(OUT_OF_BOUNDS, "\nError Vector []: OUT_OF_BOUNDS\n");
  return m_data[pos];
}

template <typename value_type>
value_type& Vector<value_type>::front() {
  if (m_size == 0)
    throw Exception(UNDEFINE_BEHAVIOR, "\nError front()\n");
  return m_data[0];
}

template <typename value_type>
const value_type& Vector<value_type>::front() const {
  if (m_size == 0)
    throw Exception(UNDEFINE_BEHAVIOR, "\nError front()\n");
  return m_data[0];
}

template <typename value_type>
value_type& Vector<value_type>::back() {
  if (m_size == 0)
    throw Exception(UNDEFINE_BEHAVIOR, "\nError back()\n");
  return m_data[0];
}

template <typename value_type>
const value_type& Vector<value_type>::back() const {
  if (m_size == 0)
    throw Exception(UNDEFINE_BEHAVIOR, "\nError back()\n");
  return m_data[0];
}

template <typename value_type>
bool Vector<value_type>::empty() const {
  return (begin() == end());
}

template <typename value_type>
std::size_t Vector<value_type>::size() const {
  return m_size;
}


template <typename value_type>
std::size_t Vector<value_type>::capacity() const {
  return m_capacity;
}

template <typename value_type>
void Vector<value_type>::clear() {
  m_size = 0;
}

template <typename value_type>
void Vector<value_type>::push_back(const value_type& value) {
  if (m_size == m_capacity)
    resize(m_capacity * 2 + 1);
  m_data[m_size++] = value;
}

template <typename value_type>
void Vector<value_type>::pop_back() {
  if (empty())
    throw Exception(UNDEFINE_BEHAVIOR, "\nError pop_back(): Vector is empty()\n");
  m_size--;
}

template <typename value_type>
void Vector<value_type>::resize(std::size_t count) {
  value_type* mem = (value_type*) realloc(m_data, count * sizeof(value_type));
  if (mem == NULL)
    throw Exception(BAD_ALLOC, "\nNOT ENOUGH MEMORY\n");
  m_capacity = count;
  m_size = count;
  m_data = mem;
}


template <typename value_type>
void Vector<value_type>::resize(std::size_t count, const value_type& value) {
  value_type* mem = (value_type*) realloc(m_data, count * sizeof(value_type));
  if (mem == NULL)
    throw Exception(BAD_ALLOC, "\nNOT ENOUGH MEMORY\n");
  m_capacity = count;
  m_data = mem;
  for (std::size_t i = size() ; i < capacity(); i++)
    m_data[i] = value;
  m_size = count;
}

template <typename value_type>
void Vector<value_type>::swap(Vector<value_type>& other) {
  std::swap(other.m_data, m_data);
  std::swap(other.m_size, m_size);
  std::swap(other.m_capacity, m_capacity);
}

template<typename TT>
bool operator == (Vector<TT>& lhs, Vector<TT>& rhs) {
  if (lhs.size() != rhs.size())
    return false;
  for (std::size_t i = 0; i < lhs.size(); i++)
    if (lhs[i] != rhs[i])
      return false;
  return true;
}

template<typename TT>
bool operator != (Vector<TT>& lhs, Vector<TT>& rhs) {
  return !(lhs == rhs);
}

template<typename TT>
bool operator < (Vector<TT>& lhs, Vector<TT>& rhs) {
  if (lhs.size() > rhs.size())
    return false;
  if (lhs.size() < rhs.size())
    return true;
  for (std::size_t i = 0; i < lhs.size(); i++)
    if (lhs[i] >= rhs[i])
      return false;
  return true;
}

template<typename TT>
bool operator <= (Vector<TT>& lhs, Vector<TT>& rhs) {
  if (lhs.size() > rhs.size())
    return false;
  if (lhs.size() < rhs.size())
    return true;
  for (std::size_t i = 0; i < lhs.size(); i++)
    if (lhs[i] > rhs[i])
      return false;
  return true;
}

template<typename TT>
bool operator > (Vector<TT>& lhs, Vector<TT>& rhs) {
  if (lhs.size() < rhs.size())
    return false;
  if (lhs.size() > rhs.size())
    return true;
  for (std::size_t i = 0; i < lhs.size(); i++)
    if (lhs[i] <= rhs[i])
      return false;
  return true;
}

template<typename TT>
bool operator >= (Vector<TT>& lhs, Vector<TT>& rhs) {
  if (lhs.size() < rhs.size())
    return false;
  if (lhs.size() > rhs.size())
    return true;
  for (std::size_t i = 0; i < lhs.size(); i++)
    if (lhs[i] < rhs[i])
      return false;
  return true;
}

#endif
