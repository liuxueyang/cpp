#include <bits/stdc++.h>

using namespace std;

const int LOGN = 20;

vector<vector<int>> stGCD;

int get_gcd(int l, int r) {
  int k = __lg(r - l + 1);
  return __gcd(stGCD[k][l], stGCD[k][r - (1 << k) + 1]);
}

void solve() {
  stGCD.clear();
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  vector<int> b;
  for (int i = 1; i < n; i++) b.push_back(abs(a[i - 1] - a[i]));

  stGCD.resize(LOGN, vector<int>(b.size(), 1));
  for (int i = 0; i < b.size(); i++) stGCD[0][i] = b[i];
  for (int i = 1; i < LOGN; i++)
    for (int j = 0; j + (1 << (i - 1)) < b.size(); j++)
      stGCD[i][j] = __gcd(stGCD[i - 1][j], stGCD[i - 1][j + (1 << (i - 1))]);

  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << " ";
      continue;
    }
    l--;
    r -= 2;
    int gcd = get_gcd(l, r);
    cout << gcd << " ";
  }
}

int main() {
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS-- > 0) {
    solve();
    cout << "\n";
  }
  return 0;
}