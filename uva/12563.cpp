// Date: Sun Jul 16 13:42:49 2023

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


const int N = 60, M = 10010;
int d[N][M], d1[N][M], tc, n, t, a[N];

int main(void)
{
#ifdef _DEBUG
  freopen("12563.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  scanf("%d", &tc);
  int tn = 0;
  while (tc--) {
    tn++;
    scanf("%d%d", &n, &t);
    REP1(i, 1, n) scanf("%d", a + i);
    memset(d, 0, sizeof d);
    memset(d1, 0, sizeof d1);

    REP1(i, 1, n) {
      REP1(j, 0, t - 1) {
        int &cur = d[i][j];
        if (cur < d[i - 1][j]) {
          cur = d[i - 1][j];
          d1[i][j] = d1[i - 1][j];
        } else if (cur == d[i - 1][j]) {
          d1[i][j] = max(d1[i][j], d1[i - 1][j]);
        }

        if (j >= a[i]) {
          if (cur < d[i - 1][j - a[i]] + 1) {
            cur = d[i - 1][j - a[i]] + 1;
            d1[i][j] = d1[i - 1][j - a[i]] + a[i];
          } else if (cur == d[i - 1][j - a[i]] + 1) {
            d1[i][j] = max(d1[i][j], d1[i - 1][j - a[i]] + a[i]);
          }
        }
      }
    }
    int ans_cnt = d[n][t - 1] + 1, ans_total = d1[n][t - 1] + 678;

    printf("Case %d: %d %d\n", tn, ans_cnt, ans_total);
  }

  return 0;
}
