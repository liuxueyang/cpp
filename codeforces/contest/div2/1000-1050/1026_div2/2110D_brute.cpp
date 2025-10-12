#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(...) ;
#define local_go_m(x) \
  int c;              \
  cin >> c;           \
  while (c--) x()

template <typename T>
bool cmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}

template <typename T>
bool cmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}

void go() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<array<int, 2>, int> c;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    if (c.contains({x, y}))
      c[{x, y}] = min(c[{x, y}], z);
    else
      c[{x, y}] = z;
  }
  vector<vector<array<int, 2>>> d(n);
  for (auto &[x, y] : c) {
    d[x[0]].push_back({x[1], y});
  }
  vector<i64> ma(n, -1);
  ma[0] = a[0];
  for (int i = 0; i < n; i++) {
    for (auto &t : d[i]) {
      if (t[1] <= ma[i]) {
        cmax(ma[t[0]], ma[i] + a[t[0]]);
      }
    }
  }
  dbg(ma);
  if (ma[n - 1] == -1) {
    cout << -1 << endl;
    return;
  }
  auto check = [&](i64 mid) -> bool {
    vector<i64> f(n, -1);
    f[0] = min(mid, i64(a[0]));
    for (int i = 0; i < n; i++) {
      for (auto &t : d[i]) {
        if (t[1] <= f[i]) {
          cmax(f[t[0]], min(mid, f[i] + a[t[0]]));
        }
      }
    }
    return f[n - 1] != -1;
  };
  i64 l = 0, r = ma[n - 1];
  while (l + 1 < r) {
    i64 mid = l + (r - l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
}

int main() {
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  local_go_m(go);
  return 0;
}