#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

// 約数の列挙
/*
 * 2, 4, 8 ... 的な
 */
template<typename T>
set<T> div_count(T x) {
  set<T> st;
  for (long long i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      st.insert(i);
      st.insert(x/i);
    }
  }
  return st;
}

int main() {
  ll N, ans = 0;
  cin >> N;

  N = 2*N;
  auto st = div_count(N);
  for (auto n : st) {
    ll t = N / n;
    if ((t - n) % 2) ans += 1;
  }
  cout << ans << endl;
}