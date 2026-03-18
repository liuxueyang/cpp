#include <cstdio>
#include <iostream>
#define inf 1145141919
using namespace std;
using ll = long long;
int n, ans;
ll a[2000005];
void solve() {
  scanf("%d", &n);
  memset(a, 0, sizeof a);
  ans = 0;
  for (int i = 1; i <= n; i += 1) {
    scanf("%lld", &a[i]);
  }
  ll l, r;
  a[0] = -inf;
  a[n + 1] = a[n] + inf;
  for (int i = 1, j = i; i <= n; i = ++j) {
    r = min(a[i + 1] - a[i], a[i] - a[i - 1] - l);
    l = 0;
    while (j < n && a[j + 2] - a[j + 1] + r > a[j + 1] - a[j]) {
      ll l0 = l, r0 = r;
      j += 1;
      l = a[j] - a[j - 1] - r0;
      r = min(a[j + 1] - a[j], a[j] - a[j - 1] - l0);
    }
    ans += j - i;
  }
  printf("%d\n", ans);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
