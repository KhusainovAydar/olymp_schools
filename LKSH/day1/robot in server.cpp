#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define INF 1000000000000
#define pi 3.1415926535897932384626433832795
#define eps 0.0000000001
//#define double long double
//#define int ll
using namespace std;

typedef long long ll;

const int NMAX = 1e5;

int n, a[NMAX];
vector< vector<int> > g;
map<int, int> tim;
bool used[NMAX];
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfs(int v) {
    cl[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (cl[to] == 0) {
            if (dfs(to))  return true;
            p[to] = v;
        }       
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true; 
        }
    }
    cl[v] = 2;
    return false;
}

vector<int> top;

void topdfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            topdfs(to);
        }
    }
    top.pb(v);
}

int dp[NMAX];

void topsort() {
    memset(used, 0, sizeof used);
    top.clear();
    for (int i = 0; i < n; i++) {
        if (!used[i])
            topdfs(i);
    }
}

void din() {
    for (int i = 0; i < top.size(); i++) {
        int to = top[i];
        int maxx = 0, cnt = 0;
        for (int j = 0; j < g[to].size(); j++) {
            if (tim[g[to][j]] > tim[to]) {
                cnt++;
            }
            maxx = max(maxx, dp[g[to][j]] + cnt);
            cnt = 0;
        }
        dp[to] = maxx;
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, dp[i]);
    }
    cout << maxx + 1;
}

inline int getint() {
    char c = getchar();
    int g = 0;
    while (c <= 32) c = getchar();
    while (c > 32) {
        g = g * 10 + int(c - '0');
        c = getchar();
    }
    return g;
}

inline char get() {
    char c = getchar();
    while (c <= 32) c = getchar();
    return c;
}

int main() {
    //ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #if __APPLE__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("servers.in", "r", stdin); 
        freopen("servers.out", "w", stdout);
    #endif
    n = getint();
    for (int i = 0; i < n; i++) {
        a[i] = getint();
        a[i]--;
        tim[a[i]] = i + 1;
    }
    g.resize(n);
    for (int i = 0; i < n; i++) {
        int k = getint();
        for (int j = 0; j < k; j++) {
            int x = getint();
            x--;
            g[i].pb(x);
        }
    }
    p.assign(n, -1);
    cl.assign(n, 0);
    cycle_st = -1;
    for (int i = 0; i < n; ++i)
        if (dfs (i))
            break;
    if (cycle_st > -1) {
        puts("-1");
        return 0;
    }
    topsort();
    din();
}