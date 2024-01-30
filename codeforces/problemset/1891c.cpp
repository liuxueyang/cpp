// Date: Wed Dec 27 14:16:40 2023

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

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif


const int N = 200010;
int t, n, a[N];

int main(void)
{
#ifdef _DEBUG
    freopen("1891c.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        ll sum = 0;
        For1(i, 1, n) cin >> a[i], sum += a[i];
        ll top = sum / 2, res = 0;
        sort(a + 1, a + 1 + n, greater<int>());
        For1(i, 1, n) {
            if (!top) {
                break;
            }
            if (top >= a[i]) {
                top -= a[i];
                a[i] = 0;
                res++;
            } else {
                a[i] -= top;
                top = 0;
                res++;
            }
        }
        For1(i, 1, n) if (a[i]) res += a[i];
        cout << res << '\n';
    }

    return 0;
}
