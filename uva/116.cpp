// Date: Sun Jul 16 10:36:07 2023

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


const int N = 110;
int a[N][N], nerow[N][N], m, n;
ll d[N][N];

int main(void)
{
#ifdef _DEBUG
  freopen("116.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &m, &n)) {
    memset(d, 0x3f, sizeof d);

    REP1(i, 1, m) {
      REP1(j, 1, n) {
        scanf("%d", &a[i][j]);
      }
    }

    ll ans = INF;
    int pos = -1;

    REP1(i, 1, m) {
      d[i][n] = a[i][n];
    }
    PER(j, 1, n) {
      REP1(i, 1, m) {
        VI rows = {i - 1, i, i + 1};
        if (rows[0] == 0) rows[0] = m;
        if (rows[2] == m + 1) rows[2] = 1;
        sort(all(rows));

        ll &cur = d[i][j];
        REP(k, 0, 3) {
          int row = rows[k];
          ll tmp = a[i][j] + d[row][j + 1];
          if (tmp < cur) {
            cur = tmp;
            nerow[i][j] = row;
          }
        }
      }
    }

    REP1(i, 1, m) {
      if (ans > d[i][1]) {
        ans = d[i][1];
        pos = i;
      }
    }

    int row = pos;

    REP1(j, 1, n) {
      printf("%d%c", row, (j == n ? '\n' : ' '));
      row = nerow[row][j];
    }

    printf("%lld\n", ans);
  }

  return 0;
}

