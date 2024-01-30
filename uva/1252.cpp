// Date: Sat Aug  5 11:24:42 2023

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


const int N = 2100, M = 150;
int m, n, d[N][N], a[M], cnt[N][N];
string b[M];

int dp(int s, int t) {
  if (cnt[s][t] == 1) {
    return d[s][t] = 0;
  }

  if (d[s][t] != -1) return d[s][t];

  d[s][t] = INF;

  For(k, 0, m) {
    int tmp = (1 << k);
    if (tmp & s) continue;

    int r1 = dp(tmp | s, t), r2 = dp(tmp | s, tmp | t), r = max(r1, r2) + 1;
    d[s][t] = min(d[s][t], r);
  }

  return d[s][t];
}

int main(void)
{
#ifdef _DEBUG
  freopen("1252.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> m >> n && m) {
    For(i, 0, n) {
      cin >> b[i];
      a[i] = 0;
      For(j, 0, m) a[i] = a[i] * 2 + (b[i][j] - '0');
    }

    memset(d, -1, sizeof d);
    memset(cnt, 0, sizeof cnt);

    For(i, 0, (1 << m)) {
      // For(k, 0, n) {
      //   cnt[i][a[k] & i]++;
      // }

      for (int j = i; j >= 0; j = (i & (j - 1))) {
        For(k, 0, n) {
          if ((a[k] & i) == j) cnt[i][j]++;
        }
        if (j == 0) break;      // NOTE empty set should also be considered
      }
    }

    dp(0, 0);
    cout << d[0][0] << '\n';
  }

  return 0;
}
