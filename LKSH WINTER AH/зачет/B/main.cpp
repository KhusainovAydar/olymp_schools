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

ll n;
vector<ll> a;
ll g = 5, G = 5;
ll mod = 4066273;

ll power(ll x, ll n) {
    if (n == 0) {
        return 1;
    }
    if ((n & 1)) {
        ll y = power(x, n - 1) * x;
        y %= mod;
        return y;
    } else {
        ll b = power(x, n / 2);
        ll y = b * b;
        y %= mod;
        return y;
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("notfft.in", "r", stdin);
    freopen("notfft.out", "w", stdout);
#endif
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (ll i = 1; i < n; i++) {
        ll G = power(g, i) - 1;
        if (G < 0)
            G += mod;
        ll y = power(g, i * n) - 1;
        if (y < 0)
            y += mod;
        G = power(G, mod - 2);
        ans = (ans + (a[i] * ((y * G) % mod)) % mod) % mod;
    }
    ans = (ans + (a[0] * n) % mod) % mod;
    cout << ans;
}