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

  // nが奇数
  ll P = N;
  auto st = div_count(P);
  for (auto it : st) {
      ans += 2;
    }
  }

  // nが偶数
  P = N - 1;
  st = div_count(P);
  for (auto it : st) {
    if (it % 2 == 0) {
      ans += 2;
    }
  }

  cout << ans << endl;
}