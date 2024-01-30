// Date: Sun Oct 15 11:28:31 2023

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

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
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#endif

const int N{1000'10};
int b[N], c[N];
class Solution {
public:
  vector<int> findIndices(vector<int> &a, int difi, int difv) {

    int n = SZ(a);
    memset(b, 0, sizeof b);
    memset(c, 0x3f, sizeof c);
    c[n] = a[n - 1];

    Rof(i, 0, n) { b[i] = max(a[i], b[i + 1]); }
    Rof(i, 0, n) c[i] = min(a[i], c[i + 1]);

    VI res(2, -1);

    For(i, 0, n) {
      int j = i + difi;
      if (j >= n)
        continue;
      int tmp = abs(a[i] - b[j]);
      if (tmp >= difv) {
        res[0] = i;

        For(k, j, n) {
          tmp = abs(a[i] - a[k]);
          if (tmp >= difv) {
            res[1] = k;
            break;
          }
        }
        break;
      }

      tmp = abs(a[i] - c[j]);
      if (tmp >= difv) {
        res[0] = i;

        For(k, j, n) {
          tmp = abs(a[i] - a[k]);
          if (tmp >= difv) {
            res[1] = k;
            break;
          }
        }
        break;
      }
    }
    return res;
  }
};
