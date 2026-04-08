#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;
using ll = long long;

struct FenwickTree {
  int n{0};
  vector<ll> a{};

  explicit FenwickTree(int n_) : n(n_), a{vector<ll>(n + 1)} {
    if (n <= 0) {
      cout << "n<=0: " << "n=" << n;
    }
  }

  static int lowbit(int x) { return x & -x; }

  void add(int pos, ll x) {
    if (pos > n) {
      ostringstream output;
      output << "update, pos>n: pos=" << pos << ", n=" << n;
      throw invalid_argument(output.str());
    }
    while (pos <= n) {
      a[pos] += x;
      pos += lowbit(pos);
    }
  }

  ll operator[](int pos) const { return sum(pos); }

  ll sum(int pos) const {
    if (pos > n) {
      ostringstream output;
      output << "sum, pos>n: pos=" << pos << ", n=" << n;
      throw invalid_argument(output.str());
    }

    ll ans{};
    while (pos) {
      ans += a[pos];
      pos -= lowbit(pos);
    }
    return ans;
  }
};

#endif
