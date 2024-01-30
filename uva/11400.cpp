// Date: Sun Jul 16 17:37:21 2023

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
struct lamp {
  int v, k, c, l;
};
lamp a[N];
int d[N], n, p[N];

int main(void)
{
#ifdef _DEBUG
  freopen("11400.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n) && n) {
    memset(p, 0, sizeof p);
    REP1(i, 1, n) {
      scanf("%d%d%d%d", &a[i].v, &a[i].k, &a[i].c, &a[i].l);
    }
    sort(a + 1, a + n + 1, [&](const lamp &x, const lamp &y) {
      if (x.v != y.v) return x.v < y.v;
      return x.c < y.c;
    });

    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    REP1(i, 1, n) {
      p[i] = p[i - 1] + a[i].l;
    }

    d[1] = a[1].k + a[1].c * a[1].l;
    REP1(i, 2, n) {
      REP1(j, 1, i) {
        d[i] = min(d[i], d[j - 1] + (p[i] - p[j - 1]) * a[i].c + a[i].k);
      }
    }

    printf("%d\n", d[n]);
  }

  return 0;
}
