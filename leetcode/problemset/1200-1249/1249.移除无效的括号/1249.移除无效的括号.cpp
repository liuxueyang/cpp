/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 *
 * https://leetcode.cn/problems/minimum-remove-to-make-valid-parentheses/description/
 *
 * algorithms
 * Medium (61.20%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 92.1K
 * Testcase Example:  '"lee(t(c)o)de)"'
 *
 * 给你一个由 '('、')' 和小写字母组成的字符串 s。
 *
 * 你需要从字符串中删除最少数目的 '(' 或者
 * ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。
 *
 * 请返回任意一个合法字符串。
 *
 * 有效「括号字符串」应当符合以下 任意一条 要求：
 *
 *
 * 空字符串或只包含小写字母的字符串
 * 可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
 * 可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "lee(t(c)o)de)"
 * 输出："lee(t(c)o)de"
 * 解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a)b(c)d"
 * 输出："ab(c)d"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "))(("
 * 输出：""
 * 解释：空字符串也是有效的
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 可能是 '('、')' 或英文小写字母
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

#ifdef MYDEBUG
#include "debug.h"
#else
#define dbg(x...)
#define dbgi(x)
#define dbgln()
#define dbgr(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *
#define MYLEETCODE
// End of LeetCode

// LeetCode Solution

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    int n = int(s.size());
    vector<int> to_del(n);
    string ans;
    stack<int> stk;

    for (int i = 0; i < n; i++) {
      if (s[i] != '(' && s[i] != ')') continue;
      if (s[i] == '(')
        stk.push(i);
      else {
        if (stk.empty())
          to_del[i] = true;
        else
          stk.pop();
      }
    }
    while (!stk.empty()) {
      int i = stk.top();
      stk.pop();
      to_del[i] = true;
    }
    for (int i = 0; i < n; i++) {
      if (!to_del[i]) ans += s[i];
    }

    return ans;
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
  string s;
  cin >> s;
  auto res = a.minRemoveToMakeValid(s);
  cout << res << '\n';

  return 0;
}
#endif  // End of MYDEBUG

// @lc code=end
