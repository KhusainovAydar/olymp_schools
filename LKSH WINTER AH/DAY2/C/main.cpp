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

const int NMAX = (const int) (1e6 + 6);

vector<int> g[NMAX];
ll G[NMAX], par[NMAX], d[NMAX];
int n, m;

void dfs(int v, int p) {
    int sz = (int) g[v].size();
    par[v] = p;
    ll ans = 0;
    for (auto t : g[v]) {
        if (t == p) continue;
        dfs(t, v);
        d[t] = d[v] + 1;
        ans ^= (G[t] + 1);
    }
    G[v] = ans;
}

pair<int, int> mem;

void ans(int v, int p, int val) {
    for (auto t : g[v]) {
        if (t == p) continue;
        ll x = ((G[v] ^ val) ^ (G[t] + 1));
        if (x == 0) {
            mem = {v, t};
            return;
        }
        if (x <= G[t]) {
            ans(t, v, (int) (x - 1));
            return;
        }
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
    freopen("woodcut.in", "r", stdin);
    freopen("woodcut.out", "w", stdout);
#endif
    cin >> n >> m;
    vector< pair<int, int> > v((unsigned long) n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[i] = {a, b};
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(m - 1, -1);

    if (G[m - 1] == 0) {
        cout << 2;
        return 0;
    }
    cout << 1 << endl;
    ans(m - 1, -1, 0);
    //cout << mem.fi << ' ' << mem.se << endl;
    for (int i = 0; i < n - 1; i++) {
        if (v[i].fi == mem.fi && v[i].se == mem.se) {
            cout << i + 1;
            return 0;
        }
        if (v[i].fi == mem.se && v[i].se == mem.fi) {
            cout << i + 1;
            return 0;
        }
    }
}