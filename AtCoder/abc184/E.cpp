#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  ll H, W;
  int inf = numeric_limits<int>::max();
  vector<vector<pair<int,int>>> warp(30);
  vector<string> graph;
  pair<int, int> start, goal;

  cin >> H >> W;
  vector<vector<int>> dist(H, vector<int>(W, inf));
  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    graph.push_back(s);
    for (int j = 0; j < W; ++j) {
      if (s[j] == 'S') {
        start = {i, j};
      } else if (s[j] == 'G') {
        goal = {i, j};
      } else if (s[j] != '.' && s[j] != '#') {
        warp[s[j] - 'a'].push_back({i, j});
      }
    }
  }

  vector<bool> visited(30, false);

  using P = pair<int, int>;
  queue<P> que;
  que.push(start);
  dist[start.first][start.second] = 0;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    if (now == goal) {
      break;
    }

    int x = now.second;
    int y = now.first;
    int cost = dist[y][x] + 1;
    // cout << y << ' ' << x << endl;
    // 文字である
    if (graph[y][x] != 'S' && graph[y][x] != '.') {
      int idx = graph[y][x] - 'a';
      if (!visited[idx]) {
        int nx,ny;
        for (auto itr : warp[idx]) {
          nx = itr.second;
          ny = itr.first;
          if (dist[ny][nx] <= cost) {
            continue;
          }

          dist[ny][nx] = cost;
          que.push({ny, nx});
        }

        visited[idx] = true;
      }
    }

    for (int i = 0; i < 4; ++i) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      // cout << ny << ' ' << nx << ' ' << endl;
      if (nx >= 0 && nx < W && ny >= 0 && ny < H && graph[ny][nx] != '#' && dist[ny][nx] == inf) {
        dist[ny][nx] = cost;
        que.push({ny, nx});
      }
    }
  }

  // cout << inf << endl;
  if (dist[goal.first][goal.second] != inf) {
    cout << dist[goal.first][goal.second] << endl;
  } else {
    cout << -1 << endl;
  }
}