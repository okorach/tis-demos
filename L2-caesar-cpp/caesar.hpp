#ifndef CAESAR_H
#define CAESAR_H
#include <memory>

template <class T>
class Caesar {
public:
  Caesar(int o) : offset(o) {}

  // Ciphers a buffer with a right shift specified by the user
  std::shared_ptr<T> encrypt(const T * buf, int bufsize) const;
  
  // Deciphers a buffer with a left shift specified by the user
  std::shared_ptr<T> decrypt(const T * buf, int bufsize) const;

private:
  int absolute_int(int x) const;
  int offset;
};
#endif
