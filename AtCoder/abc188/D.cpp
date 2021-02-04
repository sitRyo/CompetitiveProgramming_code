#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll N, C;
  cin >> N >> C;
  vector<ll> a(N), b(N), c(N);
  vector<pair<ll, ll>> imos, imos_new;
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    imos.push_back({a[i], c[i]});
    imos.push_back({b[i], -c[i]});
  }
  
  sort(imos.begin(), imos.end());
  
  auto pre = imos.front();
  auto tmp = imos.front();
  for (int i = 1; i < imos.size(); ++i) {
    auto now = imos[i];
    if (pre.first == now.first) {
      tmp.second += now.second;
    } else {
      imos_new.push_back(tmp);
      tmp = now;
    }
    pre = now;
  }

  imos_new.push_back(tmp);

  sort(imos_new.begin(), imos_new.end());

  ll ans = 0;
  ll sum = 0;
  for (int i = 0; i < imos_new.size() - 1; ++i) {
    auto now = imos_new[i];
    auto next = imos_new[i+1];
    auto interval = next.first - now.first;
    sum += now.second;
    if (sum > C) {
      ans += C * interval;
    } else {
      ans += sum * interval;
    }
  }

  cout << ans << endl;
}