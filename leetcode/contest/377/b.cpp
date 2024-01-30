// Date: Sun Dec 24 10:52:53 2023

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

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


const int N = 400010;
int a[N], b[N];

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
       hf.pb(1), vf.pb(1);
       hf.pb(m), vf.pb(n);
       int len1 = SZ(hf), len2 = SZ(vf);
       ll res = -1;
       sort(all(hf));
       sort(all(vf));
       unordered_map<int, int> hs, vs;

       For(i, 0, len1) {
           For(i1, i + 1, len1) {
               int w = abs(hf[i] - hf[i1]);
               if (!w) continue;

               hs[w] = 1;
           }
       }

       For(i, 0, len2) {
           For(i1, i + 1, len2) {
               int w = abs(vf[i] - vf[i1]);
               if (!w) continue;

               vs[w] = 1;
           }
       }

       int cnt1 = 0, cnt2 = 0;
       for (auto &[x, _] : hs) a[cnt1++] = x;
       for (auto &[x, _] : vs) b[cnt2++] = x;

       sort(a, a + cnt1);
       sort(b, b + cnt2);

       int j = 0;
       For(i, 0, cnt1) {
           while (j < cnt2 && b[j] < a[i]) ++j;
           if (j < cnt2 && b[j] == a[i]) {
               res = max(res, ll(b[j]) * b[j]);
           }
           if (j == cnt2) break;
       }

       if (res == -1) return res;
       return res % MOD;
    }
};
