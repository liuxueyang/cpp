#ifndef DSU_H
#define DSU_H

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

struct Dsu {
  int n{0};
  vector<int> fa{}, sz{};

  explicit Dsu(int n_) : n(n_), fa{vector<int>(n + 1)}, sz{fa} {
    if (n <= 0) {
      ostringstream output;
      output << "n<=0: " << "n=" << n;
      throw invalid_argument(output.str());
    }

    for (int i = 1; i <= n; i++) {
      fa[i] = i;
      sz[i] = 1;
    }
  }

  int Find(int u) {
    assert(u >= 1 && u <= n);
    return u == fa[u] ? u : (fa[u] = Find(fa[u]));
  }

  void Union(int u, int v) {
    assert(u >= 1 && u <= n && v >= 1 && v <= n);
    int ru = Find(u), rv = Find(v);
    if (ru == rv)
      return;
    if (sz[ru] < sz[rv])
      swap(ru, rv);
    fa[rv] = ru;
    sz[ru] += sz[rv];
  }
};

#endif
