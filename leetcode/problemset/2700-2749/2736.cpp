// Date: Thu Jun  6 21:31:21 2024

#include <cassert>
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

template <class T> struct BIT {
  int n;
  vector<T> c;

  BIT(int n_) : n(n_) { c = vector(n + 10, -1); }
  int lowbit(int x) { return x & -x; }
  void update(int i, T d) {
    for (; i <= n; i += lowbit(i))
      ckmax(c[i], d);
  }
  T query(int i) {
    T ans{-INF};
    for (; i; i -= lowbit(i))
      ckmax(ans, c[i]);
    return ans;
  }
};

template <class T> struct Discretize {
  int n;
  vector<T> c;

  Discretize(vector<T> &c_) {
    c = c_;
    sort(all(c));
    c.resize(distance(c.begin(), unique(all(c))));
    n = SZ(c);
  }
  int get(T x) { return 1 + distance(c.begin(), lower_bound(all(c), x)); }
  int size() { return n; }
  T origin(int i) {
    assert(i >= 1 && i <= n);
    return c[i - 1];
  }
};

class Solution {
public:
  vector<int> maximumSumQueries(vector<int> &a, vector<int> &b,
                                vector<vector<int>> &qu) {
    using TII = tuple<int, int, int>;

    int m = SZ(qu), n = SZ(a);
    VI ans(m, -1);
    vector<PII> d(n);
    vector<TII> q(m);

    For(i, 0, m) {
      VI &v = qu[i];
      q[i] = {v[0], -v[1], i};
    }

    sort(all(q), [](const TII &x, const TII &y) {
      if (get<0>(x) != get<0>(y))
        return get<0>(x) > get<0>(y);
      else
        return get<1>(x) < get<1>(y);
    });

    For(i, 0, n) { d[i] = PII(a[i], -b[i]); }
    sort(all(d), [](const PII &x, const PII &y) {
      if (x.f1 != y.f1)
        return x.f1 > y.f1;
      else
        return x.f2 < y.f2;
    });

    VI pos;
    For(i, 0, m) pos.pb(get<1>(q[i]));
    For(i, 0, n) pos.pb(d[i].f2);

    Discretize<int> dis(pos);
    BIT<int> tr(SZ(dis));
    int j = 0;

    For(i, 0, m) {
      int x, y, p;
      tie(x, y, p) = q[i];

      while (j < n && x <= d[j].f1) {
        int a0 = d[j].f1, b0 = d[j].f2, b1 = dis.get(b0);
        tr.update(b1, a0 - b0);
        ++j;
      }

      int y1 = dis.get(y);
      int tmp = tr.query(y1);
      ckmax(ans[p], tmp);
    }

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  VI p1, p2, res;
  vector<VI> q;

  p1 = {4, 3, 1, 2}, p2 = {2, 4, 9, 5};
  q = vector<VI>{{4, 1}, {1, 3}, {2, 5}};
  res = a.maximumSumQueries(p1, p2, q);
  dbg(res);

  p1 = {3, 2, 5}, p2 = {2, 3, 4};
  q = vector<VI>{{4, 4}, {3, 2}, {1, 1}};
  res = a.maximumSumQueries(p1, p2, q);
  dbg(res);

  p1 = {2, 1}, p2 = {2, 3};
  q = vector<VI>{{3, 3}};
  res = a.maximumSumQueries(p1, p2, q);
  dbg(res);

  p1 = {17}, p2 = {42};
  q = vector<VI>{{9, 60}, {94, 22}};
  res = a.maximumSumQueries(p1, p2, q);
  dbg(res);

  return 0;
}

#endif
