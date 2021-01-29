#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;

int main() {
  ll N,X,M;
  cin >> N >> X >> M;

  ll an = X;
  
  map<ll, ll> hashMap;
  hashMap[an] = 1;  
  
  vector<ll> A {X};
  ll start = 1, finish = N;
  for (ll i = 2; i <= N; ++i) {
    ll anp = (an * an) % M;
    if (hashMap[anp] > 0) {
      start = hashMap[anp];
      finish = i - 1;
      break;
    }
    hashMap[anp] = i;
    an = anp;
    A.push_back(an);
  }

  ll remain = start - 1;
  ll lenLoop = finish - start + 1;
  ll lenAll = N - remain;
  ll loopCount = lenAll / lenLoop;
  ll lenAfterLoop = lenAll % lenLoop;

  ll sumLoop = 0;
  ll sumRemain = 0;
  ll sumAfterLoop = 0;
  for (ll i = start - 1; i < finish; ++i) {
    sumLoop += A[i];
  }

  for (ll i = 0; i < start - 1; ++i) {
    sumRemain += A[i];
  }

  for (ll i = start - 1; i < lenAfterLoop; ++i) {
    sumAfterLoop += A[i];
  }

  cout << sumRemain +  sumAfterLoop + (sumLoop * loopCount)<< endl;
}