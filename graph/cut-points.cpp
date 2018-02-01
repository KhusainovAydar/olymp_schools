#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll

using namespace std;

typedef long long ll;

int n, m;
const int NMAX = 20005;
vector<int> g[NMAX];
int in[NMAX], out[NMAX];
bool used[NMAX];
int T;
set<int> ans;

void dfs(int v, int p = -1) {
    used[v] = true;
    in[v] = T;
    out[v] = T++;
    int child = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) {
            out[v] = min(out[v], in[to]);
        } else {
            dfs(to, v);
            child++;
            out[v] = min(out[v], out[to]);
            if (out[to] >= in[v] && p != -1) {
                ans.insert(v);
            }
        }
    }
    if (p == -1 && child > 1) {
        ans.insert(v);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            T = 0;
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for (auto t : ans) {
        cout << t + 1 << endl;
    }
}
