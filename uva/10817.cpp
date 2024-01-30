// Date: Sun Jul 23 16:42:27 2023

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
#define RofE(i, j) for (int i = h[j]; i != -1; i = ne[i])

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


const int N = 110, M = 30;
int d[N + M][260][260], n, m, s, st[N + M], c[N + M];

int dp(int i, int s0, int s1, int s2) {
  int &ans = d[i][s1][s2];

  if (ans >= 0) return ans;
  if (i == m + n) {
    if (s2 == (1 << s) - 1) ans = 0;
    else ans = INF;
    return ans;
  }

  ans = INF;
  if (i >= m) {
    ans = min(ans, dp(i + 1, s0, s1, s2));
  }

  int m0 = s0 & st[i], m1 = s1 & st[i];
  s0 = s0 ^ m0;
  s1 = m0 | (s1 ^ m1);
  s2 = s2 | m1;

  ans = min(ans, dp(i + 1, s0, s1, s2) + c[i]);
  return ans;
}

int main(void)
{
#ifdef _DEBUG
  freopen("10817.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> s >> m >> n && s) {
    memset(st, 0, sizeof st);
    memset(c, 0, sizeof c);
    memset(d, -1, sizeof d);

    string ss;
    getline(cin, ss);

    int i = 0;
    for (; i < m + n; ++i) {
      getline(cin, ss);

      stringstream tmp(ss);

      tmp >> c[i];
      int x;
      while (tmp >> x) {
        --x;
        st[i] = st[i] | (1 << x);
      }
    }

    int ans = dp(0, (1 << s) - 1, 0, 0);
    printf("%d\n", ans);
  }

  return 0;
}
