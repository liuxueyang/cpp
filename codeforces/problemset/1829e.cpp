// Date: Mon Sep  4 12:30:52 2023

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

#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

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

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#endif

const int N = 1010, M = 1000010;
int t, n, m, a[N][N];
int fa[M], sz[M];
bool vis[N][N];

int Find(int x) { return fa[x] = (fa[x] == x ? x : Find(fa[x])); }

void Merge(int x, int y) {
  int r1 = Find(x), r2 = Find(y);
  if (sz[r1] >= sz[r2]) {
    fa[r2] = r1;
    sz[r1] += sz[r2];
  } else {
    fa[r1] = r2;
    sz[r2] += sz[r1];
  }
}

void dfs(int x, int y) {
  vis[x][y] = true;
  int p1 = x * m + y, p2;

  For(i, 0, 4) {
    int x1 = x + dir[i][0], y1 = y + dir[i][1];
    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !vis[x1][y1] &&
        a[x1][y1] > 0) {
      p2 = x1 * m + y1;
      Merge(p1, p2);
      dfs(x1, y1);
    }
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("1829e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n >> m;

    For(i, 0, n) {
      For(j, 0, m) { cin >> a[i][j]; }
    }

    memset(vis, false, sizeof vis);
    For(i, 0, m * n) {
      fa[i] = i;
      sz[i] = 1;
    }

    For(i, 0, n) {
      For(j, 0, m) {
        if (!vis[i][j] && a[i][j] > 0) {
          dfs(i, j);
        }
      }
    }

    map<int, int> depth;
    For(i, 0, n) {
      For(j, 0, m) {
        if (a[i][j]) {
          int p = i * m + j, father = Find(p);
          depth[father] += a[i][j];
        }
      }
    }

    ll ans = 0;
    for (auto [x, y] : depth) {
      ans = max(ans, ll(y));
    }

    cout << ans << '\n';
  }

  return 0;
}
