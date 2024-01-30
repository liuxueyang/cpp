// Date: Fri Dec 15 10:43:00 2023

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

const int N = 500010;

int t, n, a[N];
struct point {
  int i, j, x, y;
};

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int main(void) {
#ifdef _DEBUG
  freopen("1521b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    For1(i, 1, n) { cin >> a[i]; }

    vector<point> res;
    PII mi{INF, -1};

    For1(i, 1, n) {
      if (a[i] < mi.f1) {
        mi = {a[i], i};
      }
    }

    bool flag = true;

    For1(i, 1, n - 1) {
      if (gcd(a[i], a[i + 1]) > 1) {
        flag = false;
        break;
      }
    }

    if (flag) {
      cout << "0\n";
      continue;
    }

    For1(i, 1, n) {
      if (i == mi.f2)
        continue;
      res.pb({i, mi.f2, mi.f1 + abs(i - mi.f2), mi.f1});
    }

    int len = SZ(res);
    cout << len << '\n';
    if (len) {
      for (auto e : res) {
        cout << e.i << ' ' << e.j << ' ' << e.x << ' ' << e.y << '\n';
      }
    }
  }

  return 0;
}
