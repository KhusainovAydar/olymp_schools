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

map<int, vector<int> > X, Y;

int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        int x = a[i].fi, y = a[i].se;
        X[x].pb(y); Y[y].pb(x);
    }
    for (auto &t : X) {
        sort(all(t.se));
    }
    for (auto &t : Y) {
        sort(all(t.se));
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i].fi, y = a[i].se;
        int pos1 = lower_bound(X[x].begin(), X[x].end(), y) - X[x].begin();
        int pos2 = lower_bound(Y[y].begin(), Y[y].end(), x) - Y[y].begin();
//        for (int j = 0; j < X[x].size(); j++) {
//            cerr << X[x][j] << ' ';
//        }
//        cerr << endl;
//        for (int j = 0; j < Y[y].size(); j++) {
//            cerr << Y[y][j] << ' ';
//        }
//        cerr << endl;
//        cerr << X[x].size() << ' ' << Y[y].size() << ' ' << (int)X[x].size() - pos1 - 1 << ' ' << (int)Y[y].size() - pos2 - 1 << endl;
        ans += pos1 * 1ll * (X[x].size() - pos1 - 1) * 1ll * pos2 * 1ll * (Y[y].size() - pos2 - 1);
//        cerr << endl;
    }
    cout << ans * 2;
}
