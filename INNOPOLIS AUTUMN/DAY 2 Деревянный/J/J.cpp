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

const int NMAX = 2 * 1e5 + 5;

vector<int> g[NMAX];
int level[NMAX], parent[NMAX];


int dfs(int v, int sz, int & center, int p = -1) {
    int sum = 1;
    for (auto x : g[v]) {
        if (level[x] == -1 && x != p) {
            sum += dfs(x, sz, center, v);
        }
    }
    if (center == -1 && (2 * sum >= sz || p == -1)) {
        center = v;
    }
    return sum;
}

void build(int v, int sz, int dep, int last) {
    int center = -1;
    dfs(v, sz, center);
    level[center] = dep;
    parent[center] = last;
    for (auto x : g[center]) {
        if (level[x] == -1) {
            build(x, sz / 2, dep + 1, center);
        }
    }
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(level, -1, sizeof(level));
    build(0, n, 0, -1);
    for (int i = 0; i < n; i++) {
        cout << parent[i] + 1 << ' ';
    }
}