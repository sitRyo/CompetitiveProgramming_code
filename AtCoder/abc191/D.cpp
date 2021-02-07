#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using ll = long long int;
constexpr ll mod = 1e9 + 7;

int main() {
  long double X, Y, R;
  cin >> X >> Y >> R;
  ll start, end;

  ll ans = 0;

  long double intStart = (ll)(X - R);
  long double intEnd = (ll)(X + R);

  if (intStart == X - R) {
    start = intStart;
  } else {
    if (X - R < 0.0) {
    start = ceil(X - R);
    } else {
      start = floor(X - R);
    }
  }  
  
  if (intEnd == X + R) { 
    end = intEnd;
  } else {
    if (X + R < 0.0) {
        end = ceil(X + R);
      } else {
        end = floor(X + R);
    }
  }


  for (int i = start; i <= end; ++i) {
    long double p = sqrtl(pow(R, 2) - pow((X - (long double)i), 2));

    ll top, bottom;

    long double intTop = (ll)(Y + p);
    long double intBottom = (ll)(Y - p);

    if (intTop == Y + p) {
      top = intTop;
    } else {
      if (Y + p < 0.0) {
        top = ceil(Y + p);
      } else {
        top = floor(Y + p);
      }
    }

    
    // cout << intTop << ' ' << intBottom << endl;
    // cout << Y+p << ' ' << Y - p << endl;

    if (intBottom == Y - p) {
      bottom = intBottom;
    } else {
      if (Y - p < 0.0) {
        bottom = ceil(Y - p);
      } else {
        bottom = floor(Y - p + 1.0);
      }
    }
    

    // cout << "top bottom" << endl;
    // cout << top << ' ' << bottom << endl;

    ans += top - bottom + 1;
  }

  cout << ans << endl;
}