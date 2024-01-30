// Date: Tue Dec 12 21:38:26 2023

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

const int N = 110;
int t, n, m;
char a[N][N], b[N][N];

struct point {
  PII p1, p2;
  point(int x1, int y1, int x2, int y2) : p1({x1, y1}), p2({x2, y2}) {}
  void print() {
    cout << p1.f1 + 1 << ' ' << p1.f2 + 1 << ' ' << p2.f1 + 1 << ' '
         << p2.f2 + 1;
  }
};

int main(void) {
#ifdef _DEBUG
  freopen("1647c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> m;
    memset(b, 0, sizeof b);

    For(i, 0, n) { cin >> a[i]; }

    bool flag = true;
    vector<point> res;

    Rof(i, 0, n) {
      if (!flag)
        break;

      Rof(j, 0, m) {
        if (a[i][j] != '0') {
          if (!j) {
            if (!i) {
              flag = false;
              break;
            }
            b[i - 1][j] = '0';
            res.pb(point(i - 1, j, i, j));
          } else {
            b[i][j - 1] = '0';
            res.pb(point(i, j - 1, i, j));
          }
        }
        b[i][j] = a[i][j];
      }
    }

    if (!flag) {
      cout << "-1\n";
      continue;
    }

    int len = SZ(res);
    cout << len << '\n';
    if (len) {
      For(i, 0, len) {
        res[i].print();
        cout << '\n';
      }
    }
  }

  return 0;
}
