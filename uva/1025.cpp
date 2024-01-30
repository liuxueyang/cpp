// Date: Sat Jul 15 16:14:25 2023

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



const int N = 60, T = 210;
int d[T][N], n, t, m1, m2, dm[N], em[N], hr[T * 10][N], hl[T * 10][N], a[N];

int main(void)
{
#ifdef _DEBUG
  freopen("1025.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int tc = 0;
  while (~scanf("%d", &n) && n) {
    tc++;
    memset(hr, 0, sizeof hr);
    memset(hl, 0, sizeof hl);
    memset(d, 0x3f, sizeof d);

    scanf("%d", &t);
    d[t][n] = 0;

    REP(i, 1, n) {
      scanf("%d", a + i);
    }

    scanf("%d", &m1);
    REP1(i, 1, m1) scanf("%d", dm + i);

    scanf("%d", &m2);
    REP1(i, 1, m2) scanf("%d", em + i);

    REP1(i, 1, m1) {
      int cur = dm[i];
      hr[cur][1] = 1;
      REP(j, 1, n) {
        cur += a[j];
        // debug2(cur, j + 1);
        hr[cur][j + 1] = 1;
      }
    }

    REP1(i, 1, m2) {
      int cur = em[i];
      hl[cur][n] = 1;
      PER(j, 1, n) {
        cur += a[j];
        // debug2(cur, j);
        hl[cur][j] = 1;
      }
    }

    PER(i, 0, t) {
      REP1(j, 1, n) {
        int &ans = d[i][j];
        ans = min(ans, d[i + 1][j] + 1);
        if (hr[i][j] && i + a[j] <= t && j + 1 <= n) {
          ans = min(ans, d[i + a[j]][j + 1]);
        }
        if (hl[i][j] && i + a[j - 1] <= t && j - 1 >= 1) {
          ans = min(ans, d[i + a[j - 1]][j - 1]);
        }
        // debug3(i, j, ans);
        // debug3(i + 1, j, d[i + 1][j]);
      }
    }

    printf("Case Number %d: ", tc);
    if (d[0][1] == INF) {
      printf("impossible\n");
    } else {
      printf("%d\n", d[0][1]);
    }
  }

  return 0;
}
