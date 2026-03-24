#include <iostream>
#include <random>

using namespace std;
using ll = long long;

using UID = uniform_int_distribution<int>;
using ULD = uniform_int_distribution<long long>;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)

mt19937 e(random_device{}());

int randint(int l, int r) {
  UID u(l, r);
  return u(e);
}

pair<int, int> randpair(int l, int r) {
  UID u(l, r);
  int x = u(e), y = u(e);
  if (x > y)
    swap(x, y);
  else if (x == y) {
    if (l == r)
      return {l, l};
    else if (y == r)
      return {r - 1, r};
    else
      return {x, x + 1};
  }
  return {x, y};
}

int main() { return 0; }
