// Date: Thu Jul 18 22:20:58 2024

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

// int128 input and output
#ifdef _DEBUG
using lll = __int128;

istream &operator>>(istream &is, lll &v) {
  string s;
  is >> s;
  v = 0;
  for (auto &it : s)
    if (isdigit(it))
      v = v * 10 + it - '0';
  if (s[0] == '-')
    v *= -1;
  return is;
}

ostream &operator<<(ostream &os, const lll &v) {
  if (v == 0)
    return (os << "0");
  lll num = v;
  if (v < 0)
    os << '-', num = -num;
  string s;
  for (; num > 0; num /= 10)
    s.pb((char)(num % 10) + '0');
  reverse(all(s));
  return (os << s);
}
#endif
// end of int128

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

const int N = 15;
int a[N][N], n, m;

void solve() {
  cin >> n >> m;

  For1(i, 1, n) {
    For1(j, 1, m) { cin >> a[i][j]; }
  }

  if (n == 1 && m == 1) {
    cout << "-1\n";
    return;
  }

  if (n == 1) {
    for (int i = 1, j = m; i < j; i++, j--)
      swap(a[1][i], a[1][j]);
    if (m & 1)
      swap(a[1][1], a[1][(m + 1) / 2]);
  } else if (m == 1) {
    for (int i = 1, j = n; i < j; i++, j--)
      swap(a[i][1], a[j][1]);
    if (n & 1)
      swap(a[1][1], a[(n + 1) / 2][1]);
  } else {
    For1(i, 1, n) {
      for (int j = 1, j1 = m; j < j1; j++, j1--)
        swap(a[i][j], a[i][j1]);
      if (m & 1)
        swap(a[i][1], a[i][(m + 1) / 2]);
    }
  }

  For1(i, 1, n) {
    For1(j, 1, m) { cout << a[i][j] << ' '; }
    NL;
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("a.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
