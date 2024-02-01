// Date: Thu Feb  1 22:53:55 2024

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

const int N = 200100;
int n, a[N], b[N];

int getn(int x) {
  int ans{};
  while (x) {
    ans++;
    x /= 10;
  }
  return ans;
}

void solve() {
  cin >> n;
  map<int, int> ma, mb;

  For1(i, 1, n) {
    cin >> a[i];
    ++ma[a[i]];
  }
  For1(i, 1, n) {
    cin >> b[i];
    ++mb[b[i]];
  }

  int ans = 0;

  auto vaccum = [&](map<int, int> &m1, map<int, int> &m2) {
    VI era;
    for (auto &[x, cnt1] : m1) {
      if (!cnt1) {
        era.pb(x);
        continue;
      }
      if (has(m2, x)) {
        int cnt2 = m2[x];
        int cnt = min(cnt2, cnt1);
        cnt1 -= cnt;
        m2[x] -= cnt;
        if (!m2[x])
          m2.erase(x);
      }
    }
    for (auto x : era)
      m1.erase(x);
  };

  auto clean2 = [&](map<int, int> &m) {
    VI era, s;
    for (auto &[x, cnt] : m) {
      if (!cnt) {
        era.pb(x);
        continue;
      }
      if (x >= 11) {
        s.pb(x);
      }
    }
    for (auto x : era)
      m.erase(x);
    for (auto x : s) {
      int len = getn(x);
      m[len] += m[x];
      ans += m[x];
      m.erase(x);
    }
  };

  auto clean3 = [&](map<int, int> &m) {
    VI era, s;
    for (auto &[x, cnt] : m) {
      if (!cnt) {
        era.pb(x);
        continue;
      }
      if (x == 10) {
        s.pb(x);
      }
    }
    for (auto x : era)
      m.erase(x);
    for (auto x : s) {
      int len = getn(x);
      m[len] += m[x];
      ans += m[x];
      m.erase(x);
    }
  };

  auto clean4 = [&](map<int, int> &m) {
    for (auto &[x, y] : m) {
      if (x == 1)
        continue;
      ans += y;
    }
  };

  vaccum(ma, mb);
  clean2(ma);
  clean2(mb);
  vaccum(ma, mb);
  clean3(ma);
  clean3(mb);
  vaccum(ma, mb);
  clean4(ma);
  clean4(mb);

  cout << ans << '\n';
}

int main(void) {
#ifdef _DEBUG
  freopen("1728c.in", "r", stdin);
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
