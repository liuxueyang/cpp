//  2023/11/17

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

const int N = 100010;
int a[N], n, t, b[N];

int main(int argc, const char * argv[]) {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        For1(i, 1, n) {
            cin >> a[i];
        }
        
        if (a[n] == 1) {
            cout << "NO\n";
            continue;
        }
        
        memset(b, 0, sizeof b);
        bool flag = true;
        int j = 1;
        
        Rof1(i, 1, n - 1) {
            if (flag) {
                if (a[i] == 1) {
                    flag = !flag;
                    b[j++] = i;
                }
            } else {
                if (a[i] == 0) {
                    flag = !flag;
                    b[j++] = i;
                }
            }
        }
        
        For1(i, j, n) {
            b[i] = 0;
        }
        
        cout << "YES\n";
        Rof1(i, 1, n) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

