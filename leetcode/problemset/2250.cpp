// Date: Sat Jun  1 13:04:57 2024

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

  BIT(int n_) : n(n_) { c = vector<T>(n + 10, 0); }

  int lowbit(int x) { return x & -x; }

  void update(int i, T d) {
    assert(i != 0);
    for (; i <= n; i += lowbit(i)) {
      c[i] += d;
    }
  }

  T query(int i) {
    T ans{};
    assert(i <= n);
    for (; i; i -= lowbit(i)) {
      ans += c[i];
    }
    return ans;
  }

  int search(T s) {
    // find the largest pos which presum(a[pos]) >= s
    int pos{};

    // 2^18 >= n(2e5)
    for (int j = 18; j >= 0; --j) {
      int pos1 = pos + (1 << j);
      if (pos1 <= n && c[pos1] <= s) {
        s -= c[pos1];
        pos = pos1;
      }
    }
    return pos;
  }
};

class Solution {
public:
  vector<int> countRectangles(vector<vector<int>> &a, vector<vector<int>> &b) {
    int m = SZ(b), n = SZ(a);
    VI ans(m, 0), d(110, 0);
    vector<PII> a1(n), b1(m);
    BIT<int> tr(110);

    For(i, 0, n) { a1[i] = PII(a[i][0], a[i][1]); }
    sort(all(a1), greater<PII>());

    For(i, 0, m) { b1[i] = PII(b[i][0], b[i][1]); }
    sort(all(b1), greater<PII>());

    map<PII, int> vis;

    int j = 0;
    For(i, 0, m) {
      while (j < n && a1[j].f1 >= b1[i].f1) {
        tr.update(a1[j].f2, 1);
        ++j;
      }

      int cur = tr.query(b1[i].f2 - 1);

      vis[b1[i]] = j - cur;
    }

    For(i, 0, m) {
      PII t = PII(b[i][0], b[i][1]);
      ans[i] = vis[t];
    }

    return ans;
  }
  vector<int> countRectangles_v1(vector<vector<int>> &a,
                                 vector<vector<int>> &b) {
    int m = SZ(b), n = SZ(a);
    VI ans(m, 0), d(110, 0);
    vector<PII> a1(n), b1(m);

    For(i, 0, n) { a1[i] = PII(a[i][0], a[i][1]); }
    sort(all(a1), greater<PII>());

    For(i, 0, m) { b1[i] = PII(b[i][0], b[i][1]); }
    sort(all(b1), greater<PII>());

    map<PII, int> vis;

    int j = 0;
    For(i, 0, m) {
      while (j < n && a1[j].f1 >= b1[i].f1) {
        d[a1[j].f2]++;
        ++j;
      }

      int cur = 0;
      For1(k, b1[i].f2, 100) { cur += d[k]; }
      vis[b1[i]] = cur;
    }

    For(i, 0, m) {
      PII t = PII(b[i][0], b[i][1]);
      ans[i] = vis[t];
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
  vector<VI> rec, po;
  VI res;

  rec = vector<VI>{{1, 2}, {2, 3}, {2, 5}};
  po = vector<VI>{{2, 1}, {1, 4}};
  res = a.countRectangles(rec, po);
  dbg(res);

  return 0;
}

#endif
