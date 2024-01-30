// Date: Sun Dec 10 15:00:10 2023

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

const int N = 200010;

struct point {
  int v, p1, p2, idx;
};

int t, n;
point a[N];
bool vis[2][N];

int main(void) {
#ifdef _DEBUG
  freopen("1768c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    For1(i, 1, n) {
      cin >> a[i].v;
      a[i].idx = i;
      a[i].p1 = a[i].p2 = 0;
    }

    sort(a + 1, a + n + 1, [&](const point &x, const point &y) {
      if (x.v > y.v)
        return true;
      else if (x.v == y.v)
        return x.idx < y.idx;
      return false;
    });

    memset(vis, false, sizeof vis);
    bool flag = true;

    For1(i, 1, n) {
      int x = a[i].v;
      if (!vis[0][x]) {
        vis[0][x] = true;
        a[i].p1 = x;
      } else if (!vis[1][x]) {
        vis[1][x] = true;
        a[i].p2 = x;
      } else {
        flag = false;
        break;
      }
    }

    VI rem1;

    Rof1(i, 1, n) {
      if (!vis[0][i]) {
        rem1.pb(i);
      }
    }

    if (nonempty(rem1)) {
      int idx = 0;
      For1(i, 1, n) {
        if (!a[i].p1) {
          if (rem1[idx] <= a[i].v) {
            a[i].p1 = rem1[idx++];
          } else {
            flag = false;
            break;
          }
        }
      }
    }

    VI rem2;

    Rof1(i, 1, n) {
      if (!vis[1][i]) {
        rem2.pb(i);
      }
    }

    if (nonempty(rem2)) {
      int idx = 0;
      For1(i, 1, n) {
        if (!a[i].p2) {
          if (rem2[idx] <= a[i].v) {
            a[i].p2 = rem2[idx++];
          } else {
            flag = false;
            break;
          }
        }
      }
    }

    if (flag) {
      cout << "YES\n";

      sort(a + 1, a + n + 1,
           [&](const point &x, const point &y) { return x.idx < y.idx; });

      For1(i, 1, n) { cout << a[i].p1 << ' '; }
      cout << '\n';

      For1(i, 1, n) { cout << a[i].p2 << ' '; }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
