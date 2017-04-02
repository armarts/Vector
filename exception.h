/*
 * Exception class
 *  Arguments are code error & msg
 *
 * Author: Atayan Garik
 */

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <cstddef>

enum {OUT_OF_BOUNDS, INVALID_SIZE, UNDEFINE_BEHAVIOR, BAD_ALLOC};

class Exception : public std::exception {
  public:

    Exception(size_t numCode, const char* msg);

    const char* what() const noexcept;

  private:

    size_t m_last_err;
    const char* m_msg;
};

#endif
