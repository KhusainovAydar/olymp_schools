#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

vector< vector< pair<int, int> > > g;
int n, m;

pair<ll, pair<int, int> > ans;

inline int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}
vector<int> mas;
vector<int> x, y;

void dijkstra() {
    vector<ll> d(n, LLONG_MAX - 1), p(n);
    set< pair<int, int> > q;
    int s;
    for (int i = 0; i < x.size(); i++) {
        s = x[i];
        d[s] = 0;
        q.insert({d[s], s});
    }
    while (!q.empty()) {
        int v = q.begin()->se;
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].fi, 
                    len = g[v][i].se;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    pair<ll, int> cnt = {LLONG_MAX - 1, -1};
    for (int t = 0; t < y.size(); t++) {
        if (d[y[t]] < cnt.fi) {
            cnt = {d[y[t]], y[t]};
        }
    }
    if (cnt.se == -1) {
        return;
    }
    int t = cnt.se;
    int v = t;
    while (mas[v] != 1) v = p[v];
    ans = {cnt.fi, {v, t}};
    return;
}

int main() {
    //ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("secure.in", "r", stdin); 
        freopen("secure.out", "w", stdout);
    #endif
    n = getint(), m = getint();
    mas.resize(n);

    for (int i = 0; i < n; i++) {
        mas[i] = getint();
        if (mas[i] == 1) {
            x.pb(i);
        }
        if (mas[i] == 2) {
            y.pb(i);
        }
    }
    g.resize(n);

    for (int i = 0; i < m; i++) {
        int a = getint(), b = getint(), c = getint();
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    ans.fi = LLONG_MAX - 1;
    dijkstra();
    if (ans.fi == LLONG_MAX - 1) {
        puts("-1");
    } else 
    printf("%d %d %lld\n", ans.se.fi + 1, ans.se.se + 1, ans.fi);
}   