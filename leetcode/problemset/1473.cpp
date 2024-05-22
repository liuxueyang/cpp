// Date: Tue May 21 21:37:20 2024

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

const ull Pr = 131;

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
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
  }
  return out;
}

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define debug1
#define debug2
#define debug3
#define dbg(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#ifdef _DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif
// End of LeetCode

const int N = 110, M = 25;
int n, m, d[N][N][M], a[N], k, c[N][M];
bool vis[N][N][M];
int calc;

class Solution {
public:
  int dfs(int i, int k, int p) {
    if (!i || !k) {
      if (!i && !k)
        return 0;
      else if (!k) {
        int sum{};
        if (a[i]) {
          if (a[i] != p)
            return INF;
        } else {
          sum = c[i][p];
        }
        int tmp = dfs(i - 1, k, p) + sum;
        ckmin(d[i][k][p], tmp);

        return tmp;
      } else
        return INF;
    }

    int &ans = d[i][k][p], tmp;

    if (vis[i][k][p])
      return ans;

    if (a[i]) {
      if (a[i] == p) {
        tmp = dfs(i - 1, k, p);
        ckmin(ans, tmp);

        vis[i][k][p] = true;
        return ans;
      } else {
        int q = a[i];
        tmp = dfs(i - 1, k - 1, q);
        ckmin(ans, tmp);
        vis[i][k][p] = true;
        return ans;
      }
    }

    int sum{};
    For1(q, 1, m) {
      sum = c[i][q];
      if (q == p) {
        tmp = dfs(i - 1, k, p);
      } else {
        tmp = dfs(i - 1, k - 1, q);
      }

      ckmin(ans, tmp + sum);
      calc++;
    }

    vis[i][k][p] = true;
    return ans;
  }

  int minCost(vector<int> &a1, vector<vector<int>> &c1, int _n1, int m1_,
              int k1) {
    n = SZ(a1);
    For(i, 0, n) a[i + 1] = a1[i];
    k = k1;
    m = SZ(c1[0]);

    For(i, 0, n) {
      For(j, 0, m) { c[i + 1][j + 1] = c1[i][j]; }
    }

    memset(d, 0x3f, sizeof d);
    memset(vis, false, sizeof vis);
    int ans = dfs(n, k, 22);

    if (ans >= INF)
      ans = -1;

    return ans;
  }
};

class Solution1 {
private:
  // 极大值
  // 选择 INT_MAX / 2 的原因是防止整数相加溢出
  static constexpr int INFTY = INT_MAX / 2;

public:
  int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n,
              int target) {
    // 将颜色调整为从 0 开始编号，没有被涂色标记为 -1
    for (int &c : houses) {
      --c;
    }

    // dp 所有元素初始化为极大值
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(target, INFTY)));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (houses[i] != -1 && houses[i] != j) {
          continue;
        }

        for (int k = 0; k < target; ++k) {
          for (int j0 = 0; j0 < n; ++j0) {
            if (j == j0) {
              if (i == 0) {
                if (k == 0) {
                  dp[i][j][k] = 0;
                }
              } else {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
              }
            } else if (i > 0 && k > 0) {
              dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
            }
            calc++;
          }

          if (dp[i][j][k] != INFTY && houses[i] == -1) {
            dp[i][j][k] += cost[i][j];
          }
        }
      }
    }

    int ans = INFTY;
    for (int j = 0; j < n; ++j) {
      ans = min(ans, dp[m - 1][j][target - 1]);
    }
    return ans == INFTY ? -1 : ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  VI p;
  vector<VI> q;
  int res;

  // p = VI{0, 0, 0, 0, 0};
  // q = vector<VI>{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
  // n = 5, m = 2, k = 3;
  // res = a.minCost(p, q, n, m, k);
  // dbg(res);

  // p = VI{0, 2, 1, 2, 0};
  // q = vector<VI>{{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
  // n = 5, m = 2, k = 3;
  // res = a.minCost(p, q, n, m, k);
  // dbg(res);

  // calc = 0;
  // n = 100, m = 20, k = 50;
  // p = VI(n, 0);
  // q = vector<VI>(n, VI(m, 1));
  // res = a.minCost(p, q, n, m, k);
  // dbg(res, calc);

  Solution1 a1;
  // calc = 0;
  // n = 100, m = 20, k = 50;
  // p = VI(n, 0);
  // q = vector<VI>(n, VI(m, 1));
  // res = a1.minCost(p, q, n, m, k);
  // dbg(res, calc);

  int n1 = 100;
  m = 20;

  For1(k, 1, n1) {
    calc = 0;
    n = 100, m = 20;
    p = VI(n, 0);
    q = vector<VI>(n, VI(m, 1));
    int res1 = a.minCost(p, q, n, m, k);
    int calc1 = calc;

    calc = 0;
    p = VI(n, 0);
    q = vector<VI>(n, VI(m, 1));
    int res2 = a1.minCost(p, q, n, m, k);
    int calc2 = calc;

    double pr = double(calc1) / calc2;
    assert(res1 == res2);
    dbg(k, res1, res2, calc1, calc2, pr);

    // break;
  }

  return 0;
}

#endif
