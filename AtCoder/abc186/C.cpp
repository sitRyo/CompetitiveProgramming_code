#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int N;
  cin >> N; 

  auto check = [](int digit, int n) {
    while (n > 0) {
      int d = n % digit;
      if (d == 7) {
        return false;
      }
      n /= digit;
    }

    return true;
  };

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (check(10, i) && check(8, i)) {
      ans += 1;
    }
  }

  cout << ans << endl;
}