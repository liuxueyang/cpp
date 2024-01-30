// Date: Tue Jul 18 12:56:59 2023

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


const int N = 5010;
int d[N][N], pa[N], qa[N], pb[N], qb[N], n, cnt[N][N], tc, m;
char a[N], b[N];

int main(void)
{
#ifdef _DEBUG
  freopen("1625.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  scanf("%d", &tc);
  while (tc--) {
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);

    pa[0] = pa[n + 1] = qa[0] = qa[n + 1] = 0;
    pb[0] = pb[m + 1] = qb[0] = qb[m + 1] = 0;
    REP1(i, 1, n) pa[i] = pa[i - 1] | (1 << (a[i] - 'A'));
    PER1(i, 1, n) qa[i] = qa[i + 1] | (1 << (a[i] - 'A'));
    REP1(i, 1, m) pb[i] = pb[i - 1] | (1 << (b[i] - 'A'));
    PER1(i, 1, m) qb[i] = qb[i + 1] | (1 << (b[i] - 'A'));

    REP1(i, 0, n) {
      REP1(j, 0, m) {
        cnt[i][j] = __builtin_popcount((pa[i] | pb[j]) & (qa[i + 1] | qb[j + 1]));
        // debug3(i, j, cnt[i][j]);
      }
    }

    REP1(i, 0, n) {
      REP1(j, 0, m) {
        if (i + j == 0) d[i][j] = 0;
        else d[i][j] = INF;

        if (j) d[i][j] = min(d[i][j], d[i][j - 1] + cnt[i][j - 1]);
        if (i) d[i][j] = min(d[i][j], d[i - 1][j] + cnt[i - 1][j]);
      }
    }

    printf("%d\n", d[n][m]);
  }

  return 0;
}
