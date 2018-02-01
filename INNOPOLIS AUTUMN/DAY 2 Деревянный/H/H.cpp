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
//#define MOD 1000000007

using namespace std;

typedef long long ll;

const int NMAX = 1e5 + 5;
int tin[NMAX], tout[NMAX];
const int K = 25;
int go[K][NMAX];
int timer = 1;
int dp[NMAX];
vector< vector<int> > g;
int n;
int parent[NMAX];

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto t : g[v]) {
        if (t == p) continue;
        dp[t] = dp[v] + 1;
        dfs(t, v);
    }
    tout[v] = timer;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
    if (anc(v, u)) {
        return v;
    }
    if (anc(u, v)) {
        return u;
    }
    for (int i = K - 1; i >= 0; i--) {
        if (!anc(go[i][v], u)) {
            v = go[i][v];
        }
    }
    return parent[v];
}

bool cmp(int a, int b) {
    return tin[a] < tin[b];
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("genealogy.in", "r", stdin);
    freopen("genealogy.out", "w", stdout);
#endif
    cin >> n;
    g.resize(n);
    int cor = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            cor = i;
            parent[i] = i;
            continue;
        }
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
        parent[i] = x;
    }
    dp[cor] = 1;
    dfs(cor, -1);
    for (int i = 0; i < n; i++) {
        go[0][i] = parent[i];
    }
    for (int i = 1; i < K; i++) {
        for (int j = 0; j < n; j++) {
            go[i][j] = go[i - 1][go[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a[i]--;
        }
        sort(a.begin(), a.end(), cmp);
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += dp[a[i]];
        }
        for (int i = 1; i < k; i++) {
            sum -= dp[lca(a[i], a[i - 1])];
        }
        cout << sum << endl;
    }
}