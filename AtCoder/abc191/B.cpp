#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll N,X;
  cin >> N >> X;
  vector<ll> A(N), ans;
  
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] != X) ans.push_back(A[i]);
  }

  for (auto itr : ans) {
    cout << itr << ' ';
  }
  cout << endl;
}