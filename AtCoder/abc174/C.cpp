#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll K;
  cin >> K;

  ll n = 7 % K;
  set<ll> s;
  int ans = 1;
  while (s.count(n) == 0) {
    if (n == 0) {
      cout << ans << endl;
      return 0; 
    }

    s.insert(n);
    n = (n * 10 + 7) % K;
    ans += 1;
  }

  cout << -1 << endl;
}