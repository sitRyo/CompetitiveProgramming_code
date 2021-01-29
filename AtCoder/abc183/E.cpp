#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll H, W;
  cin >> H >> W;

  vector<string> mp;
  string s;
  for (int i = 0; i < W+1; ++i) {
    s.push_back('#');
  }
  mp.push_back(s);

  for (int i = 0; i < H; ++i) {
    cin >> s;
    s = '#' + s;
    mp.push_back(s);
  }

  vector<vector<ll>> dp(H+1, vector<ll>(W+1));
  vector<vector<ll>> X(H+1, vector<ll>(W+1));
  vector<vector<ll>> Y(H+1, vector<ll>(W+1));
  vector<vector<ll>> Z(H+1, vector<ll>(W+1));

  dp[1][1] = 1;
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      if (i == 1 && j == 1) continue;
      if (mp[i][j] == '#') continue;

      X[i][j] = (X[i][j-1] + dp[i][j-1]) % mod;
      Y[i][j] = (Y[i-1][j] + dp[i-1][j]) % mod;
      Z[i][j] = (Z[i-1][j-1] + dp[i-1][j-1]) % mod;
      dp[i][j] = (X[i][j] + Y[i][j] + Z[i][j]) % mod;
    }
  }

  cout << dp[H][W] << endl;
}