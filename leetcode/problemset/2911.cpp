// Date: Sat May 25 21:34:53 2024

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

const int N = 210;
int n, d[N][N], p[N][N];
bool vis[N][N];
map<int, VI> divm;
string s;

VI get_divs(int n) {
  if (has(divm, n))
    return divm[n];

  VI ans;
  for (int i = 1; i * i <= n; ++i) {
    int j = n / i;
    if (n % i == 0) {
      ans.pb(i);
      if (i != j && j != n)
        ans.pb(j);
    }
  }
  sort(all(ans));
  divm[n] = ans;
  return ans;
}

int cal(string t) {
  int len = SZ(t), ans = len;
  VI divs = get_divs(len);
  t = " " + t;

  for (auto k : divs) {
    int co = 0;
    For1(i, 1, k) {
      int j = i;
      string t1;
      while (j <= len) {
        t1 += t[j];
        j += k;
      }
      int m = SZ(t1);
      for (int j1 = 0, j2 = m - 1; j1 < j2; j1++, j2--) {
        if (t1[j1] != t1[j2])
          co++;
      }
    }
    ckmin(ans, co);
    if (!ans)
      break;
  }
  return ans;
}

class Solution {
public:
  int dfs(int i, int k) {
    if (!i || !k) {
      if (!i && !k)
        return 0;
      else
        return INF;
    }
    if (vis[i][k])
      return d[i][k];

    int &ans = d[i][k], tmp;
    For(j, k, i) {
      tmp = dfs(j - 1, k - 1) + p[j][i];
      ckmin(ans, tmp);
    }
    vis[i][k] = true;
    return ans;
  }
  int minimumChanges(string s1, int k1) {
    n = SZ(s1);
    s = " " + s1;
    divm.clear();

    memset(vis, false, sizeof vis);
    memset(d, 0x3f, sizeof d);
    memset(p, 0x3f, sizeof p);

    For1(k, 2, n) {
      For1(i, 1, n + 1 - k) {
        int j = i + k - 1;
        p[i][j] = cal(s.substr(i, k));
      }
    }

    int ans = dfs(n, k1);
    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  string s;
  int k, res;

  s = "abcac";
  k = 2;
  res = a.minimumChanges(s, k);
  dbg(res);

  s = "acba";
  k = 2;
  res = a.minimumChanges(s, k);
  dbg(res);

  return 0;
}

#endif