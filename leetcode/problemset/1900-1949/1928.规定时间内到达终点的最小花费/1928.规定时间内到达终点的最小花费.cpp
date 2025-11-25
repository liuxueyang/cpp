/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 *
 * [1928] 规定时间内到达终点的最小花费
 *
 * https://leetcode.cn/problems/minimum-cost-to-reach-destination-in-time/description/
 *
 * algorithms
 * Hard (54.72%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    16.2K
 * Total Submissions: 29.6K
 * Testcase Example:
 * '30\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]'
 *
 * 一个国家有 n 个城市，城市编号为 0 到 n - 1 ，题目保证 所有城市 都由双向道路
 * 连接在一起 。道路由二维整数数组 edges 表示，其中 edges[i] = [xi, yi,
 * timei] 表示城市 xi 和 yi 之间有一条双向道路，耗费时间为 timei
 * 分钟。两个城市之间可能会有多条耗费时间不同的道路，但是不会有道路两头连接着同一座城市。
 *
 * 每次经过一个城市时，你需要付通行费。通行费用一个长度为 n 且下标从
 * 0 开始的整数数组 passingFees 表示，其中 passingFees[j] 是你经过城市
 * j 需要支付的费用。
 *
 * 一开始，你在城市 0 ，你想要在 maxTime 分钟以内 （包含
 * maxTime 分钟）到达城市 n - 1 。旅行的 费用 为你经过的所有城市
 * 通行费之和 （包括 起点和终点城市的通行费）。
 *
 * 给你 maxTime，edges 和 passingFees ，请你返回完成旅行的 最小费用 ，如果无法在 maxTime 分钟以内完成旅行，请你返回
 * -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：maxTime = 30, edges =
 * [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees =
 * [5,1,2,20,20,3]
 * 输出：11
 * 解释：最优路径为 0 -> 1 -> 2 -> 5 ，总共需要耗费 30 分钟，需要支付 11
 * 的通行费。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：maxTime = 29, edges =
 * [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees =
 * [5,1,2,20,20,3]
 * 输出：48
 * 解释：最优路径为 0 -> 3 -> 4 -> 5 ，总共需要耗费 26 分钟，需要支付 48
 * 的通行费。 你不能选择路径 0 -> 1 -> 2 -> 5 ，因为这条路径耗费的时间太长。
 *
 *
 * 示例 3：
 *
 *
 * 输入：maxTime = 25, edges =
 * [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees =
 * [5,1,2,20,20,3]
 * 输出：-1
 * 解释：无法在 25 分钟以内从城市 0 到达城市 5 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * n == passingFees.length
 * 2
 * n - 1
 * 0 i, yi
 * 1 i
 * 1  
 * 图中两个节点之间可能有多条路径。
 * 图中不含有自环。
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

const ull Pr = 131, Pr1 = 13331;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nemp(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define all1(a, len) (a + 1), (a + 1 + len)
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream &operator<<=(ostream &os, const vector<T> &a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream &operator>>=(istream &is, vector<T> &a) {
  for (auto &x : a) is >> x;
  return is;
}

#define MYLEETCODE
// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *
// End of LeetCode

#ifdef MYDEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

// LeetCode Solution

class Solution {
 public:
  int minCost(int maxTime, vector<vector<int>> &edges,
              vector<int> &passingFees) {
    int n = SZ(passingFees);
    vector<vector<int>> d(n, vector<int>(maxTime + 1, INF));
    d[0][0] = passingFees[0];
    vector<vector<PII>> g(n);
    for (auto &adj : edges) {
      int u = adj[0], v = adj[1], w = adj[2];
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }

    using TI3 = tuple<int, int, int>;
    priority_queue<TI3, vector<TI3>, greater<TI3>> q;
    q.push({passingFees[0], 0, 0});
    while (!q.empty()) {
      auto [fee, u, t] = q.top();
      q.pop();
      if (fee > d[u][t]) continue;
      for (auto [v, wt] : g[u]) {
        int tmp = fee + passingFees[v];
        if (t + wt > maxTime) continue;
        int newt = t + wt;
        if (ckmin(d[v][newt], tmp)) {
          q.push({tmp, v, newt});
        }
      }
    }
    int ans = INF;
    For1(i, 0, maxTime) { ckmin(ans, d[n - 1][i]); }
    return ans == INF ? -1 : ans;
  }
};

#ifdef MYDEBUG
int main(void) {
#if defined(MY_INPUT)
  freopen("input.txt", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  int mx, n1, m1;
  cin >> mx >> n1 >> m1;
  VVI g(n1, VI(m1));
  For(i, 0, n1) cin >>= g[i];
  cin >> n1;
  VI p(n1);
  cin >>= p;
  auto res = a.minCost(mx, g, p);
  cout << res << '\n';

  return 0;
}
#endif  // End of MYDEBUG

// @lc code=end
