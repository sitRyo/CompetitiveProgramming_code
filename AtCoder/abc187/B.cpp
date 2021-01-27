#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  int N;
  cin >> N;
  vector<pair<double, double>> c(N);
  for (int i = 0; i < N; ++i) {
    double a, b;
    cin >> a >> b;
    c[i] = {a, b};
  }

  int ans = 0;
  for (int i = 0; i < N-1; ++i) {
    for (int j = i+1; j < N; ++j) {
      auto p1 = c[i];
      auto p2 = c[j];
      double m = (p2.second - p1.second) / (p2.first - p1.first);

      if (m >= -1.0 && m <= 1.0) {
        ans ++;
      }
    }
  }

  cout << ans << endl;
}