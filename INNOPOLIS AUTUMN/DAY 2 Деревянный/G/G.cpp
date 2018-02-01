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

const int NMAX = 2 * 1e6 + 5;
int par[NMAX], rang[NMAX];

void make_set(int v) {
    par[v] = v;
    rang[v] = 0;
}

int find_set(int v) {
    return (v == par[v]) ? v : (par[v] = find_set(par[v]));
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        par[b] = a;
        if (rang[a] == rang[b])
            rang[a]++;
    }
}

vector< vector<int> > up;
vector<int> dist;
int lg2 = 30;

void add(int v, int p) {
    up[0][v] = find_set(p);
    dist[v] = dist[p] + 1;
    for (int i = 1; i < lg2; i++) {
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
}

int go_up(int x, int d) {
    for (int i = lg2 - 1; i >= 0; i--) {
        if ((1 << i) > d) continue;
        x = up[i][x];
        d -= (1 << i);
    }
    return x;
}

int lca(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (dist[a] != dist[b]) {
        if (dist[a] > dist[b]) {
            swap(a, b);
        }
        b = go_up(b, dist[b] - dist[a]);
    }
    if (a == b) return find_set(a);
    for (int i = lg2 - 1; i >= 0; i--) {
        if (up[i][a] == up[i][b]) continue;
        a = up[i][a];
        b = up[i][b];
    }
    return find_set(up[0][a]);
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("carno.in", "r", stdin);
    freopen("carno.out", "w", stdout);
#endif
    int n;
    cin >> n;
    up.assign(lg2, vector<int>(n + 100));
    dist.assign(n, 0);
    make_set(0);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            x--;
            make_set(cnt);
            add(cnt, x);
            cnt++;
        } else if (c == '-') {
            int x;
            cin >> x;
            x--;
            union_sets(find_set(up[0][x]), x);
        } else if (c == '?') {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << find_set(lca(a, b)) + 1 << endl;
        }
    }
}