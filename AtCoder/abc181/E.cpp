#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  ll N,M;
  cin >> N >> M;
  vector<ll> H(N), W(M);

  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }

  for (int i = 0; i < M; ++i) {
    cin >> W[i];
  }

  sort(H.begin(), H.end());
  sort(W.begin(), W.end());

  vector<ll> left(N+1), right(N+1);

  for (int i = 2; i < N; i += 2) {
    int idx = i - 1;
    left[i] = left[i-2] + H[idx] - H[idx - 1];
  }

  for (int i = 2; i < N; i += 2) {
    int idx = N - i;
    right[i] = right[i-2] + H[idx + 1] - H[idx];
  }

  ll ans = numeric_limits<ll>::max();
  for (int i = 0; i < M; ++i) {
    int idx = lower_bound(H.begin(), H.end(), W[i]) - H.begin();
    if (idx % 2 == 0) {
      ans = min(ans, left[idx] + right[N - 1 - idx] + H[idx] - W[i]);
    } else {
      ans = min(ans, left[idx-1] + right[N-idx] + W[i] - H[idx - 1]);
    }
  }

  cout << ans << endl;
}