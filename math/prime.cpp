#include <bits/stdc++.h>
#define EPS 1e-7

using namespace std;

typedef long long LL;

bool IsPrimeSlow (LL x)
{
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  LL s = (long long)(sqrt((double)(x))+EPS);
  for(LL i=5;i<=s;i+=6)
  {
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    LL n;
    while (cin >> n) {
        if (kek(n)) {
            cout << "Yes" << '\n';
        } else cout << "No" << '\n';
        return 0;
    }
}
