#include <bits/stdc++.h>

const int MAXN = 4e6 + 5;
const int mod = 998244353;

int qpow(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    n >>= 1;
  }
  return ans;
}

int fac[MAXN], inv[MAXN];

void init() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[MAXN - 1] = qpow(fac[MAXN - 1], mod - 2);
  for (int i = MAXN - 2; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int binom(int n, int m) {  // C(n, m)
  if (n < 0 || m < 0 || n < m) return 0;
  if (n == m) return 1;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
  init();
  int A, B, C, D;
  scanf("%d%d%d%d", &A, &B, &C, &D);
  int N = A + B + C + D;
  int ans = 0;
  for (int t = 0; t <= B; ++t) {
    (ans += 1ll * binom(A - 1 + t, A - 1) * binom(N - A - t, C) % mod) %= mod;
  }
  printf("%d\n", ans);
  return 0;
}