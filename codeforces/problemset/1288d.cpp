// Date: Sun Dec 24 09:26:26 2023

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

const int N = 3000'10, M = 10;
int n, m, a[N][M];

PII check(int x) {
  set<int> s;
  map<int, int> b2i;
  For1(i, 1, n) {
    int tmp = 0, base = 1;
    For1(j, 1, m) {
      if (a[i][j] < x) {
      } else {
        tmp += base;
      }
      base <<= 1;
    }
    s.insert(tmp);
    b2i[tmp] = i;
  }

  for (auto x : s) {
    for (auto y : s) {
      int z = (x | y);
      if (z == ((1 << m) - 1)) {
        return {b2i[x], b2i[y]};
      }
    }
  }
  return {-1, -1};
}

int main(void) {
#ifdef _DEBUG
  freopen("1288d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n >> m) {
    For1(i, 1, n) {
      For1(j, 1, m) { cin >> a[i][j]; }
    }

    int l = 0, r = 1e9 + 10, mid;
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (check(mid) != PII{-1, -1})
        l = mid;
      else
        r = mid - 1;
    }

    auto res = check(l);
    cout << res.f1 << ' ' << res.f2 << '\n';
  }

  return 0;
}
