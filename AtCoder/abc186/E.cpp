#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll T;
  cin >> T;
  while (T--) {
    ll N, S, K;
    cin >> N >> S >> K;

    ll g = gcd(K, N);
    if (S % g > 0) {
      cout << -1 << endl;
      continue;
    } 

    N /= g;
    S /= g;
    K /= g;

    modint::set_mod(N);
    modint ans = -modint(S) / K;
    cout << ans.val() << endl;
  }
  
}