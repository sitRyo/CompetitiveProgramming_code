#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int N, S,D;
  cin >> N >> S >> D;
  
  bool flag = false;
  for (int i = 0; i < N; ++i) {
    ll X,Y;
    cin >> X >> Y;
    if (X < S && Y > D) {
      flag = true;
    }
  }

  if (!flag) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}