#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;

const int NMAX = 1e6 + 60;

ll f[NMAX];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
#endif
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < NMAX; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
    }
    a++, b++;
    cout << f[__gcd(a, b) - 1];
}