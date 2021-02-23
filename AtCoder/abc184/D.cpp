#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
using ld = long double;
constexpr ll mod = 1e9 + 7;

int main() {
  cout << fixed << setprecision(12);
  // ld e1 = (98.0 / (98.0+99.0+99.0));
  // ld e2 = (99.0 / (99.0+99.0+99.0));
  // cout << (e1 + e2 * 3.0) << endl;

  ld A,B,C;
  cin >> A >> B >> C;

  ld ans = 0.0;
  for (int a = A; a < 100; ++a) {
    for (int b = B; b < 100; ++b) {
      for (int c = C; c < 100; ++c) {
        ans += (ld) a / (ld) (a + b + c);
      }
    }
  }

  cout << ans << endl;
}