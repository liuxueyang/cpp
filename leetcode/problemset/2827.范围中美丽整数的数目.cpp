/*
 * @lc app=leetcode.cn id=2827 lang=cpp
 *
 * [2827] 范围中美丽整数的数目
 *
 * https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range/description/
 *
 * algorithms
 * Hard (37.23%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 10.7K
 * Testcase Example:  '10\n20\n3'
 *
 * 给你正整数 low ，high 和 k 。
 *
 * 如果一个数满足以下两个条件，那么它是 美丽的 ：
 *
 *
 * 偶数数位的数目与奇数数位的数目相同。
 * 这个整数可以被 k 整除。
 *
 *
 * 请你返回范围 [low, high] 中美丽整数的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：low = 10, high = 20, k = 3
 * 输出：2
 * 解释：给定范围中有 2 个美丽数字：[12,18]
 * - 12 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3
 * 整除。
 * - 18 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3
 * 整除。 以下是一些不是美丽整数的例子：
 * - 16 不是美丽整数，因为它不能被 k = 3 整除。
 * - 15 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
 * 给定范围内总共有 2 个美丽整数。
 *
 *
 * 示例 2：
 *
 *
 * 输入：low = 1, high = 10, k = 1
 * 输出：1
 * 解释：给定范围中有 1 个美丽数字：[10]
 * - 10 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 1
 * 整除。 给定范围内总共有 1 个美丽整数。
 *
 *
 * 示例 3：
 *
 *
 * 输入：low = 5, high = 5, k = 2
 * 输出：0
 * 解释：给定范围中有 0 个美丽数字。
 * - 5 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 < low <= high <= 10^9
 * 0 < k <= 20
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
int dp[15][30][30];

class Solution {
 public:
  string s1, s2;
  int len, k;

  int dfs(int pos, int dif, int x, bool bdl, bool bdr, bool num) {
    if (pos == len) return dif == len && x == 0 && num;

    if (!bdl && !bdr && num && dp[pos][dif][x] != -1) return dp[pos][dif][x];

    int low = 0, up = 9, ans{};

    if (!num && s1[pos] == '0') {
      ans += dfs(pos + 1, dif, x, bdl, false, false);
      low = 1;
    }

    if (bdl) ckmax(low, s1[pos] - '0');
    if (bdr) ckmin(up, s2[pos] - '0');

    For1(i, low, up) {
      int x1 = (x * 10 + i) % k, dif1 = dif;
      if (i & 1) {
        dif1++;
      } else {
        dif1--;
      }
      ans += dfs(pos + 1, dif1, x1, bdl && i == s1[pos] - '0',
                 bdr && i == s2[pos] - '0', true);
    }

    if (!bdl && !bdr && num) dp[pos][dif][x] = ans;

    return ans;
  }
  int numberOfBeautifulIntegers(int low, int high, int k_) {
    memset(dp, -1, sizeof dp);
    k = k_;
    s1 = to_string(low);
    s2 = to_string(high);

    len = SZ(s2);
    int len1 = SZ(s1);
    if (len1 < len) {
      s1 = string(len - len1, '0') + s1;
    }

    return dfs(0, len, 0, true, true, false);
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

  return 0;
}
#endif  // End of MYDEBUG

// @lc code=end
