#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  string N;
  ll K;
  cin >> N;
  cin >> K;

  for (int i = 0; i < K; ++i) {
    string s1 = N;
    string s2 = N;

    sort(s1.begin(), s1.end(), greater<>());
    sort(s2.begin(), s2.end());

    ll g1 = stol(s1);
    ll g2 = stol(s2);
    ll f = g1 - g2;
    N = to_string(f);
  }

  cout << N << endl;
}