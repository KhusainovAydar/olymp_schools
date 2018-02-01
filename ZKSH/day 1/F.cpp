#include <bits/stdc++.h>
#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define ll ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 50005, K = 500;

ll sz[NMAX], del[NMAX], maximum[NMAX];
ll cnt[NMAX];

int n;

void build() {
    for (int i = 0; i < NMAX; i++) {
        del[i] = 1;
        sz[i] = 0;
        maximum[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        sz[i / K] += cnt[i];
        maximum[i / K] = max(maximum[i / K], cnt[i]);
    }
}

void recalc(ll x) {
    sz[x] = 0;
    maximum[x] = 0;
    for (ll i = 0; i < K; i++) {
        if (x * K + i > n) break;
        cnt[x * K + i] *= del[x];
        sz[x] += cnt[x * K + i];
        maximum[x] = max(maximum[x], cnt[x * K + i]);
    }
    del[x] = 1;
}

pair<ll, ll> find_num(ll x) {
    int y = 0;
    for (int i = 0; i < NMAX; i++) {
        if (sz[i] * del[i] >= x) {
            y = i;
            break;
        }
        x -= sz[i] * del[i];
    }
    for (int i = 0; i < K; i++) {
        if (y * K + i > n) break;
        if (cnt[y * K + i] * del[y] >= x) {
            return {y * K + i, x};
        }
        x -= cnt[y * K + i] * del[y];
    }
}

void upd(ll l, ll r) {
    pair<ll, ll> L_pair = find_num(l);
    pair<ll, ll> R_pair = find_num(r);
    if (L_pair.fi / K == R_pair.fi / K) {
        recalc(L_pair.fi / K);

        if (L_pair.fi == R_pair.fi) {
            cnt[L_pair.fi] += R_pair.se - L_pair.se + 1;
            recalc(L_pair.fi / K);
            return;
        }

        cnt[L_pair.fi] += cnt[L_pair.fi] - L_pair.se + 1;
        cnt[R_pair.fi] += R_pair.se;
        for (ll i = L_pair.fi + 1; i < R_pair.fi; i++) {
            cnt[i] *= 2;
        }
        recalc(L_pair.fi / K);
        return;
    }
    recalc(L_pair.fi / K);
    recalc(R_pair.fi / K);

    cnt[L_pair.fi] += cnt[L_pair.fi] - L_pair.se + 1;
    cnt[R_pair.fi] += R_pair.se;
    for (ll i = L_pair.fi + 1; i <= n; i++) {
        if (i % K == 0) break;
        cnt[i] *= 2;
    }

    for (ll i = R_pair.fi / K * K; i < R_pair.fi; i++) {
        cnt[i] *= 2;
    }

    recalc(L_pair.fi / K);
    recalc(R_pair.fi / K);

    for (ll i = L_pair.fi / K + 1; i < R_pair.fi / K; i++) {
        del[i] *= 2;
    }
}

ll getmax(ll l, ll r) {
    ll maxx = 0;
    pair<ll, ll> L_pair = find_num(l);
    pair<ll, ll> R_pair = find_num(r);
    if (L_pair.fi / K == R_pair.fi / K) {
        recalc(L_pair.fi / K);

        if (L_pair.fi == R_pair.fi) {
            maxx = max(maxx, R_pair.se - L_pair.se + 1);
            return maxx;
        }

        maxx = max(maxx, cnt[L_pair.fi] - L_pair.se + 1);
        maxx = max(maxx, R_pair.se);
        for (ll i = L_pair.fi + 1; i < R_pair.fi; i++) {
            maxx = max(maxx, cnt[i]);
        }
        return maxx;
    }
    recalc(L_pair.fi / K);
    recalc(R_pair.fi / K);

    maxx = max(maxx, cnt[L_pair.fi] - L_pair.se + 1);
    maxx = max(maxx, R_pair.se);
    for (ll i = L_pair.fi + 1; i <= n; i++) {
        if (i % K == 0) break;
        maxx = max(maxx, cnt[i]);
    }

    for (ll i = R_pair.fi / K * K; i < R_pair.fi; i++) {
        maxx = max(maxx, cnt[i]);
    }

    for (ll i = L_pair.fi / K + 1; i < R_pair.fi / K; i++) {
        maxx = max(maxx, maximum[i] * del[i]);
    }
    return maxx;
}

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
    //    freopen("flow2.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int m;
        cin >> m;
        memset(cnt, 0, sizeof(cnt));

        for (int i = 1; i <= n; i++) {
            cnt[i] = 1;
        }
        build();
        for (int it = 0; it < m; it++) {
            char c;
            cin >> c;
            if (c == 'D') {
                ll l, r;
                cin >> l >> r;
                upd(l, r);
            } else {
                ll l, r;
                cin >> l >> r;
                ll ans = getmax(l, r);
                if (ans > 100000000) {
                    assert(false);
                }
                assert(ans <= (r - l + 1));
                cout << ans << endl;
            }
        }
    }
}
