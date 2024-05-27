// Date: Sat Oct 21 17:04:27 2023

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

class Solution {
public:
  int last5(string &s) {
    int res{0};
    int n = SZ(s), i = n - 1;

    while (i >= 0 && s[i] != '5') {
      --i;
      res++;
    }
    if (i < 0)
      return n;

    --i;
    while (i >= 0 && !(s[i] == '2' || s[i] == '7')) {
      res++;
      --i;
    }

    if (i < 0)
      return n;

    return res;
  }

  int last0(string &s) {
    int res{0};
    int n = SZ(s), i = n - 1;

    while (i >= 0 && s[i] != '0') {
      --i;
      res++;
    }
    if (i < 0)
      return n;

    --i;
    while (i >= 0 && !(s[i] == '0' || s[i] == '5')) {
      res++;
      --i;
    }
    return res;
  }

  int minimumOperations(string s) {
    int cnt1 = last5(s), cnt2 = last0(s);
    // printf("cnt1=%d, cnt2=%d\n", cnt1, cnt2);
    return min(cnt1, cnt2);
  }
};