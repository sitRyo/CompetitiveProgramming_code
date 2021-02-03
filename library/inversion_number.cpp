/**
 * 転倒数
 * BITのrange sum queryを使って, 自分より小さい数を数える
 */


// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;


using ll = long long int;
constexpr ll mod = 1e9 + 7;

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T> struct fenwick_tree {
    using U = T;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  B = A;
  
  sort(A.begin(), A.end());

  map<ll, ll> mp;
  ll cnt = 1;
  for (auto val : A) {
    mp[val] = cnt++;
  }

  fenwick_tree<ll> ft(N+2);
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    ll idx = mp[B[i]];
    ll total = ft.sum(0, idx);
    ans += i - total;
    ft.add(idx, 1);
  }

  cout << ans << endl;
}