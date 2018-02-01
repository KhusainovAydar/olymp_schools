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
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 50050, K = 20, CK = 500;

vector<int> g[NMAX];
int n;
ll c[NMAX];
ll dp[CK][NMAX];
int glub[NMAX];
int T, tin[NMAX], tout[NMAX];

int go[K][NMAX];

void dfs(int v, int p) {
    tin[v] = T++;
    if (p == -1) {
        go[0][v] = v;
    } else {
        go[0][v] = p;
    }
    for (auto t : g[v]) {
        if (t == p) continue;
        glub[t] = glub[v] + 1;
        dfs(t, v);
    }
    tout[v] = T;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int goup(int v, int ur) {
    int u = v;
    for (int i = K - 1; i >= 0; i--) {
        if (ur - (1 << i) >= 0) {
            ur -= (1 << i);
            u = go[i][u];
        }
    }
    return u;
}

int lca(int v, int u) {
    if (anc(v, u)) return v;
    if (anc(u, v)) return u;
    for (int i = K - 1; i >= 0; i--) {
        if (!anc(go[i][u], v)) {
            u = go[i][u];
        }
    }
    return go[0][u];
}

void dfs_cnt(int v, int p) {
    for (int i = 1; i < CK; i++) {
        int u = goup(v, i);
        if (glub[u] % i == glub[v] % i)
            dp[i][v] = dp[i][u] + c[v];
        else
            dp[i][v] = c[v];
    }
    for (auto t : g[v]) {
        if (t == p) continue;
        dfs_cnt(t, v);
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
    //    freopen("anniversary.in", "r", stdin);
//    freopen("anniversary.out", "w", stdout);
#endif
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, -1);

    for (int i = 1; i < K; i++) {
        for (int j = 0; j < n; j++) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }

    dfs_cnt(0, -1);

    vector<int> t((unsigned long) n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }
    vector<int> k((unsigned long) (n - 1));
    for (int i = 0; i < n - 1; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int v = t[i], u = t[i + 1];
        int q = lca(v, u);
        int val = k[i];
        if (q == v && val < CK) {
            int r = (glub[u] - glub[v]) / val;
            cout << dp[val][u] - dp[val][v] + c[v] << endl;
            continue;
        }
        if (q == u && val < CK) {
            int r = (glub[v] - glub[u]) / val;
            cout << dp[val][v] - dp[val][u] + c[u] << endl;
            continue;;
        }
        if (val < CK) {
            int r = (glub[v] - glub[q]) / val;
            int up_q = goup(v, r * val);
            int sv = up_q;
            ll ans = 0;
            ans += dp[val][v] - dp[val][up_q] + c[up_q];
            r = (glub[u] - glub[q]) / val;
            up_q = goup(u, r * val);
            ans += dp[val][u] - dp[val][up_q] + c[up_q] * (sv != up_q);
            cout << ans << endl;
        } else {
            ll ans = 0;
            while (glub[u] > glub[q]) {
                ans += c[u];
                u = goup(u, val);
            }
            while (glub[v] >= glub[q]) {
                if (v == q) {
                    if (glub[q] % val == glub[t[i]] % val)
                        ans += c[v];
                    break;
                }
                ans += c[v];
                v = goup(v, val);
            }
            cout << ans << endl;
        }
    }
}