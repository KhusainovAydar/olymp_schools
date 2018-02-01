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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll NMAX = 105, INF = 1000000000;

struct edge {
    int to;
    int cap, flow;
    int num;
};

int n, m;
bool del[NMAX];
vector< edge > edges;
vector< int > g[NMAX];
vector< int > ptr;
bool used[NMAX];
int type[NMAX];
vector< int > dist;

void add_edge(int v, int u, int cap, int num) {
    g[v].pb(edges.size());
    edges.pb({u, cap, 0, num});
    g[u].pb(edges.size());
    edges.pb({v, cap, 0, num});
}

void bfs(int start) {
    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto t : g[v]) {
            int u = edges[t].to;
            if (edges[t].flow < edges[t].cap && dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int dfs(int v, int flow, int sink) {
    if (v == sink) {
        return flow;
    }
    for (; ptr[v] < g[v].size(); ptr[v]++) {
        int i = g[v][ptr[v]];
        int to = edges[i].to;
        if (dist[to] == dist[v] + 1 && edges[i].flow < edges[i].cap) {
            int cur_flow = dfs(to, min(flow, edges[i].cap - edges[i].flow), sink);
            if (cur_flow != 0) {
                edges[i].flow += cur_flow;
                edges[i ^ 1].flow -= cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
}

ll dinic(int source, int sink) {
    ll flow = 0;
    dist.resize(NMAX, INF);
    ptr.resize(NMAX, 0);
    while (true) {
        bfs(source);
        if (dist[sink] == INF) {
            break;
        }
        fill(ptr.begin(), ptr.end(), 0);
        while (ll cur_flow = dfs(source, INF, sink)) {
            flow += cur_flow;
        }
    }
    return flow;
}

vector<int> Ans;

void dfs_ans(int v) {
    used[v] = 1;
    type[v] = 1;
    for (auto t : g[v]) {
        if (edges[t].to == n || used[edges[t].to]) continue;
        if (edges[t].cap != edges[t].flow)
            dfs_ans(edges[t].to);
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
    //    freopen("substr3.in", "r", stdin);
//    freopen("subst3.out", "w", stdout);
#endif
    cin >> n >> m;
    vector< pair<int, int> > V(m);
    for (int i = 0; i < m; i++) {
        int v, u, cap;
        cin >> v >> u >> cap;
        V[i] = {v, u};
        add_edge(v, u, cap, i);
    }
    ll ans = dinic(1, n);
    dfs_ans(1);
    for (int i = 0; i < m; i++) {
        int v = V[i].fi, u = V[i].se;
        if (type[v] != type[u]) {
            Ans.pb(i + 1);
        }
    }
    cout << Ans.size() << ' ';
    cout << ans << endl;
    sort(all(Ans));
    for (auto t : Ans) {
        cout << t << ' ';
    }
}#include <bits/stdc++.h>
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll NMAX = 105, INF = 1000000000;

struct edge {
    int to;
    int cap, flow;
    int num;
};

int n, m;
bool del[NMAX];
vector< edge > edges;
vector< int > g[NMAX];
vector< int > ptr;
bool used[NMAX];
int type[NMAX];
vector< int > dist;

void add_edge(int v, int u, int cap, int num) {
    g[v].pb(edges.size());
    edges.pb({u, cap, 0, num});
    g[u].pb(edges.size());
    edges.pb({v, cap, 0, num});
}

void bfs(int start) {
    fill(dist.begin(), dist.end(), INF);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto t : g[v]) {
            int u = edges[t].to;
            if (edges[t].flow < edges[t].cap && dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int dfs(int v, int flow, int sink) {
    if (v == sink) {
        return flow;
    }
    for (; ptr[v] < g[v].size(); ptr[v]++) {
        int i = g[v][ptr[v]];
        int to = edges[i].to;
        if (dist[to] == dist[v] + 1 && edges[i].flow < edges[i].cap) {
            int cur_flow = dfs(to, min(flow, edges[i].cap - edges[i].flow), sink);
            if (cur_flow != 0) {
                edges[i].flow += cur_flow;
                edges[i ^ 1].flow -= cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
}

ll dinic(int source, int sink) {
    ll flow = 0;
    dist.resize(NMAX, INF);
    ptr.resize(NMAX, 0);
    while (true) {
        bfs(source);
        if (dist[sink] == INF) {
            break;
        }
        fill(ptr.begin(), ptr.end(), 0);
        while (ll cur_flow = dfs(source, INF, sink)) {
            flow += cur_flow;
        }
    }
    return flow;
}

vector<int> Ans;

void dfs_ans(int v) {
    used[v] = 1;
    type[v] = 1;
    for (auto t : g[v]) {
        if (edges[t].to == n || used[edges[t].to]) continue;
        if (edges[t].cap != edges[t].flow)
            dfs_ans(edges[t].to);
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
    //    freopen("substr3.in", "r", stdin);
//    freopen("subst3.out", "w", stdout);
#endif
    cin >> n >> m;
    vector< pair<int, int> > V(m);
    for (int i = 0; i < m; i++) {
        int v, u, cap;
        cin >> v >> u >> cap;
        V[i] = {v, u};
        add_edge(v, u, cap, i);
    }
    ll ans = dinic(1, n);
    dfs_ans(1);
    for (int i = 0; i < m; i++) {
        int v = V[i].fi, u = V[i].se;
        if (type[v] != type[u]) {
            Ans.pb(i + 1);
        }
    }
    cout << Ans.size() << ' ';
    cout << ans << endl;
    sort(all(Ans));
    for (auto t : Ans) {
        cout << t << ' ';
    }
}