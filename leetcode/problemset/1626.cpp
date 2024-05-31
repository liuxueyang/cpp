// Date: Thu May 30 21:40:31 2024

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

class Solution {
public:
  int bestTeamScore(vector<int> &s, vector<int> &a) {
    vector<PII> b;
    int n = SZ(a);

    For(i, 0, n) { b.pb({s[i], a[i]}); }
    sort(all(b));

    VI d(n, 0);

    For(i, 0, n) { d[i] = b[i].f1; }

    For(i, 1, n) {
      For(j, 0, i) {
        if (b[i].f2 >= b[j].f2) {
          ckmax(d[i], d[j] + b[i].f1);
        }
      }
    }

    int ans = *max_element(all(d));

    return ans;
  }
  int bestTeamScore_v2(vector<int> &s, vector<int> &a) {
    vector<PII> b;
    int n = SZ(a), mx = 0;

    For(i, 0, n) {
      b.pb({s[i], a[i]});
      ckmax(mx, a[i]);
    }
    sort(all(b));

    VI d(mx + 1, 0);

    For(i, 0, n) {
      int cur = b[i].f2, tmp = 0;
      For1(j, 0, b[i].f2) { ckmax(tmp, d[j] + b[i].f1); }
      ckmax(d[cur], tmp);
    }

    int ans = *max_element(all(d));

    return ans;
  }

  int bestTeamScore_v1(vector<int> &s, vector<int> &a) {
    vector<PII> b;
    int n = SZ(a);

    For(i, 0, n) { b.pb({a[i], s[i]}); }
    sort(all(b));

    VI d(n, 0);

    For(i, 0, n) { d[i] = b[i].f2; }

    For(i, 1, n) {
      For(j, 0, i) {
        if (b[i].f2 >= b[j].f2) {
          ckmax(d[i], d[j] + b[i].f2);
        }
      }
    }

    int ans = 0;
    For(i, 0, n) { ckmax(ans, d[i]); }

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  VI sc, ag;
  int res;

  sc = VI{1, 3, 5, 10, 15}, ag = VI{1, 2, 3, 4, 5};
  res = a.bestTeamScore(sc, ag);
  dbg(res);

  sc = VI{4, 5, 6, 5}, ag = VI{2, 1, 2, 1};
  res = a.bestTeamScore(sc, ag);
  dbg(res);

  sc = VI{1, 2, 3, 5}, ag = VI{8, 9, 10, 1};
  res = a.bestTeamScore(sc, ag);
  dbg(res);

  return 0;
}

#endif
