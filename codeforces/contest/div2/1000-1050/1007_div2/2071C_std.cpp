// https://codeforces.com/contest/2071/submission/308365332
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
  int n, st, en;
  std::cin >> n >> st >> en;
  st--;
  en--;

  std::vector<std::vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> q;
  q.push_back(en);
  std::vector<bool> vis(n);
  vis[en] = true;

  for (int i = 0; i < n; i++) {
    int x = q[i];
    for (auto y : adj[x]) {
      if (!vis[y]) {
        vis[y] = true;
        q.push_back(y);
      }
    }
  }
  std::reverse(q.begin(), q.end());
  for (auto x : q) {
    std::cout << x + 1 << " \n"[x == q.back()];
  }
}

int main() {
#ifdef _DEBUG
#ifndef _CPH
  freopen("input.txt", "r", stdin);
#endif
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}