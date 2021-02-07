#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> sum(N+1);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  for (int i = 0; i < N; ++i) {
    sum[i+1] = sum[i] + A[i];
  }
  
  ll ans = 0;
  for (int i = 1; i < N; ++i) {
    ans += (sum[N] - sum[i]) - (N-i) * A[i-1];
  }

  cout << ans << endl;
}