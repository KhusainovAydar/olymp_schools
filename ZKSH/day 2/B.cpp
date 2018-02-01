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

const int NMAX = 1000000;
int sum[NMAX];

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
    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        sum[a[i].fi + a[i].se]++;
    }
    string s;
    cin >> s;
    int S = 0;
    int ans = 0;
    for (auto i : s) {
        if (i == '+') {
            S++;
        } else {
            S--;
        }
        ans += sum[S];
        S -= sum[S];
    }
    cout << ans;
}