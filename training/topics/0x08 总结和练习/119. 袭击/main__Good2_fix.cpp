#include <bits/stdc++.h>
#define sqr(x) (ll)(x) * (x)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int T, n, t[N];

struct node {
  int x, y;
  bool op;
} a[N];

bool cmp1(node x, node y) {
  // NOTE: y should not be sorted
  // if (x.x == y.x) return x.y < y.y;
  return x.x < y.x;
}

bool cmp2(int x, int y) { return a[x].y < a[y].y; }

ll dist(int x, int y) { return sqr(a[x].x - a[y].x) + sqr(a[x].y - a[y].y); }

ll work(int l, int r) {
  if (l == r) return 9e18;
  int mid = (l + r) >> 1;
  ll d = min(work(l, mid), work(mid + 1, r));
  int cnt = 0, num = 0;
  for (int i = l; i <= r; i++)
    if (sqr(a[i].x - a[mid].x) < d) t[++cnt] = i, num += a[i].op;

  // 只有一种颜色直接返回，注意这里不能写成 return 9e18不然就挂了
  if (!num || num == cnt) return d;

  sort(t + 1, t + cnt + 1, cmp2);
  int tn = 1;
  for (int i = 1; i <= cnt; i++)
    if (a[t[i]].op) {
      tn = i;
      break;
    }

  for (int i = 1; i <= cnt; i++)
    // 找到相异颜色点对，先对答案进行更新
    if (a[t[i]].op ^ a[t[tn]].op) d = min(d, dist(t[i], t[tn]));

  for (int i = 1; i <= cnt; i++)
    // 瓶颈：如果答案一直是9e18，那么这里的复杂度就是n^2，难以接受
    for (int j = i + 1; j <= cnt && sqr(a[t[i]].y - a[t[j]].y) < d; j++)
      if (a[t[i]].op ^ a[t[j]].op) d = min(d, dist(t[i], t[j]));
  return d;
}

int main() {
#if defined(_DEBUG) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y), a[i].op = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d%d", &a[i + n].x, &a[i + n].y), a[i + n].op = 1;

    // NOTE: this is important
    shuffle(a + 1, a + 2 * n + 1, mt19937_64(random_device{}()));

    sort(a + 1, a + 2 * n + 1, cmp1);
    printf("%.3Lf\n", sqrt((long double)work(1, 2 * n)));
  }
  return 0;
}

// 作者：bianshiyang
// 链接：https://www.acwing.com/solution/content/271981/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
