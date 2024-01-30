// Date: Mon Dec 18 22:39:07 2023

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
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

const int N = 100010;
int t, n, d[N][2], a, b;
string s;

int main(void) {
#ifdef _DEBUG
  freopen("1443b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> a >> b >> s;

    n = SZ(s);
    memset(d, 0x3f, sizeof d);

    int res = INF;
    if (s[0] == '0') {
      d[0][0] = 0;
      d[0][1] = a + b;
    } else {
      d[0][1] = a;
    }

    For(i, 1, n) {
      if (s[i] == '0') {
        if (s[i - 1] == '0') {
          d[i][0] = d[i - 1][0];
          d[i][1] = d[i - 1][1] + b;
        } else {
          d[i][0] = d[i - 1][1];
          d[i][1] = d[i - 1][1] + b;
        }
      } else {
        if (s[i - 1] == '0') {
          d[i][1] = min(d[i - 1][0] + a, d[i - 1][1]);
        } else {
          d[i][1] = d[i - 1][1];
        }
      }
    }

    if (s[n - 1] == '1')
      res = d[n - 1][1];
    else
      res = min(d[n - 1][0], d[n - 1][1]);

    cout << res << '\n';
  }

  return 0;
}
