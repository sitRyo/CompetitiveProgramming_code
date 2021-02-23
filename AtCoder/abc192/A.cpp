#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int X;
  cin >> X;
  X = X % 100;
  cout << 100 - X << endl;
}