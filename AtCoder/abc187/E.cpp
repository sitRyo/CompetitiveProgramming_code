#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int N;

#define int ll

void getDepth(vector<vector<int>> const& graph, int prev, int now, vector<int>& depth) {
  if (prev == -1) depth[now] = 0;
  for (auto it : graph[now]) {
    if (it == prev) continue;
    depth[it] = depth[now] + 1;
    getDepth(graph, now, it, depth);
  }
}

void sumWeight(vector<int>& ans, vector<int> const& weight, int W, int const now, int const prev, vector<vector<int>> const& G) {
  W += weight[now];
  ans[now] += W;
  for (auto to : G[now]) {
    if (to == prev) continue;
    sumWeight(ans, weight, W, to, now, G);
  }
}

signed main() {
  cin >> N;
  vector<vector<int>> graph(N);
  vector<pair<int, int>> edge(N);
  vector<int> depth(N);
  vector<int> weight1(N);
  vector<int> ans(N, 0);

  for (int i = 0; i < N-1; ++i) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    edge[i] = {a, b};
  }

  getDepth(graph, -1, 0, depth);

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; ++i) {
    int t,e,x;
    cin >> t >> e >> x;

    e--;

    int a = edge[e].first;
    int b = edge[e].second;
    if (t == 2) swap(a, b);
    int d1 = depth[a];
    int d2 = depth[b];
    
    if (d1 < d2) {
      weight1[0] += x;
      weight1[b] -= x;
    } else {
      weight1[a] += x;
    }
  }

  sumWeight(ans, weight1, 0, 0, -1, graph);

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << "\n";
  }
  cout << "\n";
}