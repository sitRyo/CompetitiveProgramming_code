#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  string str;
  cin >> str;

  int l = 0, r = N-1;
  int ans = 0;
  while (l < r) {
    if (str[l] == 'W') {
      while (l < r) {
        if (str[r] == 'R') {
          ans += 1;
          break;
        }
        r--;
      }

      r--;
    }

    l++;
  }

  cout << ans << endl;
}