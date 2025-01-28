#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 5;
vector<int> e[N];
int w[N], dfn[N], nfd[N], pre[N], suf[N], low[N];
bool ed[N];
int id;
void dfs(int u) {
  if (ed[u]) return;
  ed[u] = 1;
  dfn[u] = ++id;
  nfd[id] = u;
  for (int v : e[u]) dfs(v);
  ed[u] = 0;
  low[u] = id;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int T;
  cin >> T;
  while (T--) {
    int n, m, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
      e[i].clear();
      id = 0;
    }
    for (i = 1; i <= n; i++) cin >> w[i];
    for (i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    dfs(1);
    for (i = 1; i <= n; i++) pre[i] = max(pre[i - 1], w[nfd[i]]);
    suf[n + 1] = 0;
    for (i = n; i; i--) suf[i] = max(suf[i + 1], w[nfd[i]]);
    int mx = 0;
    for (i = 1; i <= n; i++)
      if (max(pre[dfn[i] - 1], suf[low[i] + 1]) > w[i] && w[i] > w[mx]) mx = i;
    cout << mx << '\n';
  }
}