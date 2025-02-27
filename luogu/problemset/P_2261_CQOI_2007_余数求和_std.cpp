#include <algorithm>
#include <cstdio>

#include "debug.h"
using namespace std;
typedef long long ll;

int main() {
#ifdef _DEBUG
#ifndef _CPH
  freopen("input.txt", "r", stdin);
#endif
#endif

  ll n, k;
  while (~scanf("%lld%lld", &n, &k) && n && k) {
    ll ans = n * k;

    for (ll l = 1, r; l <= n; l = r + 1) {
      if (k / l != 0)
        r = min(k / (k / l), n);
      else
        r = n;
      ans -= (k / l) * (r - l + 1) * (l + r) / 2;
    }
    printf("%lld\n", ans);
  }

  return 0;
}