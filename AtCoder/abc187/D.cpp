#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  ll N,X = 0;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    ll a, b;
    cin >> a >> b;
    A[i] = 2 * a + b;
    X -= a;
  }

  sort(A.begin(), A.end(), greater<ll>());

  int ans = 0;

  for (int i = 0; i < N; ++i) {
    X += A[i];
    ans ++;
    if (X > 0) {
      break;
    }
  }

  cout << ans << endl;
}