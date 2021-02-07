#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll V,T,S,D;
  cin >> V >> T >> S >> D;

  ll l = V * T;
  ll r = V * S;

  if (D < l || r < D) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}