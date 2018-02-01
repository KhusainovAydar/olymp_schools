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

const int NMAX = 500;

vector<int> g[NMAX];
int n, m;
vector<bool> used;
vector<int> mt;

bool try_kuhn(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (auto t : g[v]) {
        if (mt[t] == -1 || try_kuhn(mt[t])) {
            mt[t] = v;
            return true;
        }
    }
    return false;
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
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x != 0) {
            x--;
            g[i].pb(x);
            cin >> x;
        }
    }

    used.resize(n, 0);
    mt.resize(m, -1);
    for (int i = 0; i < n; i++) {
        fill(used.begin(), used.end(), 0);
        try_kuhn(i);
    }

    vector< pair<int, int> > ans;
    for (int i = 0; i < m; i++) {
        if (mt[i] != -1) {
            ans.pb({mt[i] + 1, i + 1});
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].fi << ' ' << ans[i].se << endl;
    }
}