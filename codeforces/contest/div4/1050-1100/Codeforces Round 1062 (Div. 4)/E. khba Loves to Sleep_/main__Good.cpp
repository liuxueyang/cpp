#include <bits/stdc++.h>
using namespace std;
#include "debug.h"

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &i : a)
      cin >> i;
    sort(a.begin(), a.end());
    int l = 0, r = x + 1;

    auto check = [&](int m) -> int {
      int f = 0;

      for (int i = 1; i < n; ++i)
        if (a[i] - a[i - 1] >= m * 2)
          f += a[i] - a[i - 1] - m * 2 + 1;
      if (a[0] >= m)
        f += a[0] - m + 1;
      if (a.back() + m <= x)
        f += x - a.back() - m + 1;

      return f;
    };

    while (l + 1 < r) {
      int m = (l + r) >> 1, f = check(m);

      if (f >= k)
        l = m;
      else
        r = m;
    }

    vector<int> z;
    int e = 0;
    for (int i = 0; i < n; ++i) {
      while (z.size() < k && e + l <= a[i])
        z.emplace_back(e++);
      e = max(e, a[i] + l);
    }
    while (z.size() < k && e <= x)
      z.emplace_back(e++);
    for (int i : z)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
