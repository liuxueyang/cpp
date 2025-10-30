#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int query(int a, int b) {
  std::cout << "? " << a << " " << b << std::endl;
  int res;
  std::cin >> res;
  return res;
}

void solve() {
  int lo = 1, hi = 999;
  while (hi - lo > 1) {
    int x = lo + (hi - lo) / 3;
    int y = lo + (hi - lo) * 2 / 3;
    int res = query(x, y);
    if (res == x * y) {
      lo = y;
    } else if (res == x * (y + 1)) {
      lo = x;
      hi = y;
    } else {
      assert(res == (x + 1) * (y + 1));
      hi = x;
    }
  }
  std::cout << "! " << hi << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
