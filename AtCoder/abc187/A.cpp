#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  string a,b;
  cin >> a >> b;
  int total = 0;
  for (auto itr : a) {
    total += itr - '0';
  }

  int p = 0;
  for (auto itr : b) {
    p += itr - '0';
  }

  cout << ((total > p) ? total : p) << endl;
}