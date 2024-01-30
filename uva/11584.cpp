// Date: Mon Jul 17 21:08:57 2023

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif


const int N = 1010;
int d[N], n, tc;
char a[N];
bool vis[N][N];

int main(void)
{
#ifdef _DEBUG
  freopen("11584.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  scanf("%d", &tc);
  while (tc--) {
    memset(vis, false, sizeof vis);
    scanf("%s", a);
    n = strlen(a);

    REP(i, 0, n) {
      vis[i][i] = true;
      for (int j = i - 1, k = i + 1; j >= 0 && k < n && a[j] == a[k]; j--, k++) {
        vis[j][k] = true;
      }
    }

    REP(i, 0, n - 1) {
      for (int j = i, k = i + 1; j >= 0 && k < n && a[j] == a[k]; --j, ++k) {
        vis[j][k] = true;
      }
    }

    memset(d, 0x3f, sizeof d);
    d[0] = 1;

    REP(i, 1, n) {
      d[i] = d[i - 1] + 1;
      if (vis[0][i]) d[i] = min(d[i], 1);

      REP(j, 0, i) {
        if (vis[j + 1][i])
          d[i] = min(d[i], d[j] + 1);
      }
    }

    printf("%d\n", d[n - 1]);
  }

  return 0;
}
