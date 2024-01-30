// Date: Thu Jul 20 12:44:27 2023

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


const int N = 110;
string a;
int n, tc, d[N][N];

bool match(int i, int j) {
  return ((a[i] == '(' && a[j] == ')') ||
          (a[i] == '[' && a[j] == ']'));
}

void print(int i, int j) {
  if (i > j) return;
  if (i == j) {
    if (a[i] == '(' || a[i] == ')') cout << "()";
    else cout << "[]";
  } else {
    if (match(i, j) && d[i][j] == d[i + 1][j - 1]) {
      cout << a[i];
      print(i + 1, j - 1);
      cout << a[j];
    } else {
      For1(k, i, j) {
        if (d[i][j] == d[i][k] + d[k + 1][j]) {
          print(i, k);
          print(k + 1, j);
          return;
        }
      }
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("1626.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> tc;
  getline(cin, a);
  getline(cin, a);

  while (tc--) {
    getline(cin, a);
    n = SZ(a);

    debug2(a, n);
    a = " " + a;

    memset(d, 0x3f, sizeof d);
    d[0][0] = 0;

    For1(j, 1, n) {
      Rof1(i, 1, j) {
        if (i == j) {
          d[i][j] = 1;
          d[j + 1][j] = 0;
        } else {
          if (match(i, j)) d[i][j] = min(d[i][j], d[i + 1][j - 1]);

          For1(k, i, j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j]);
          }
        }
      }
    }

    print(1, n);
    cout << "\n";
    if (tc) cout << "\n";
    getline(cin, a);
  }

  return 0;
}
