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
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("substr3.in", "r", stdin);
//    freopen("substr3.out", "w", stdout);
#endif
    ll n, m, k;
    cin >> n >> m >> k;

    ll a, b, c;
    cin >> a >> b >> c;

    ll T;
    cin >> T;

    vector<ll> v(m);

    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    k -= m;
    set< pair<ll, ll> > s;
    for (int i = 0; i < m; i++) {
        s.insert({v[i], (v[i] - 1) * b});
    }

    for (int i = 0; i < k; i++) {
        set< pair<ll, ll> >::iterator r = s.begin();
        set< pair<ll, pair<ll, ll> > > mn;
        while (r != s.end()) {
            if (r == s.begin()) {
                r++;
            }
            set< pair<ll, ll> >::iterator l = r;
            --l;
            ll x1 = l->fi, val1 = l->se;
            ll x2 = r->fi, val2 = r->se;

            ll val = x2 - x1;
            if (val * a + val1 <= T || val < 2) {
                ++r;
                continue;
            }

            ll cop = T;
            cop -= val1;
            cop = max(0ll, cop);
            ll x3 = x1 + cop / a + 1;
            ll cnt = 1;
            if (x3 >= x2) {
                ++r;
                continue;
            }

            ll val3 = val1 + (x3 - x1) * c;
            if (val3 > T) {
                ++r;
                continue;
            }

            cop = T;
            cop -= val3;
            cop = max(cop, 0ll);
            cnt += cop / a;
            cnt = min(x2 - x3, cnt);

            mn.insert({-cnt, {x3, val3}});
            ++r;
        }
        if (mn.empty()) continue;
        auto q = mn.begin();
        ll cnt = q->fi;
        ll x = q->se.fi;
        ll val = q->se.se;
        s.insert({x, val});
    }
    ll ans = 0;
    set< pair<ll, ll> >::iterator r = s.begin();
    while (r != s.end()) {
        if (r == s.begin()) {
            ++r;
        }
        set< pair<ll, ll> >::iterator l = r;
        if (r->se <= T) {
            ans++;
        }
        --l;
        ll cop = max(0ll, T);
        cop -= l->se;
        cop = max(0ll, cop);
        ans += min(cop / a, max(0ll, r->fi - l->fi - 1));
        ++r;
    }
    cout << ans;
}