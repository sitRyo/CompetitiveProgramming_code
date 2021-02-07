#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll N,Q;
  cin >> N >> Q;
  vector<ll> A(N);
  ll digitMax = 31;
  vector<fenwick_tree<ll>> fw_array;
  for (int i = 0; i < digitMax; ++i) {
    fenwick_tree<ll> fw(N+1);
    fw_array.push_back(fw);
  }

  for (int i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    A[i] = a;
    for (int j = 0; j < digitMax; ++j) {
      int bit = (a >> j) & 1;
      fw_array[j].add(i, bit);
    }
  }

  for (int i = 0; i < Q; ++i) {
    ll t,x,y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      int idx = x;
      ll now = A[idx];

      for (int j = 0; j < digitMax; ++j) {
        int bit = (now >> j) & 1;
        fw_array[j].add(idx, -bit);
      }

      ll newElement = y xor A[idx];

      for (int j = 0; j < digitMax; ++j) {
        int bit = (newElement >> j) & 1;
        fw_array[j].add(idx, bit);
      }

      A[idx] = newElement;
    } else {
      x--;
      ll ans = 0;
      for (int j = 0; j < digitMax; ++j) {
        ll bit = fw_array[j].sum(x, y);
        if (bit % 2) {
          ans += (1 << j);
        }
      }

      cout << ans << endl;
    }
  }
}

// https://www.youtube.com/watch?v=xPum1B6dmfk&feature=youtu.be&ab_channel=AtCoderLive