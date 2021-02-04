#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  string s;
  vector<vector<ll>> dp(N+2, vector<ll>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = 1;
  ll ans = 1LL << N+1;
  ll cnt = 1;
  for (int i = 0; i < N; ++i) {
    cin >> s;
    if (s == "AND") {
      dp[i+1][0] = dp[i][1] + dp[i][0] * 2;
      dp[i+1][1] = dp[i][1];
    } else {
      dp[i+1][1] = dp[i][1] * 2 + dp[i][0];
      dp[i+1][0] = dp[i][0];
    }
  }
  
  cout << dp[N][1] << endl;
}