/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 *
 * https://leetcode.cn/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (40.69%)
 * Likes:    718
 * Dislikes: 0
 * Total Accepted:    89.9K
 * Total Submissions: 221K
 * Testcase Example:
 * '4\n[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]\n0\n3\n1'
 *
 * 有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi,
 * toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
 *
 * 现在给定所有的城市和航班，以及出发城市 src 和目的地
 * dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的
 * 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入:
 * n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src =
 * 0, dst = 3, k = 1
 * 输出: 700
 * 解释: 城市航班图如上
 * 从城市 0 到城市 3 经过最多 1 站的最佳路径用红色标记，费用为 100 + 600 = 700。
 * 请注意，通过城市 [0, 1, 2, 3] 的路径更便宜，但无效，因为它经过了 2 站。
 *
 *
 * 示例 2：
 *
 *
 * 输入:
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
 * 输出: 200
 * 解释:
 * 城市航班图如上
 * 从城市 0 到城市 2 经过最多 1 站的最佳路径标记为红色，费用为 100 + 100 = 200。
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k =
 * 0 输出：500 解释： 城市航班图如上 从城市 0 到城市 2
 * 不经过站点的最佳路径标记为红色，费用为 500。
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 100
 * 0 <= flights.length <= (n * (n - 1) / 2)
 * flights[i].length == 3
 * 0 <= fromi, toi < n
 * fromi != toi
 * 1 <= pricei <= 10^4
 * 航班没有重复，且不存在自环
 * 0 <= src, dst, k < n
 * src != dst
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
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<PII>> g(n);
    for (auto &f : flights) {
      g[f[0]].push_back({f[1], f[2]});
    }

    k++;
    VVI d(k + 1, VI(n, INF));
    struct Node {
      int val, u, cnt;
      bool operator>(const Node &rh) const { return val > rh.val; }
    };

    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({0, src, 0});
    VVB vis(k + 1, VB(n));

    while (!q.empty()) {
      auto [val, u, cnt] = q.top();
      q.pop();
      if (vis[cnt][u]) continue;
      vis[cnt][u] = true;

      for (auto [v, w] : g[u]) {
        if (cnt + 1 <= k && ckmin(d[cnt + 1][v], val + w)) {
          q.push({d[cnt + 1][v], v, cnt + 1});
        }
      }
    }

    int ans = INF;
    For1(i, 0, k) { ckmin(ans, d[i][dst]); }
    return ans >= INF ? -1 : ans;
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
  int n, src, dst, k, m, m1;
  cin >> n;
  cin >> m >> m1;
  VVI fli(m, VI(3));
  For(i, 0, m) cin >>= fli[i];
  cin >> src >> dst >> k;
  auto res = a.findCheapestPrice(n, fli, src, dst, k);
  cout << res << '\n';

  return 0;
}
#endif  // End of MYDEBUG

// @lc code=end
