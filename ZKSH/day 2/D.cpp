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

int cnt[505][505];
int cur[505];

ll crossmul(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - a.se * b.fi;
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector< pair<ll, ll> > a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].fi >> b[i].se;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            for (int y = 0; y < m; y++) {
                pair<ll, ll> p1 = a[i], p2 = a[j];
                if (p1.fi > p2.fi) {
                    swap(p1, p2);
                }
                if (b[y].fi < p1.fi || b[y].fi > p2.fi) continue;
                if (p1.fi == p2.fi) {
                    if (b[y].se <= p1.se || b[y].se <= p2.se) {
                        cnt[i][j]++;
                        cnt[j][i]++;
                    }
                    continue;
                }
                pair<ll, ll> v1 = {p2.fi - p1.fi, p2.se - p1.se};
                pair<ll, ll> v2 = {b[y].fi - p1.fi, b[y].se - p1.se};
                if (crossmul(v1, v2) <= 0) {
                    cnt[i][j]++;
                    cnt[j][i]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i].fi == b[j].fi && b[j].se < a[i].se) {
                cur[i]++;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            for (int y = j + 1; y < n; y++) {
                int pos1 = i, pos2 = j, pos3 = y;
                if (a[pos1].fi > a[pos2].fi) {
                    swap(pos1, pos2);
                }
                if (a[pos1].fi > a[pos3].fi) {
                    swap(pos1, pos3);
                }
                if (a[pos2].fi > a[pos3].fi) {
                    swap(pos2, pos3);
                }
//                cerr << cnt[pos1][pos3] << ' ' << cnt[pos1][pos2] << ' ' << cnt[pos2][pos3] << ' ' << cur[pos2] << endl;
                if (cnt[pos1][pos3] == cnt[pos1][pos2] + cnt[pos2][pos3] - cur[pos2]) {
//                    cout << a[pos1].fi << ' ' << a[pos1].se << endl;
//                    cout << a[pos2].fi << ' ' << a[pos2].se << endl;
//                    cout << a[pos3].fi << ' ' << a[pos3].se << endl;
//                    cout << endl;
                    ans++;
                }
            }
        }
    }

    cout << ans;
}