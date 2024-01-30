// Date: Sun Dec  3 18:52:56 2023

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
ll a[N][N];
bool vis[N][N];

int main(void) {
#ifdef _DEBUG
  freopen("1422b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> m;
    memset(vis, false, sizeof vis);

    For1(i, 1, n) {
      For1(j, 1, m) { cin >> a[i][j]; }
    }

    ll res = 0;

    For1(i, 1, n) {
      int i1 = n + 1 - i;
      if (i1 < i)
        break;

      For1(j, 1, m) {
        VI tmp;
        tmp.clear();

        int j1 = m + 1 - j;
        if (j1 < j)
          break;

        if (j1 != j) {
          tmp.pb(a[i][j]);

          tmp.pb(a[i][j1]);

          if (i != i1) {
            tmp.pb(a[i1][j]);
            tmp.pb(a[i1][j1]);
          }
        } else {
          if (i != i1) {
            tmp.pb(a[i][j]);
            tmp.pb(a[i1][j]);
          }
        }

        int len = SZ(tmp);
        if (len)
          sort(all(tmp));

        if (len == 4) {
          For(k, 0, len) { res += abs(tmp[k] - tmp[1]); }
        } else if (len == 2) {
          res += abs(tmp[0] - tmp[1]);
        }
      }
    }

    cout << res << '\n';
  }

  return 0;
}
