#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int N,M,K;
  cin >> N >> M;

  vector<int> A(M+10), B(M+10);
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }

  cin >> K;
  vector<int> C(K+10), D(K+10);
  for (int i = 0; i < K; ++i) {
    cin >> C[i] >> D[i];
    C[i]--, D[i]--;
  }

  int ans = -1;
  for (int i = 0; i < (1 << K); ++i) {
    vector<int> dish(N+10, 0);
    int p = i;
    
    for (int j = 0; j < K; ++j) {
      int t = (p >> j) & 1;
      if (t == 0) dish[C[j]] = 1;
      else dish[D[j]] = 1;
    }
    int res = 0;
    for (int j = 0; j < M; ++j) {
      int a = A[j];
      int b = B[j];

      if (dish[a] && dish[b]) {
        res += 1;
      }
    }

    if (res > ans) {
      ans = res;
    }
  }

  cout << ans << endl;
}