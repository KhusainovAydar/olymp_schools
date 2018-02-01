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

using namespace std;

typedef long long ll;

const int NMAX = (const int) (1e5 + 5);

ll dp[61], c[61];

ll proc(ll x) {
    int n = 0;
    for (int i = 0; i < 61; i++) {
        if (((x >> i) & 1))
            n = i;
    }
    n++;
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        if ((x >> (i - 1)) & 1) {
            c[i] = c[i - 1] + (1ll << (i - 1));
        } else {
            c[i] = c[i - 1];
        }
    }
    dp[0] = 1;
    if ((x & 1))
        dp[1] = 1;
    else
        dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if ((x >> (i - 1)) & 1) {
            ll a;
            if (i == 2) a = 1;
            else a = 0;
            dp[i] = (a ^ (dp[i - 1] ^ (c[i - 1] % 2 * (1ll << (i - 1)))));
        } else {
            dp[i] = dp[i - 1];
        }
    }
//    for (int i = 0; i <= n; i++) {
//        cerr << dp[i] << ' ';
//    }
//    cerr << endl;
    return dp[n];
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector< pair<ll, ll> > v((unsigned long) n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        ans ^= (proc(v[i].se) ^ (proc(v[i].fi - 1)));
    }
    if (ans == 0) {
        cout << "Lose";
        return 0;
    }
    cout << "Win" << endl;
    //cerr << ans;
    int k = 0;
    for (int i = 0; i < 61; i++) {
        if ((ans >> i) & 1)
            k = i;
    }
    for (int i = 0; i < n; i++) {
        ll L = 0, R = (ll) ((2e18 - (1ll << k)) / (1ll << (k + 1)));
        while (R - L > 1) {
            ll M = (L + R) >> 1;
            if ((1ll << k) + (1ll << (k + 1)) * M <= v[i].se)
                L = M;
            else
                R = M;
        }
        L = (1ll << k) + (1ll << (k + 1)) * L;
        if (L >= v[i].fi && L <= v[i].se) {
            cout << L << ' ' << (ans ^ L);
            return 0;
        }
        L = 0, R = (ll) ((2e18 - (1ll << k)) / (1ll << (k + 1)));
        while (R - L > 1) {
            ll M = (L + R) >> 1;
            if ((1ll << k) + (1ll << (k + 1)) * M < v[i].fi)
                L = M;
            else
                R = M;
        }
        L = (1ll << k) + (1ll << (k + 1)) * L;
        //cerr << L << endl;
        if (v[i].fi - L < (1ll << (k)) && L < v[i].fi) {
            cout << v[i].fi << ' ' << (ans ^ v[i].fi);
            return 0;
        }
    }
}