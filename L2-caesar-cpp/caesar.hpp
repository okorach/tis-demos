#ifndef CAESAR_H
#define CAESAR_H
#include <memory>

class Caesar {
public:
  Caesar(int o) : offset(o) {}

  // Ciphers a buffer with a right shift specified by the user
  char * encrypt(const char * buf, int bufsize) const;
  
  // Deciphers a buffer with a left shift specified by the user
  char * decrypt(const char * buf, int bufsize) const;

private:
  int absolute_int(int x) const;
  int offset;
};
#endif
