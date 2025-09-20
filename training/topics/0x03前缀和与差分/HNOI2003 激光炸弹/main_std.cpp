// https://blog.nowcoder.net/n/996954257c9840fba1605f267a712e1f

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 5010;  // 这个N表示点最多的数量
int g[N][N];

int main() {
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif

  int N, R;  // 为了方便就重名了，两个N重名是没关系的，因为会优先选择函数里的
  while (cin >> N >> R) {
    memset(g, 0, sizeof g);
    int xx = R, yy = R;  // xx和yy表示边界，初始化为最小的R

    for (int i = 0, x, y, w; i < N; ++i) {
      cin >> x >> y >> w;
      x++;
      y++;  // 坐标x，y都要加1，因为这道题目的坐标是从0开始的
      g[x][y] = w;
      xx = max(xx, x);
      yy = max(yy, y);
    }

    for (int i = 1; i <= xx; i++)
      for (int j = 1; j <= yy; j++)
        g[i][j] =
            g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + g[i][j];  // 求前缀和

    int ans = 0;
    for (int i = R; i <= xx; i++) {
      for (int j = R; j <= yy; j++) {
        ans = max(
            ans,
            g[i][j] - g[i - R][j] - g[i][j - R] +
                g[i - R]
                 [j - R]);  // 用提前算好的前缀和减去其他部分再补上多剪的那部分
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
