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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll proc(ll a, ll b, ll mod) {
    if (b == 0)
        return 0;
    if (b & 1) {
        return ((proc(a, b - 1, mod) + a) % mod);
    } else {
        return ((proc(a, b / 2, mod) * 2) % mod);
    }
}

ll binpow(ll a, ll n, ll mod) {
    if (n == 0) {
        return 1;
    }
    if (n & 1) {
        return proc(binpow(a, n - 1, mod), a, mod);
    } else {
        ll b = binpow(a, n / 2, mod);
        return proc(b, b, mod);
    }
}

bool miller_rabin(ll n) {
    ll b = rand();
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;

    if (b < 2)
        b = 2;

    for (ll g; (g = gcd(n, b)) != 1; ++b)
        if (n > g)
            return false;

    ll n_1 = n;
    --n_1;
    ll p = 0, q = n_1;
    while (q % 2 == 0) {
        q >>= 1;
        p++;
    }

    ll rem = binpow(b, q, n);
    if (rem == 1 || rem == n_1)
        return true;

    for (ll i = 1; i < p; i++) {
        rem = proc(rem, rem, n);
        if (rem == n_1)
            return true;
    }
    return false;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
#endif
    ll x;
    cin >> x;
    bool ch = true;
    for (int i = 0; i < 100; i++) {
        ch = (ch && miller_rabin(x));
    }
    if (ch) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}