//  2023/11/18

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

#ifdef DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

#ifdef DEBUG

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

const int N = 1010, M = 1e7 + 10;
int t, n, a[N];
bool vis[M];
map<int, int> m;

void defact(int x) {
    if (!vis[x]) {
        m[x]++;
        return;
    }
    
    for (ll i = 2; i * i <= x; ++i) {
        if (!vis[i]) {
            int cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            m[i] += cnt;
        }
    }
    if (x > 1) m[x]++;
}

int main(int argc, const char * argv[]) {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(vis, false, sizeof vis);
    
    int top = 1e7;
    for (int i = 2; i <= top; ++i) {
        if (!vis[i]) {
            for (int j = i + i; j <= top; j += i) {
                vis[j] = true;
            }
        }
    }
    
    cin >> t;
    while (t--) {
        m.clear();
        cin >> n;
        
        For1(i, 1, n) {
            cin >> a[i];
            defact(a[i]);
        }
        
        int res {0};
        VI b;
        
        for (auto &[_, y] : m) {
            b.pb(y);
        }
        
        int tmp = 0;
        for (auto x : b) {
            if (x >= 2) {
                res += x / 2;
                tmp += (x % 2);
                
                if (tmp >= 3) {
                    res += tmp / 3;
                    tmp %= 3;
                }
            } else {
                tmp += x;
                if (tmp >= 3) {
                    res += tmp / 3;
                    tmp %= 3;
                }
            }
        }
        
        if (tmp >= 3) {
            res += tmp / 3;
            tmp %= 3;
        }
        
        cout << res << '\n';
    }

    return 0;
}

