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

vector< vector<int> > g;
int n;

const int NMAX = 1e5 + 5;
const int K = 20;

int go[K][NMAX];
int parent[NMAX];

int tin[NMAX], tout[NMAX];
int dist[NMAX];
int timer = 1;

void dfs(int v, int p) {
    tin[v] = timer++;
    parent[v] = p;
    if (p == -1) {
        dist[v] = 0;
    } else {
        dist[v] = dist[p] + 1;
    }
    for (auto t : g[v]) {
        if (t == p) continue;
        dfs(t, v);
    }
    tout[v] = timer;
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
    freopen("lenpath.in", "r", stdin);
    freopen("lenpath.out", "w", stdout);
#endif
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) go[0][i] = parent[i] < 0 ? i : parent[i];
    for (int i = 1; i < K; i++) {
        for (int v = 0; v < n; v++) go[i][v] = go[i - 1][go[i - 1][v]];
    }
    int m;
    cin >> m;
    //    for (int i = 0; i < n; i++) {
    //        cout << dist[i] << ' ';
    //    }
    //    cout << endl;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int q = lca(a, b);
        //        cout << q + 1 << ' ';
        //        cout << a + 1 << ' ' << b + 1 << ' ' << dist[a] << ' ' << dist[b] << endl;
        int sum = dist[a] - (dist[q]) + dist[b] - (dist[q]);
        cout << sum << endl;
    }
}