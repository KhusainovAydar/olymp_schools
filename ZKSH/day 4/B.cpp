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


const int NMAX = 10005;

bool used[NMAX];
int ans[NMAX];

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
    int n, k;
    cin >> n >> k;
    vector< pair<int, int> > d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].fi;
        d[i].se = i;
    }
    vector< pair<int, int> > a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(all(d));
    for (int i = 0; i < n; i++) {
        int maxx = 0;
        int id = 0;
        int wes = 0;
        for (int j = 0; j < k; j++) {
            if (used[j]) continue;
            if (a[j].se > d[i].fi) continue;
            if (a[j].fi > maxx) {
                maxx = a[j].fi;
                wes = a[j].se;
                id = j + 1;
            } else if (a[j].fi == maxx && a[j].se > wes) {
                maxx = a[j].fi;
                wes = a[j].se;
                id = j + 1;
            }
        }
        if (id == 0) continue;
        used[id - 1] = 1;
        ans[d[i].se] = id;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}
