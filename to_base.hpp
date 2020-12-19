#include <string>

template <int base>
std::string to_base(int n) {
  std::string s;
  while (n) {
    s = std::to_string(n % base) + s;
    n /= base;
  }
  return s;
}
