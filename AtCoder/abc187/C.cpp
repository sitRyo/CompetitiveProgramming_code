#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  map<string, bool> hashMap1, hashMap2;
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    if (str[0] == '!') {
      auto s = str.substr(1);
      hashMap2[s] = true;
    } else {
      hashMap1[str] = true;
    }
  }

  for (auto itr : hashMap1) {
    if (hashMap2[itr.first]) {
      cout << itr.first << endl;
      return 0;
    }
  }

  cout << "satisfiable" << endl;
}