class DisjointSet {
 private:
  std::vector<int> r;

 public:
  DisjointSet(int n) : r(n, -1) {}

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x != y) {
      if (x > y) {
        std::swap(x, y);
      }
      r[x] += r[y];
      r[y] = x;
    }

    return x != y;
  }

  bool same(int x, int y) { return root(x) == root(y); }

  int size(int x) { return -r[x]; }

 private:
  int root(int x) { return r[x] < 0 ? x : r[x] = root(r[x]); }
};
