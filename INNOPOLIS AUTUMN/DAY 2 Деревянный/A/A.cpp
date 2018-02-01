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

vector< vector<int> > g;
int n, q;
int cor;
const int NMAX = 1e5 + 5;
int tin[NMAX], tout[NMAX];
int timer = 1;

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto t : g[v]) {
        if (t == p) continue;
        dfs(t, v);
    }
    tout[v] = timer;
}

bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int main(int argc, char* argv[]) {
    //srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    freopen("ancestor.in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
#endif
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (x == -1) {
            cor = i;
            continue;
        }
        g[x].push_back(i);
        g[i].push_back(x);
    }
    cin >> q;
    dfs(cor, -1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << anc(a, b) << endl;
    }
}