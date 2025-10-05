
#include <cassert>
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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

const ull Pr = 131;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nemp(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
  }
  return out;
}

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define debug1
#define debug2
#define debug3
#define dbg(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

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
// End of LeetCode

const int N = 23;
int d[N][N][N][N];
bool vis[N][N][N][N];
int rco[N], cco[N];

class Solution {
public:
    int m, n, ans;
    
    bool check_row(int r) {
        return r >= 0 && r <= m;
    }
    bool check_col(int c) {
        return c >= 0 && c <= n;
    }

    int dfs(int r1, int r2, int c1, int c2) {
        if (!(check_row(r1) && check_row(r2) && check_col(c1) && check_col(c2))) {
            return INF;
        }
        if (vis[r1][r2][c1][c2]) return d[r1][r2][c1][c2];
        vis[r1][r2][c1][c2] = true;
        int &cur = d[r1][r2][c1][c2];

        if (r2 - r1 > 1) {
            For(i, r1 + 1, r2) {
                int tmp = dfs(r1, i, c1, c2) + dfs(i, r2, c1, c2);
                if (cur > tmp + rco[i]) cur = tmp + rco[i];
            }
        }
        if (c2 - c1 > 1) {
            For(i, c1 + 1, c2) {
                int tmp = dfs(r1, r2, c1, i) + dfs(r1, r2, i, c2);
                if (cur > tmp + cco[i]) cur = tmp + cco[i];
            }
        }
        if (r2 - r1 == 1 && c2 - c1 == 1) cur = 0;
        return cur;
    }
    
    ll minimumCost(int m, int n, vector<int>& ho, vector<int>& ve) {
        pq<int> pc(all(ve)), pr(all(ho));
        int cntc{1}, cntr {1};
        ll sumc {0}, sumr{0};
        ll ans {};

        for (auto x : ho) sumr += x;
        for (auto x : ve) sumc += x;

        while (nemp(pc) || nemp(pr)) {
            if (nemp(pc) && nemp(pr)) {
                if (pc.top() >= pr.top()) {
                    ans += pc.top() * cntr;
                    dbg(pc.top() * cntr);

                    sumc -= pc.top();
                    pc.pop();
                    cntc++;
                } else {
                    ans += pr.top() * cntc;
                    dbg(pr.top() * cntc);

                    sumr -= pr.top();
                    pr.pop();
                    cntr++;
                }
            } else if (nemp(pc)) {
                ans += pc.top() * cntr;
                dbg(pc.top() * cntr);
                sumc -= pc.top();
                pc.pop();
                cntc++;
            } else if (nemp(pr)) {
                ans += pr.top() * cntc;
                dbg(pr.top() * cntc);
                sumr -= pr.top();
                pr.pop();
                cntr++;
            }
        }

        dbg(cntc, cntr);

        return ans;
    }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  VI ho {1, 3}, ve {5};
  ll res;

  res = a.minimumCost(3, 2, ho, ve);
  dbg(res);

  return 0;
}

#endif
