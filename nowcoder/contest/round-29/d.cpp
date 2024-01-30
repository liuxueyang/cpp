// Date: Sun Jan 21 19:45:23 2024

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

const int N = 100100;
int n, a[N];
PII b[N];

void solve() {
  while (~scanf("%d", &n)) {
    For1(i, 1, n) {
      scanf("%d", &a[i]);
      b[i] = {a[i], i};
    }

    sort(b + 2, b + 1 + n);
    multiset<PII> s2;
    multiset<PII, greater<PII>> s1;

    int len1, len2;
    if (n & 1) {
      len1 = len2 = (n - 1) / 2;
    } else {
      len1 = n / 2;
      len2 = len1 - 1;
    }

    For1(i, 2, n) {
      if (SZ(s1) < len1) {
        s1.insert(b[i]);
      } else {
        s2.insert(b[i]);
      }
    }

    if (n & 1) {
      auto t1 = *s1.begin(), t2 = *s2.begin();
      double r = t1.f1 + t2.f1;
      r /= 2;
      printf("%.1lf\n", r);
    } else {
      auto t = *s1.begin();
      double r = t.f1;
      printf("%.1lf\n", r);
    }

    For1(i, 2, n) {
      auto x = PII(a[i], i);
      if (has(s1, x)) {
        s1.erase(x);
      } else {
        s2.erase(x);
      }

      if (nemp(s1)) {
        auto t = *s1.begin();

        if (t.f1 >= a[i - 1]) {
          s1.insert({a[i - 1], i - 1});
        } else {
          s2.insert({a[i - 1], i - 1});
        }
      } else {
        s2.insert({a[i - 1], i - 1});
      }

      while (SZ(s1) != len1) {
        if (SZ(s1) > len1) {
          auto it = s1.begin();
          auto p1 = *it;
          s1.erase(it);
          s2.insert(p1);
        } else {
          auto it = s2.begin();
          auto p1 = *it;
          s2.erase(it);
          s1.insert(p1);
        }
      }

      if (n & 1) {
        auto t1 = *s1.begin(), t2 = *s2.begin();
        double r = t1.f1 + t2.f1;
        r /= 2;
        printf("%.1lf\n", r);
      } else {
        auto t = *s1.begin();
        double r = t.f1;
        printf("%.1lf\n", r);
      }
    }
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 1;

  while (T--) {
    solve();
  }

  return 0;
}
