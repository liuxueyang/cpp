// Date: Sat Dec 23 15:48:37 2023

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

const int N = 200010;
int t, n, a[N];

int main(void) {
#ifdef _DEBUG
  freopen("1698c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;

    int cnt0{}, cnt1{}, cnt2{};
    VI b;
    bool flag = true;

    For1(i, 1, n) {
      cin >> a[i];
      if (a[i] == 0) {
        if (!cnt0) {
          cnt0++;
          b.pb(a[i]);
        }
      } else if (a[i] > 0) {
        cnt1++;
        if (cnt1 >= 3) {
          flag = false;
        } else {
          b.pb(a[i]);
        }
      } else {
        cnt2++;
        if (cnt2 >= 3) {
          flag = false;
        } else {
          b.pb(a[i]);
        }
      }
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }

    int len = SZ(b);
    set<int> s(all(b));

    For(i, 0, len) {
      if (!flag)
        break;
      For(j, i + 1, len) {
        if (!flag)
          break;
        For(k, j + 1, len) {
          int tmp = b[i] + b[j] + b[k];
          if (!has(s, tmp)) {
            flag = false;
            break;
          }
        }
      }
    }

    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
