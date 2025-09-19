// https://ac.nowcoder.com/acm/discuss/blogs?tagId=108641

#include <iostream>
using namespace std;
const int mod = 9901;
typedef long long ll;

ll A, B, k = 0;
ll p[20005], n[20005];

ll fpow(ll p, ll n) {  // 快速幂
  ll res = 1;
  p %= mod;
  while (n) {
    if (n & 1) res = res * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return res;
}

ll sum(ll p, ll n) {  // 求约数和方程的每一项
  // 递归二分法求等比数列1+pi+pi^2+pi^3+...+pi^ni;
  //=(1+p+p^2+...+p^(n/2))*(1+p^(n/2+1))
  if (n == 0) return 1;  // 只有p^0这一项
  if (n % 2) {           // n为奇数
    return ((sum(p, n / 2) % mod) * (1 + fpow(p, n / 2 + 1))) % mod;
  } else {  // n为偶数
    return ((sum(p, n / 2 - 1) % mod) * (1 + fpow(p, n / 2 + 1)) % mod +
            fpow(p, n / 2)) %
           mod;
  }
}

signed main() {
#if defined(_DEBUG) && !defined(_CPH)
  freopen("input.txt", "r", stdin);
#endif

  while (cin >> A >> B) {
    k = 0;
    for (int i = 2; i * i <= A;) {  // 根号法+递归法
      if (A % i == 0) {             // 如果i是A的因子
        p[++k] = i;                 // 记录所有素因子
        n[k] = 0;
        while (!(A % i)) {
          n[k]++;  // 记录素因子的个数
          A /= i;
        }
      }
      if (i == 2)
        i++;  // 奇偶法，2以外的偶数并非素数
      else
        i += 2;  // 特判：分解整数A(A为质数)
    }
    if (A != 1) {
      p[++k] = A;
      n[k] = 1;
    }
    if (!A) {
      cout << 0 << endl;
      continue;
    }
    ll ans = 1;  // 约数和
    for (int i = 1; i <= k; i++) {
      ans = (ans * (sum(p[i], n[i] * B) % mod)) % mod;  // 约数和方程
      // n[i]*B可能会超过int，因此用long long
    }
    cout << ans << endl;  // 输出答案
  }
}
