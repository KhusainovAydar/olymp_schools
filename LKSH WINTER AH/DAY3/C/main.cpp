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

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll mod(ll a, ll n) {
    ll x = 0, y = 1;
    ll g = gcd(a, n, x, y);
    if (g != 1) {
        return -1;
    } else {
        return ((x % n + n) % n);
    }
}

ll ans(ll r1, ll r2, ll m1, ll m2) {
    ll k = (r2 - r1) * mod(m1, m2);
    ll x = r1 + m1 * k;
    return x;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("chine.in", "r", stdin);
    freopen("chine.out", "w", stdout);
#endif
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    ll x = ans(a, b, n, m);
    while (x < 0) {
        x += n * m;
    }
    cout << x % (n * m);
}