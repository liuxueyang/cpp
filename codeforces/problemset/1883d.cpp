// Date: Wed Dec 27 16:24:53 2023

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

int q, l, r;
set<int> l_s, r_s;
map<int, int> lcnt, rcnt;

bool check() {
  bool mark = false;
  if (nonempty(r_s)) {
    auto it = r_s.begin();
    int a = *it;

    auto it1 = l_s.upper_bound(a);
    if (it1 != l_s.end()) {
      mark = true;
    }
  }
  return mark;
}

int main(void) {
#ifdef _DEBUG
  freopen("1883d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  l_s.clear();
  r_s.clear();
  lcnt.clear();
  rcnt.clear();
  cin >> q;
  string op;

  while (q--) {
    cin >> op >> l >> r;
    if (op == "+") {
      lcnt[l]++;
      rcnt[r]++;
      l_s.insert(l);
      r_s.insert(r);

      bool mark = check();
      cout << (mark ? "YES" : "NO") << '\n';
    } else {
      lcnt[l]--;
      rcnt[r]--;
      if (lcnt[l] == 0) {
        l_s.erase(l);
      }
      if (rcnt[r] == 0) {
        r_s.erase(r);
      }

      bool mark = check();
      cout << (mark ? "YES" : "NO") << '\n';
    }
  }

  return 0;
}
