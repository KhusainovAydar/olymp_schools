#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
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
    int r;
    cin >> r;
    int n;
    cin >> n;
    vector< pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    vector< pair<int, int> > scan;
    for (int i = 0; i < n; i++) {
        scan.pb({v[i].fi, 0});
        scan.pb({v[i].se, 1});
    }
    sort(scan.begin(), scan.end());
    int bal = 0, maxx = 0;
    for (int i = 0; i < scan.size(); i++) {
        if (bal == 0) {
            if (i > 0) {
                maxx = max(maxx, scan[i].fi - scan[i - 1].fi);
            }
        }
        if (scan[i].se == 0) {
            bal++;
        } else {
            bal--;
        }
    }
    maxx = max(maxx, r - scan.back().fi);
    maxx = max(maxx, scan[0].fi);
    cout << maxx << endl;
}