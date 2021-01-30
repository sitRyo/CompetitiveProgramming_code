#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  for (int i = 0; i < 100; ++i) {
    if (c == 0) {
      a -= 1;
      if (a < 0) {
        cout << "Aoki" << endl;
        break;
      }

      b -= 1;
      if (b < 0) {
        cout << "Takahashi" << endl;
        break;
      }
    } else {
      b -= 1;
      if (b < 0) {
        cout << "Takahashi" << endl;
        break;
      }

      a -= 1;
      if (a < 0) {
        cout << "Aoki" << endl;
        break;
      }
    }
  }
}