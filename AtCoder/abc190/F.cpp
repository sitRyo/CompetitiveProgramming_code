#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  B = A;
  sort(A.begin(), A.end());
  map<ll, ll> index;
  int cnt = 1;
  for (auto n : A) {
    index[n] = cnt++;
  }
  
  fenwick_tree<ll> fw(N+2);
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    ll val = B[i];
    ll idx = index[val];
    res += i - fw.sum(0, idx);
    fw.add(idx, 1);
  }

  cout << res << endl;

  for (int i = 0; i < N-1; ++i) {
    res -= B[i];
    res += N - 1 - B[i];
    cout << res << endl;
  }
}