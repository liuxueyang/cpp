#pragma GCC optimize(4)

#include <iostream>
#include <vector>

using namespace std;

const int N = 6e4 * 2 + 10;

int primes[N], cnt;
bool st[N];
int sum[N];

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

int get(int n, int p) {
  int res = 0;
  while (n) {
    res += n / p;
    n /= p;
  }
  return res;
}

void mul(vector<int>& a, int b) {
  int t = 0;
  for (int i = 0; i < a.size(); i++) {
    t += a[i] * b;
    a[i] = t % 10000;
    t /= 10000;
  }

  while (t) {
    a.push_back(t % 10000);
    t /= 10000;
  }
}

int main() {
#if defined(_DEBUG) && !defined(_CPH) && !defined(_SUB)
  freopen("input.txt", "r", stdin);
#endif

  int n;
  cin >> n;
  int a = 2 * n, b = n;

  get_primes(a);

  for (int i = 0; i < cnt; i++) {
    int p = primes[i];
    sum[i] = get(a, p) - get(b, p) - get(a - b + 1, p);
  }

  vector<int> res;
  res.push_back(1);

  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < sum[i]; j++) mul(res, primes[i]);

  cout << res.back();
  for (int i = res.size() - 2; i >= 0; i--) printf("%04d", res[i]);

  return 0;
}

// 作者：目目目
// 链接：https://www.acwing.com/solution/content/103826/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。