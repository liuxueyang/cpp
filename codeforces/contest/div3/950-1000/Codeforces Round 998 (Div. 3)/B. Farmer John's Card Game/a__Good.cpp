#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

void tc() {
  ll n, m;
  cin >> n >> m;
  vector<vll> ve(n, vll(m));
  vll p(n, -16);
  bool val = true;
  ll c = 0;
  for (vll &we : ve) {
    for (ll &i : we) cin >> i;
    ll minN = *min_element(we.begin(), we.end());
    if (minN < n) p[minN] = c++;
    val &= minN < n;
    sort(we.begin(), we.end());
    ll last = we[0] - n;
    for (ll i : we) {
      val &= last + n == i;
      last = i;
    }
  }
  if (!val) {
    cout << "-1\n";
    return;
  }
  for (ll i : p) cout << i + 1 << ' ';
  cout << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    tc();
  }
  return 0;
}
