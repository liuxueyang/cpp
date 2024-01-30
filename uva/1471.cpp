// Date: Sat Aug  5 18:21:56 2023

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


const int N = 200010;
int a[N], n, f[N], g[N], T;

int main(void)
{
#ifdef _DEBUG
  freopen("1471.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> n;
    For1(i, 1, n) {
      cin >> a[i];
      f[i] = g[i] = 1;
    }

    Rof1(i, 1, n) {
      if (i + 1 <= n && a[i] < a[i + 1]) {
        f[i] = f[i + 1] + 1;
      }
    }

    For1(i, 1, n) {
      if (i - 1 >= 1 && a[i] > a[i - 1]) {
        g[i] = g[i - 1] + 1;
      }
    }

    int ans = 1;
    set<PII> s;
    s.insert({a[1], g[1]});

    For1(i, 2, n) {
      PII item = {a[i], g[i]};
      // NOTE lower_bound in algorithm requires random-access iterators which is not the case for set
      // So it will be bad performance for set
      // auto it = lower_bound(s.begin(), s.end(), item);

      // This is the correct way
      auto it = s.lower_bound(item);

      if (it == s.begin()) {
        if (it->f1 == a[i] && it->f2 >= g[i]) continue;

        while (it != s.end() && it->f1 >= a[i] && it->f2 <= g[i])
          s.erase(it++);

        s.insert(item);
        ans = max(ans, f[i]);
      } else {
        auto it1 = it; it1--;
        ans = max(ans, it1->f2 + f[i]);

        if (it1->f2 >= g[i]) continue;

        while (it != s.end() && it->f1 >= a[i] && it->f2 <= g[i])
          s.erase(it++);

        s.insert(item);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
