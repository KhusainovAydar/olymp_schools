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

pair<ll, ll> ans(ll r1, ll r2, ll m1, ll m2) {
    ll d = __gcd(m1, m2);
    m1 /= d;
    m2 /= d;
    if ((r2 - r1) % d != 0) {
        return {-1, -1};
    }
    ll k = (r2 - r1) * mod(m1, m2) * d;
    ll x = r1 + m1 * k;
    while (x < 0)
        x += m1 * m2 * d;
    x %= m1 * m2 * d;
    return {x, m1 * m2 * d};
}



int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n, m, x, y;
        cin >> a >> b >> n >> m;
        while (a < 0) {
            a += n;
        }
        while (b < 0) {
            b += m;
        }
        if (n < m) {
            swap(n, m);
            swap(a, b);
        }
        ll gc = __gcd(max(n, m), min(n, m));
        if ((b - a) % gc != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES ";
        ll n2 = n / gc;
        ll m2 = m / gc;
        ll r2 = gcd(n2, m2, x, y);
        r2++;
        x *= (b - a);
        y *= (b - a);
        x /= gc;
        y /= gc;
        ll ans = n * x + a;
        while (ans < 0) {
            ans += (n * m / gc);
        }
        cout << ans % (n * m / gc) << " " << n * m / gc << endl;
    }
    return 0;
}