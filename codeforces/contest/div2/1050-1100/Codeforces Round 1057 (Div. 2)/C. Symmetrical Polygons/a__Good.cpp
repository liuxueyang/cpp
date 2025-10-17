#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200'005;

int t;
int n;
int a[MAXN];
map<int, int> cnt;

int main() {
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif

  ios::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cnt.clear();

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
    }

    ll base = 0;
    vector<int> odd, even;
    for (auto [x, c] : cnt) {
      base += (ll)x * (c / 2);
      if (c % 2 == 1) {
        odd.push_back(x);
      } else if (c >= 2) {
        even.push_back(x);
      }
    }

    if (base == 0) {
      cout << 0 << '\n';
      continue;
    }

    ll ans = 0;
    for (int x : odd) {
      if (2 * base > x) {
        ans = max(ans, 2 * base + x);
      }
    }

    assert(is_sorted(odd.begin(), odd.end()));
    for (int i = 1; i < (int)odd.size(); i++) {
      if (odd[i - 1] + 2 * base > odd[i]) {
        ans = max(ans, odd[i - 1] + 2 * base + odd[i]);
      }
    }

    for (int x : even) {
      if (base - x > 0) {
        ans = max(ans, 2 * base);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
