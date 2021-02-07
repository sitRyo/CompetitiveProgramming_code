#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<int>> blocks(H, vector<int>(W));

  int mmin = 1000000;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> blocks[i][j];
      if (blocks[i][j] < mmin) {
        mmin = blocks[i][j];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      ans += abs(blocks[i][j] - mmin);
    }
  }

  cout << ans << endl;
}