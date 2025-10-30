// Date: Fri Dec 29 12:04:17 2023

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

const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ll INF = 0x3f3f3f3f'3f3f3f3f, MOD = 1e9 + 7;

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

using PLI = pair<ll, int>;

const int N = 1100, M = 1100 * 2;
int t, n, m, h[N], g[N][N], s[N];
int idx, e[M], ne[M], w[M];

struct point {
  ll val;
  int ver, s0;
  point(ll _val, int _ver, int _s0) : val(_val), ver(_ver), s0(_s0) {}
  bool operator>(const point &rhs) const { return val > rhs.val; }
};

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(g, 0x3f, sizeof g);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

ll dijkstra() {
  priority_queue<point, vector<point>, greater<point>> q;
  q.push({0, 1, s[1]});
  map<PII, ll> dis;
  dis[{1, s[1]}] = 0;
  set<PII> vis;

  while (nemp(q)) {
    auto t = q.top();
    q.pop();

    ll base = t.val;
    int ver = t.ver, sv = t.s0;

    if (has(vis, PII(ver, sv)))
      continue;

    vis.insert(PII(ver, sv));

    ForE(i, ver) {
      int j = e[i], svj = min(sv, s[j]);
      PII pj = PII(j, svj);

      ll tmp = base + sv * w[i];
      if (!has(dis, pj) || tmp < dis[pj]) {
        dis[pj] = tmp;
        q.push(point(tmp, j, svj));
      }
    }
  }

  ll res = INF;
  For1(i, 1, 1000) {
    PII p = PII(n, i);
    if (dis.find(p) != dis.end()) {
      res = min(res, dis[p]);
    }
  }
  return res;
}

int main(void) {
#ifdef _DEBUG
  freopen("g.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--) {
    Init();
    cin >> n >> m;

    For(i, 0, m) {
      int a, b, c;
      cin >> a >> b >> c;
      Add(a, b, c);
      Add(b, a, c);
    }

    For1(i, 1, n) { cin >> s[i]; }

    cout << dijkstra() << '\n';
  }

  return 0;
}
