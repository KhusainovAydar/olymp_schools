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

const int NMAX = 200005;

vector<int> g[NMAX];
ll dp[2][NMAX];
ll l[NMAX], r[NMAX];
ll size[NMAX];
int n;

void dfs(int v, int p) {
    size[v] = 1;
    ll sum1 = 0, sum2 = 0;
    vector< pair<int, int> > kek;
    for (auto t : g[v]) {
        if (t == p) continue;
        dfs(t, v);
        sum1 += dp[0][t];
        sum2 += dp[1][t];
        size[v] += size[t];
    }
    dp[0][v] = max((ll)l[v], sum1);
    dp[1][v] = min((ll)r[v], sum2 + 1);
}

set<int> ans;

void pokr(int v, int p) {
    ans.insert(v);
    for (auto t : g[v]) {
        if (t == p) continue;
        pokr(t, v);
    }
}

void DFS(int v, int p, int val) {
    ll sum = val;
    if (sum == 0) return;
    if (sum == size[v]) {
        pokr(v, p);
        return;
    }
    for (auto t : g[v]) {
        if (t == p) continue;
        sum -= dp[0][t];
    }
    for (auto t : g[v]) {
        if (t == p) continue;
        ll r = dp[1][t] - dp[0][t];
        if (sum >= r) {
            sum -= r;
            DFS(t, v, dp[1][t]);
            continue;
        }
        DFS(t, v, dp[0][t] + sum);
        sum = 0;
    }
    if (sum == 1) {
        ans.insert(v);
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
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            g[i].pb(x);
            g[x].pb(i);
        }
    }
    dfs(0, -1);
    DFS(0, -1, dp[0][0]);
    cout << ans.size() << endl;
    for (auto t : ans) {
        cout << t  + 1 << ' ';
    }
}