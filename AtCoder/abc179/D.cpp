#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 998244353;

using mint = modint998244353;
using S = mint;
using F = mint;

S INF = numeric_limits<int>::max();

S op(S a, S b){ return a; }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  ll N, K;
  cin >> N >> K;
  vector<pair<ll,ll>> Range;
  for (int i = 0; i < K; ++i) {
    ll l, r;
    cin >> l >> r;
    Range.push_back({l, r+1});
  }

  std::vector<S> v(N);
  v[0] = 1;
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  for (int i = 0; i < N-1; ++i) {
    mint now = seg.get(i);
    for (int j = 0; j < K; ++j) {
      int l = Range[j].first + i, r = min(Range[j].second + i, N);
      if (l >= N) continue;
      seg.apply(l, r, now);
    }
  }

  cout << seg.get(N-1).val() << endl;
}