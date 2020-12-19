
template <typename T>
class BIT {
 public:
  BIT(int n) : _array(n + 1, 0), _n(n) {}

  // O(log(n))
  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += array[i];
      i -= i & -i;
    }
    return s;
  }

  // O(log(n))
  void add(int i, T x) {
    while (i < n) {
      array[i] += x;
      i += i & -i;
    }
  }

 private:
  std::vector<T> _array;
  const int _n;
};
