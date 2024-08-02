#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s = std::max(s, a[i]);
  }
  std::vector<int> f(s + 1, 2 * s + 1);
  for (int i = 0; i < n; i++) {
    int b;
    std::cin >> b;
    f[a[i]] = std::min(f[a[i]], a[i] - b);
  }
  for (int i = 1; i <= s; i++) {
    f[i] = std::min(f[i], f[i - 1]);
  }
  std::vector<int> dp(s + 1);
  for (int i = 1; i <= s; i++) {
    if (f[i] <= i) {
      dp[i] = dp[i - f[i]] + 1;
    }
  }

  i64 ans = 0;
  while (m--) {
    int c;
    std::cin >> c;
    if (c > s) {
      int t = (c - s + f[s] - 1) / f[s];
      c -= t * f[s];
      ans += t;
    }
    ans += dp[c];
  }
  std::cout << 2 * ans << "\n";

  return 0;
}
