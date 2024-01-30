// Date: Fri Dec 15 21:20:18 2023

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

int t;
string s;

string a[70];

int solve(string &s, string &t) {
  int len1 = SZ(s), len2 = SZ(t);
  int j = 0, i = 0;
  for (; i < len2; ++i) {
    while (j < len1 && t[i] != s[j])
      ++j;
    if (j == len1)
      break;
    ++j;
  }
  --i;
  int match_cnt = i + 1;
  return len1 - match_cnt + (len2 - match_cnt);
}

int main(void) {
#ifdef _DEBUG
  freopen("1560d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  For(i, 0, 63) {
    ll x = (1LL << i);
    a[i] = to_string(x);
  }

  while (t--) {
    cin >> s;

    int res = INF;
    For(i, 0, 63) {
      int tmp = solve(s, a[i]);
      res = min(res, tmp);
    }
    cout << res << '\n';
  }

  return 0;
}
