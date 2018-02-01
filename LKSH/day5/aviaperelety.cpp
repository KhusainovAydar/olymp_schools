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

const int NMAX = 1003;
int n;
int mas[NMAX][NMAX];
bool used[NMAX];
vector< vector<int> > g, gr;
vector<int> order, component;

void dfs1(int v, ll m) {
    used[v] = true;
    for (int i = 0; i < n; i++) {
        if (g[v][i] <= m && !used[i]) {
            dfs1(i, m);
        }
    }
    order.push_back(v);
}

void dfs2(int v, ll m) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < n; i++) {
        if (!used[i] && gr[v][i] <= m) {
            dfs2(i, m);
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
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);
#endif
    cin >> n;
    g.resize(n, vector<int> (n));
    gr.resize(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mas[i][j];
            g[i][j] = mas[i][j];
            gr[j][i] = mas[i][j];
        }
    }
    ll l = -1, r = LLONG_MAX - 1;
    while (r - l > 1) {
        //cout << l << ' ' << r << endl;
        ll m = (l + r) >> 1;
        component.clear();
        order.clear();
        memset(used, 0, sizeof used);
        for (int i = 0; i < n; i++) {
            if (!used[i])
                dfs1(i, m);
        }
        memset(used, 0, sizeof used);
        for (int i = 0; i < n; i++) {
            int v = order[n - i - 1];
            if (!used[v]) {
                dfs2(v, m);
                if (component.size() == n)
                    r = m;
                else l = m;
                break;
            }
        }
    }
    cout << r;
}