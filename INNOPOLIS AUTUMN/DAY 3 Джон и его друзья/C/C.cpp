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

const int NMAX = 1e4 + 5;

bool used[NMAX];
bool tr[NMAX];
ll dp[NMAX];
ll t[NMAX];
vector< vector<int> > g;

void dfs(int v) {
    used[v] = 1;
    dp[v] = t[v];
    for (auto u : g[v]) {
        if (!used[u])
            dfs(u);
        dp[v] = max(dp[v], t[v] + dp[u]);
    }
}

int main() {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        dp[i] = t[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tr[a] = 1;
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!tr[i] && !used[i]) {
            dfs(i);
        }
    }
    ll maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, dp[i]);
    }
    cout << maxx;
}