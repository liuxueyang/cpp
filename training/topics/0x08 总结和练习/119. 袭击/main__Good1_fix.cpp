#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <random>

#ifdef DEBUG
#include "debug.h"
#endif

using namespace std;

const int N = 200015;
struct node {
  double x, y;
  bool flag = false;
} arr[N], brr[N];
node temp[N];

ostream &operator<<(ostream &os, node &v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}

int n, m;

bool cmp(node x, node y) {
  // if (x.x == y.x)
  //   return x.y < y.y;
  // else
  return x.x < y.x;
}

const int INF = 1e9;
double ans = (double)INF;

double dist(node x, node y) {
  if (x.flag == y.flag)
    return INF;
  else if (x.x == y.x && x.y == y.y && x.flag != y.flag)
    return x.flag < y.flag;
  else
    return (
        std::sqrt(((x.y - y.y) * (x.y - y.y)) + ((x.x - y.x) * (x.x - y.x))));
}

double dfs(int l, int r) {
  if (l >= r) return INF;

  int mid = (l + r) >> 1;
  // 找到中间点
  double midx = arr[mid].x;
  // 分治
  ans = std::min(dfs(l, mid), dfs(mid + 1, r));

  // 分治最优排序方式（归并排序）
  {
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
      if (j > r || (i <= mid && arr[i].y <= arr[j].y))
        temp[k] = arr[i++];
      else
        temp[k] = arr[j++];
    }
    for (int k = l; k <= r; k++) arr[k] = temp[k];
  }

  // 找[l, mid] 与 [mid + 1, r] 之间点的最短距离
  // 每边至多只有6个点 两边加起来12个点
  int k = 0;
  for (int i = mid; i >= l; i--) {
    if (arr[i].x >= midx - ans && arr[i].x <= midx + ans) {
      // if (k == 6) break;
      temp[++k] = arr[i];
    }
  }

  for (int i = 1, j = k; i < j && k; i++, j--) swap(temp[i], temp[j]);

  for (int i = mid + 1; i <= r; i++) {
    if (arr[i].x >= midx - ans && arr[i].x <= midx + ans) {
      // if (k == 12) break;
      temp[++k] = arr[i];
    }
  }

  // 直接计算两点距离即可
  for (int i = 1; i <= k; i++) {
    for (int j = i - 1; j > 0 && temp[i].y - temp[j].y < ans; j--) {
      ans = std::min(ans, dist(temp[i], temp[j]));
    }
  }

  return ans;
}

int main() {
#if defined(_DEBUG) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    ans = (double)INF;
    n = 1;
    scanf("%d", &m);
    // 不同的点打上不同的标记
    for (int i = 1; i <= m; i++) {
      scanf("%lf %lf", &brr[i].x, &brr[i].y);
      brr[i].flag = false;
    }

    for (int i = m + 1; i <= m * 2; i++) {
      scanf("%lf %lf", &brr[i].x, &brr[i].y);
      brr[i].flag = true;
    }

    shuffle(brr + 1, brr + 1 + 2 * m, mt19937_64(random_device{}()));
    std::sort(brr + 1, brr + 1 + 2 * m, cmp);

    bool flag = false;
    arr[1] = brr[1];
    // 相同的点且坐标相同的点不需要加入计算的数组中
    // 不同的点且坐标相同的点直接输出结果 没有比这个更小的距离了
    // 其余的点直接加入计算的数组中即可，并且在这一步就直接计算距离
    for (int i = 2; i <= m * 2; i++) {
      if (brr[i].x == brr[i - 1].x && brr[i].y == brr[i - 1].y &&
          brr[i].flag == brr[i - 1].flag)
        continue;
      else if (brr[i].x == brr[i - 1].x && brr[i].y == brr[i - 1].y &&
               brr[i].flag != brr[i - 1].flag) {
        flag = true;
        puts("0.000");
        break;
      } else {
        arr[++n] = brr[i];
        ans = std::min(ans, dist(arr[n], arr[n - 1]));
      }
    }

    if (flag)
      continue;
    else {
      printf("%.3lf\n", dfs(1, n));
    }
  }
  return 0;
}
