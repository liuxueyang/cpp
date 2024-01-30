// Date: Sat Dec 16 09:14:16 2023

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
    {1, 0},
    {-1, 0},
    {0, 1},
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
int t, n;
bool vis[2][N];
char a[2][N];

bool check(int x, int y) {
  return x >= 0 && x < 2 && y >= 0 && y < n && a[x][y] == 'B' && !vis[x][y];
}

void dfs(int x, int y) {
  vis[x][y] = true;
  int x1, y1;

  For(i, 0, 3) {
    x1 = x + dir[i][0];
    y1 = y + dir[i][1];

    if (check(x1, y1)) {
      dfs(x1, y1);
      return;
    }
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("1766c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n >> a[0] >> a[1];

    memset(vis, false, sizeof vis);
    bool flag = true;

    dfs(0, 0);
    For(i, 0, 2) {
      For(j, 0, n) {
        if (a[i][j] == 'B' && !vis[i][j]) {
          flag = false;
          break;
        }
      }
      if (!flag)
        break;
    }

    if (flag) {
      cout << "YES\n";
      continue;
    }

    memset(vis, false, sizeof vis);
    flag = true;

    dfs(1, 0);
    For(i, 0, 2) {
      For(j, 0, n) {
        if (a[i][j] == 'B' && !vis[i][j]) {
          flag = false;
          break;
        }
      }
      if (!flag)
        break;
    }

    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
