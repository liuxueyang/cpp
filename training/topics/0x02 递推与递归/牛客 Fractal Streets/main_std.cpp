#include <math.h>

#include <cstdio>
#include <utility>  //pair
using namespace std;
#define ll long long
#define pr pair<ll, ll>
#define mp make_pair
#include "debug.h"

pr get(int n, ll m) {  // 返回值是第n层第m个的坐标
  if (!n) return mp(0, 0);
  ll len = 1ll << (n - 1), cnt = (1ll << (2 * n)) / 4;
  pr pos = get(n - 1, m % cnt);
  // 我们把它在下一层的坐标求出来，然后根据它在这一层的方位（左上，左下，右上，右下），还原它旋转移动前的坐标
  ll x = pos.first, y = pos.second, z = m / cnt;
  if (z == 0)
    return mp(y, x);
  else if (z == 1)
    return mp(x, y + len);
  else if (z == 2)
    return mp(x + len, y + len);
  else if (z == 3)
    return mp(-y + 2 * len - 1, -x + len - 1);
  // z==1,2都是可以直接平移得到，而z==0,3需要旋转
  // 其实路径的形状并不重要，关键是第n层与第n+1层间的的坐标是怎样变换的。
  // printf("Impossible z = %d\n", z);
  dbg("Impossible", z);
}
int main() {
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif

  int T, n;
  ll a, b, x, y;
  scanf("%d", &T);

  while (T--) {
    scanf("%d%lld%lld", &n, &a, &b);

    pr A = get(n, a - 1), B = get(n, b - 1);

    x = A.first - B.first, y = A.second - B.second;
    printf("%.0lf\n", sqrt(x * x + y * y) * 10);
  }
}
