#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
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

const int NMAX = 100005;

int n, m;
ll d[2][NMAX];
ll sum[NMAX];

struct node {
    int a, b, len, cost;
};

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
    cin >> n >> m;
    int start, finish;
    cin >> start >> finish;

    vector< pair< int, pair<int, int> > > g[NMAX], gr[NMAX];
    vector<node> a((unsigned long) m);

    for (int i = 0; i < m; i++) {
        cin >> a[i].a >> a[i].b >> a[i].len >> a[i].cost;
        g[a[i].a].pb({a[i].b, {a[i].len, a[i].cost}});
        gr[a[i].b].pb({a[i].a, {a[i].len, a[i].cost}});
    }

    for (int i = 0; i < 2; i++) {
        fill(d[i], d[i] + NMAX, INT_MAX);
    }

    set< pair<ll, int> > q;
    d[0][start] = 0;
    q.insert({d[0][start], start});

    while (q.size()) {
        int v = q.begin()->se;
        q.erase(q.begin());
        for (auto t : g[v]) {
            int u = t.fi, len = t.se.fi, cost = t.se.se;
            if (d[0][v] + len < d[0][u]) {
                q.erase({d[0][u], u});
                d[0][u] = d[0][v] + len;
                q.insert({d[0][u], u});
            }
        }
    }

    d[1][finish] = 0;
    q.insert({d[1][finish], finish});

    while (q.size()) {
        int v = q.begin()->se;
        q.erase(q.begin());
        for (auto t : gr[v]) {
            int u = t.fi, len = t.se.fi, cost = t.se.se;
            if (d[1][v] + len < d[1][u]) {
                q.erase({d[1][u], u});
                d[1][u] = d[1][v] + len;
                q.insert({d[1][u], u});
            }
        }
    }

    vector< pair<ll, ll> > v;
    for (int i = 0; i < m; i++) {
        int A = a[i].a, B = a[i].b, len = a[i].len, cost = a[i].cost;
        v.pb({d[0][A] + d[1][B] + len, cost});
    }
    sort(v.begin(), v.end());

    int Q;
    cin >> Q;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            sum[i] = v[i].se;
        } else {
            sum[i] = sum[i - 1] + v[i].se;
        }
    }

    while (Q--) {
        int val;
        cin >> val;
        int L = -1, R = v.size();
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (v[M].fi <= val) {
                L = M;
            } else {
                R = M;
            }
        }
        if (L == -1) {
            cout << 0 << endl;
            continue;
        }
        cout << sum[L] << endl;
    }
}