#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, D = 1e6 + 5;
int n, d, f[N][2];
vector<int> A[D];
int main() {
#ifdef _DEBUG
#ifndef _CPH
  freopen("input.txt", "r", stdin);
#endif
#endif

  while (~scanf("%d %d", &n, &d)) {
    memset(f, 0, sizeof f);
    for (int i = 0; i < D; i++) A[i] = {};

    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      if (d)
        A[a % d].push_back(a / d);
      else
        A[a].push_back(a);
    }
    // 要求所有 A[i] 当中不存在相邻的两个数
    int ans = 0;
    for (int i = 0; i < D; i++)
      if (A[i].size() > 1) {
        if (d == 0) {
          // A[i] = i, i, i, i, i
          ans += A[i].size() - 1;
          continue;
        }
        sort(A[i].begin(), A[i].end());  // 从小到大
        f[0][0] = 1;
        f[0][1] = 0;
        for (unsigned j = 1; j < A[i].size(); j++) {
          if (A[i][j] == A[i][j - 1]) {
            f[j][0] = f[j - 1][0] + 1;
            f[j][1] = f[j - 1][1];
          } else if (A[i][j] == A[i][j - 1] + 1) {
            f[j][0] = min(f[j - 1][0], f[j - 1][1]) + 1;
            f[j][1] = f[j - 1][0];
          } else {
            f[j][0] = min(f[j - 1][0], f[j - 1][1]) + 1;
            f[j][1] = min(f[j - 1][0], f[j - 1][1]);
          }
        }
        // 0, 1, .., A[i].size() - 1
        ans += min(f[A[i].size() - 1][0], f[A[i].size() - 1][1]);
      }
    printf("%d\n", ans);
  }

  return 0;
}
