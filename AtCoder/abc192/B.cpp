#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  string str;
  cin >> str;
  bool flag = true;
  for (int i = 1; i <= str.size(); ++i) {
    if (i % 2 == 0) {
      // 偶数
      if (!isupper(str[i-1])) {
        flag = false;
      }
    } else {
      // 奇数
      if (isupper(str[i-1])) {
        flag = false;
      }
    }
  }

  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}