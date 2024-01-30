// Date: Fri Dec 22 12:15:15 2023

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

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

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
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())

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

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

const int N = 210, M = 50010;
int t, n, m, h[N], d[N];
int idx, e[M], ne[M];

void Init() {
  idx = 0;
  memset(d, 0, sizeof d);
  memset(h, -1, sizeof h);
}

void Add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int main(void) {
#ifdef _DEBUG
  freopen("1829f.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> m;

    Init();
    For(i, 0, m) {
      int x, y;
      cin >> x >> y;
      Add(x, y);
      d[x]++;
      d[y]++;
    }

    map<int, int> ma;

    For1(i, 1, n) { ma[d[i]]++; }

    int resx = -1, resy = -1;
    for (auto &[de, cnt] : ma) {
      if (cnt == 1) {
        resx = de;
      }
    }

    if (resx != -1) {
      for (auto &[de, cnt] : ma) {
        if (cnt == resx) {
          resy = de - 1;
          break;
        }
      }
    } else {
      for (auto &[de, cnt] : ma) {
        if (de != 1) {
          resy = de - 1;
          resx = cnt - 1;
          break;
        }
      }
    }

    cout << resx << ' ' << resy << '\n';
  }

  return 0;
}
