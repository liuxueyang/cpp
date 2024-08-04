#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    ll k;
    cin >> n >> k;
    ll max_s = 0;
    for (int i = 0; i < n; i++)
      max_s += abs(n - 1 - i - i);
    if (k % 2 != 0 || k > max_s) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      vector<int> p(n);
      k /= 2;
      iota(p.begin(), p.end(), 0);
      for (int i = 0; k > 0; i++) {
        if (k >= n - 1 - 2 * i) {
          swap(p[i], p[n - 1 - i]);
          k -= n - 1 - 2 * i;
        } else {
          swap(p[i], p[i + k]);
          k = 0;
        }
      }
      for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
      }
      cout << "\n";
    }
  }
}
