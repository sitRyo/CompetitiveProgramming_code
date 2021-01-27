#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  vector<int> X(M), Y(M);
  vector<int> dp(N, numeric_limits<int>::max());
  vector<vector<int>> graph(N);

  for (int i = 0; i < M; ++i) {
    cin >> X[i] >> Y[i];
    X[i]--, Y[i]--;
    graph[X[i]].push_back(Y[i]); // 有向グラフ
  }

  for (int i = 0; i < N; ++i) {
    for (auto to : graph[i]) {
      dp[to] = min<int>({A[i], dp[i], dp[to]});
    }
  }

  int ans = numeric_limits<int>::min();
  for (int i = 0; i < N; ++i) {
    ans = max(ans, A[i] - dp[i]);
  }

  cout << ans << endl;
}