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
mt19937_64 _m_gen64;

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
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}

template <class T>
ostream& operator<<=(ostream& os, const vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    os << a[i] << " \n"[i == n];
  }
  return os;
}

template <class T>
istream& operator>>=(istream& is, vector<T>& a) {
  int n = int(a.size()) - 1;
  for (int i = 1; i <= n; ++i) {
    is >> a[i];
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  int n = int(a.size());
  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i == n - 1];
  }
  return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  for (auto& x : a) is >> x;
  return is;
}

// For LeetCode
#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*
// End of LeetCode

#ifdef _DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

const int M = 200, N = 20;
int dp[N][M], dp1[N][11][M], dp2[N][11][M];

bool is_inc(string& s) {
  int len = SZ(s);
  if (len == 1) return true;

  For(i, 1, len) {
    if (s[i] > s[i - 1]) continue;
    return false;
  }
  return true;
}

bool is_dec(string& s) {
  int len = SZ(s);
  if (len == 1) return true;

  For(i, 1, len) {
    if (s[i] < s[i - 1]) continue;
    return false;
  }
  return true;
}

bool check(int n) {
  string s = to_string(n);
  return is_inc(s) || is_dec(s);
}

bool is_wonderful(int n) {
  int sum = 0;
  if (check(n)) return true;

  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return check(sum);
}

class Solution {
 public:
  VB vg;
  string s1, s2;
  int len;

  ll dfs(int pos, int cur, bool bdl, bool bdr) {
    if (pos == len) {
      return vg[cur];
    }
    if (!bdl && !bdr && dp[pos][cur] != -1) return dp[pos][cur];

    int low = 0, up = 9, l1 = s1[pos] - '0', r1 = s2[pos] - '0';
    ll ans = 0;
    if (bdl) ckmax(low, l1);
    if (bdr) ckmin(up, r1);
    For1(i, low, up) {
      int cur1 = cur + i;
      ll tmp = dfs(pos + 1, cur1, bdl && i == l1, bdr && i == r1);
      ans = (ans + tmp);
    }
    if (!bdl && !bdr) dp[pos][cur] = ans;
    return ans;
  }

  ll dfs1(int pos, int val, int cur, bool bdl, bool bdr, bool is_num) {
    if (pos == len) {
      return !check(cur) && is_num;
    }
    if (!bdl && !bdr && dp1[pos][val][cur] != -1) return dp1[pos][val][cur];
    int low = 0, up = 9, l1 = s1[pos] - '0', r1 = s2[pos] - '0';
    ll ans = 0;

    if (is_num)
      low = val + 1;
    else {
      ans += dfs1(pos + 1, val, cur, bdl && 0 == l1, bdr && 0 == r1, is_num);
    }

    if (bdl) ckmax(low, l1);
    if (bdr) ckmin(up, r1);
    For1(i, low, up) {
      int cur1 = cur + i;
      ll tmp = dfs1(pos + 1, i, cur1, bdl && i == l1, bdr && i == r1,
                    is_num || i != 0);
      ans = (ans + tmp);
    }
    if (!bdl && !bdr) dp1[pos][val][cur] = ans;
    return ans;
  }
  ll dfs2(int pos, int val, int cur, bool bdl, bool bdr, bool is_num) {
    if (pos == len) {
      return !check(cur) && is_num;
    }
    if (!bdl && !bdr && dp2[pos][val][cur] != -1) return dp2[pos][val][cur];
    int low = 0, up = 9, l1 = s1[pos] - '0', r1 = s2[pos] - '0';
    ll ans = 0;
    if (is_num)
      up = val - 1;
    else {
      ans += dfs2(pos + 1, val, cur, bdl && 0 == l1, bdr && 0 == r1, is_num);
    }

    if (bdl) ckmax(low, l1);
    if (bdr) ckmin(up, r1);
    For1(i, low, up) {
      int cur1 = cur + i;
      ll tmp = dfs2(pos + 1, i, cur1, bdl && i == l1, bdr && i == r1,
                    is_num || i != 0);
      ans = (ans + tmp);
    }
    if (!bdl && !bdr) dp2[pos][val][cur] = ans;
    return ans;
  }

  long long countFancy(long long l, long long r) {
    vg = VB(M + 10);
    For1(i, 1, 9) vg[i] = true;

    For1(i, 10, M) { vg[i] = check(i); }

    s1 = to_string(l);
    s2 = to_string(r);
    len = SZ(s2);
    int len1 = SZ(s1);
    if (len1 < len) {
      s1 = string(len - len1, '0') + s1;
    }
    memset(dp, -1, sizeof dp);
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);
    ll tmp0 = dfs(0, 0, true, true);
    ll tmp1 = dfs1(0, -1, 0, true, true, false);
    ll tmp2 = dfs2(0, 10, 0, true, true, false);
    ll ans = tmp0 + tmp1 + tmp2;
    // dbg(tmp0, tmp1, tmp2);

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  ll l, r;
  cin >> l >> r;
  // l = r = 119;
  auto res = a.countFancy(l, r);
  cout << res << '\n';

  // if (r < 500) {
  //   For1(i, l, r) {
  //     auto output = a.countFancy(i, i);
  //     int exp = Solution::check(i) || Solution::check_sum(i);
  //     if (output != exp) {
  //       dbg(i, output, exp);
  //     }
  //   }
  // }

  return 0;
}

#endif