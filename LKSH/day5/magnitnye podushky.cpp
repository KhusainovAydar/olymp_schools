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

struct Hash {
    vector< vector<ll> > h;
    vector<ll> step1, step2;
    ll p1 = 29, p2 = 31, mod = 42424243;
    void init(const vector< vector<char> > &m, int N, int M) {
        h.resize(N, vector<ll> (M));
        step1.resize(N + 1);
        step2.resize(M + 1);
        step1[0] = 1;
        step2[0] = 1;
        int c = m[0][0] - 'A';
        h[0][0] = c;
        for (int i = 1; i <= N; i++) {
            step1[i] = step1[i - 1] * p1;
            if (step1[i] >= mod) step1[i] %= mod;
        }
        for (int i = 1; i <= M; i++) {
            step2[i] = step2[i - 1] * p2;
            if (step2[i] >= mod) step2[i] %= mod;
        }
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (x == 0 && y == 0) continue;
                c = m[x][y] - 'A';
                h[x][y] = (x ? (h[x - 1][y] * p1) : 0) + (y ? (h[x][y - 1] * p2) : 0) - ((x > 0 && y > 0) ? h[x - 1][y - 1] * p1 * p2 : 0) + c;
                if (h[x][y] >= mod) h[x][y] %= mod;
            }
        }
    }
    ll get_hash(int x, int y, int xx, int yy) {
        ll ret = h[xx][yy] - (y ? (h[xx][y - 1] * step2[yy - y + 1]) % mod : 0)
        - (x ? (h[x - 1][yy] * step1[xx - x + 1]) % mod : 0) + ((x > 0 && y > 0) ? (h[x - 1][y - 1] * step1[xx - x + 1] * step2[yy - y + 1]) % mod : 0);
        ret %= mod;
        if (ret < 0) ret += mod;
        return ret;
    }
};

int n, m;
vector< vector<int> > g;
const int NMAX = 1e5 + 5;
bool used[2 * NMAX];
int timer, tin[2 * NMAX], fup[2 * NMAX];
set<int> cutp;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = timer;
    fup[v] = timer++;
    int child = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (v == p) p = -1;
        else {
            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
            } else {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] >= tin[v] && v >= n) {
                    cutp.insert(v);
                }
                child++;
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    srand((unsigned int)time(NULL));
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("city.in", "r", stdin);
    freopen("city.out", "w", stdout);
#endif
    cin >> n >> m;
    g.resize(NMAX * 2);
    int cnt = n;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        int d = cnt++;
        g[d].push_back(a);
        g[d].push_back(b);
        g[d].push_back(c);
        g[a].push_back(d);
        g[b].push_back(d);
        g[c].push_back(d);
    }
    memset(used, 0, sizeof(used));
    timer = 0;
    dfs(0);
    cout << cutp.size() << endl;
    for (auto t : cutp) {
        cout << t - n + 1 << ' ';
    }
}