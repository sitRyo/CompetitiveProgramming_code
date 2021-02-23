#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

struct Edge {
  ll to;
  ll cost;
  ll interval;
};

int main() {
  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<vector<Edge>> G(N+1);
  for (int i = 0; i < M; ++i) {
    ll A, B, T, K;
    cin >> A >> B >> T >> K;
    G[A].push_back({B, T, K});
    G[B].push_back({A, T, K});
  }

  ll inf = numeric_limits<ll>::max();
  vector<ll> dis(N+1, inf);
  dis[X] = 0;
  using P = pair<ll, ll>;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.emplace(dis[X], X);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {
      continue;
    }

    ll nowCost = dis[v];
    // cout << "v " << v << " cost " << nowCost << endl;
    for (auto &e : G[v]) {
      // cout << "to " << e.to << " Time " << e.cost << " interval " << e.interval << " ";
      ll rem = e.interval - (nowCost % e.interval);
      if (rem == e.interval) {
        rem = 0;
      }
      // cout << "rem " << rem << endl;
      ll cost = rem + e.cost;
      if (dis[e.to] > dis[v] + cost) {
        dis[e.to] = dis[v] + cost;
        pq.emplace(dis[e.to], e.to);
      }
    }
  }

  if (dis[Y] == inf) {
    cout << -1 << endl;
  } else {
    cout << dis[Y] << endl;
  }
}