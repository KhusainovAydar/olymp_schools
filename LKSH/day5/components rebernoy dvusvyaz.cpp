#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define INF 1000000000000000
//#define y1 kek
//#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 20005;
int n, m;
vector< vector<int> > g;
bool used[NMAX];
int timer, tin[NMAX], fup[NMAX];
set< pair<int, int> > se;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = timer;
    fup[v] = timer++;
    bool flag = false;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) {
            if (!flag) {
                flag = true;
                continue;
            }
        }
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                //cout << v << ' ' << to << endl;
                se.insert({v, to});
                se.insert({to, v});
            }
        }
    }
}

int col[NMAX];

void dfscolor(int v, int color) {
    col[v] = color;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            if (se.find({v, to}) == se.end()) {
                dfscolor(to, color);
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs(i);
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("bicone.in", "r", stdin);
    freopen("bicone.out", "w", stdout);
#endif
    cin >> n >> m;
    g.resize(n);
    memset(col, 0, sizeof(col));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    find_bridges();
    int kek = 1;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfscolor(i, kek);
            kek++;
        }
    }
    cout << kek - 1 << endl;
    for (int i = 0; i < n; i++) {
        cout << col[i] << ' ';
    }
}s