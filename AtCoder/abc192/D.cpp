#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  string X;
  ll M;
  cin >> X >> M;
  string cpy = X;
  sort(cpy.begin(), cpy.end());
  ll b = cpy.back() - '0';

  // reverse(X.begin(), X.end());
  if (X.size() == 1) {
    int p = stoi(X);
    if (p > M) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }

    return 0;
  }
  
  // 二分探索
  using bint = __int128_t;
  ll ac = b;
  ll wa = M + 1;
  bint m = M;
  while (ac + 1 < wa) {
    bint wj = (ac + wa) / 2;
    bint v = 0;
    for (auto c : X) {
      if (v > m) {
        v = M+1;
        break;
      }
      v = wj * v + (c - '0');
    }

    if (v <= m) {
      ac = wj;
    } else {
      wa = wj;
    }
  }

  // cout << ac << endl;
  cout << ac - b << endl;
}