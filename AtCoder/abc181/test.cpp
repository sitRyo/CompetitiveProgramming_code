#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A {2, 3, 5, 7, 9};
  int it = lower_bound(A.begin(), A.end(), 9) - A.begin();
  cout << it << endl;
}