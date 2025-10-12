#include <stdio.h>

#define N 300000

int main() {
  static char cc[N + 1];
  static int kk[(N + 1) * 4];
  int n, i, x, k;
  long long ans;

  scanf("%d%s", &n, cc);
  ans = (long long)n * (n + 1) / 2;
  x = n + 1, kk[x]++, k = 1;
  for (i = 0; i < n; i++) {
    if (cc[i] == '1')
      k += kk[x + 2] + kk[x + 3] + kk[x + 4], x += 3;
    else
      k -= kk[x + 1], x--;
    ans -= k - kk[x - 1];
    kk[x]++, k++;
  }
  printf("%lld\n", ans);
  return 0;
}
