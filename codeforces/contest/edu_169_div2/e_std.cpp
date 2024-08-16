#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 3e5 + 10, M = 1e7 + 10;

int n;
int a[N];
int prm[M], st[M], sg[M], idx;

void prework() {
  sg[1] = 1;
  for (int i = 2; i < M; i++) {
    if (!st[i])
      prm[++idx] = i, sg[i] = idx;
    for (int j = 1; prm[j] * i < M; j++) {
      st[prm[j] * i] = 1, sg[prm[j] * i] = min(sg[prm[j] * i], j);
      if (i % prm[j] == 0)
        break;
    }
  }
}

void solve() {
  cin >> n;
  int xr = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i], xr ^= sg[a[i]];

  if (xr == 0)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
}

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int dt;
  memset(sg, 0x3f, sizeof sg);
  prework();
  for (int i = 2; i < M; i += 2)
    sg[i] = 0;
  // for (int i = 1; i <= 300; i ++)
  // 	cout << i << ":" << sg[i] << endl;
  // cout << endl;

  cin >> dt;

  while (dt--)
    solve();

  return 0;
}
