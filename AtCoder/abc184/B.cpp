#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int N, X;
  cin >> N >> X;

  while (N--) {
    char t;
    cin >> t;
    if (t == 'o') {
      X = X + 1;
    } else {
      X = max(0, X - 1);
    }
  }

  cout << X << endl;
}