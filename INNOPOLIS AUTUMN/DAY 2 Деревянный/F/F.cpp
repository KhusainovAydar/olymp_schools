#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 3 * 1e5 + 5;
int kek = 0;
const int K = 20;
int go[K][NMAX], parent[NMAX];
int tin[NMAX], tout[NMAX];
ll t[NMAX * 4];
int timer = 0;
vector< vector< int > > g;

void dfs(int v, int p) {
    tin[v] = timer++;
    if (p == -1) {
        parent[v] = kek;
    } else {
        parent[v] = p;
    }
    for (auto t : g[v]) {
        if (t == p) {
            continue;
        }
        dfs(t, v);
    }
    tout[v] = timer - 1;
}

void upd(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] += val;
        return;
    }
    if (tl > tr) return;
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        upd(2 * v + 1, tl, tm, pos, val);
    } else {
        upd(2 * v + 2, tm + 1, tr, pos, val);
    }
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return 0;
    if (l > r) return 0;
    if (tl > tr) return 0;
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    
    return sum(2 * v + 1, tl, tm, l, min(tm, r)) +
    sum(2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int v, int u) {
    if (anc(v, u)) {
        return v;
    }
    for (int i = K - 1; i >= 0; i--) {
        if (!anc(go[i][v], u)) {
            v = go[i][v];
        }
    }
    return parent[v];
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("treepathadd.in", "r", stdin);
    freopen("treepathadd.out", "w", stdout);
#endif
    int n;
    cin >> n;
    g.resize(NMAX);
    g[0].push_back(1);
    g[1].push_back(0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    kek = 0;
    
    dfs(0, -1);
    n++;
    for (int i = 0; i < n; i++) go[0][i] = parent[i] < 0 ? i : parent[i];
    for (int i = 1; i < K; i++) {
        for (int v = 0; v < n; v++) go[i][v] = go[i - 1][go[i - 1][v]];
    }
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            int a, b;
            cin >> a >> b;
            ll val;
            cin >> val;
            int lc = lca(a, b);
            //cout << a << ' ' << b << ' ' << lc << ' ' << parent[lc] << endl;
            //cout << tin[a] << ' ' << tin[b] << ' ' << tin[lc] << ' ' << tin[parent[lc]] << endl;
            upd(0, 0, n + 1, tin[a], val);
            upd(0, 0, n + 1, tin[b], val);
            upd(0, 0, n + 1, tin[lc], -val);
            upd(0, 0, n + 1, tin[parent[lc]], -val);
        } else {
            int x;
            cin >> x;
            int l = tin[x], r = tout[x];
            //cout << l << ' ' << r << endl;
            cout << sum(0, 0, n + 1, l, r) << endl;
        }
    }
}