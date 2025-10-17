#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, d[N], f[N][2], ans;
vector<int> G[N];
bool vis[N];

void dfs(int u) {
  vis[u] = true;
  vector<int> tmp;
  for (int v : G[u])
    if (d[v] >= 4 && !vis[v]) {
      dfs(v);
      tmp.push_back(f[v][1]);
    }
  sort(tmp.rbegin(), tmp.rend());  // 从大到小把儿子排序了
  f[u][1] = 1;                     // 选最大的三个儿子
  for (int i = 0; i < tmp.size() && i < 3; i++) {
    f[u][1] += tmp[i];
  }

  // f[u][0] 选最大的四个儿子
  f[u][0] = f[u][1];
  if (tmp.size() >= 4) f[u][0] += tmp[3];
  ans = max(ans, f[u][0]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    d[u]++;
    d[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] >= 4 && !vis[i]) {
      dfs(i);
    }
  }
  if (ans == 0)
    printf("-1\n");
  else
    printf("%d\n", ans * 3 + 2);

  return 0;
}