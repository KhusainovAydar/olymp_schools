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

const int NMAX = (const int) (1e5 + 5);

vector<int> g[NMAX], gr[NMAX];
vector<int> G(NMAX, 0);
vector<bool> used(NMAX, 0);
int n, m;

void dfs(int v) {
    used[v] = 1;
    int sz = (int) g[v].size();
    vector<bool> k((unsigned long) (sz + 1), 0);
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
        if (G[to] > sz) continue;
        k[G[to]] = 1;
    }
    for (int i = 0; i <= sz; i++) {
        if (!k[i]) {
            G[v] = i;
            break;
        }
    }
}

vector<int> ans;

void dfs2(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs2(to);
        }
    }
    ans.pb(v);
}

void top_sort() {
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs2(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        gr[b].pb(a);
    }
    top_sort();
//    for (auto v : ans) {
//        cerr << v << ' ';
//    }
    for (auto v : ans) {
        if (!used[v]) {
            dfs(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << G[i] << endl;
    }
}