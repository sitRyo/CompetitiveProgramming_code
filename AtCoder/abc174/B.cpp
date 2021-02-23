#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int N, D;
  cin >> N >> D;
  using ld = long double;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ld a,b;
    cin >> a >> b;
    ld d = sqrtl(powl(a, 2) + powl(b, 2));
    if (d <= D) {
      ans += 1;
    }
  }
  cout << ans << endl;
}