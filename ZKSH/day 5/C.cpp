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
    vector< ll > a(n);
    vector< ll > cur(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur[i] = 1;
    }
    ll ans = 1;
    reverse(all(a));
    for (int i = 0; i < n - 1; i++) {
        ll L = 0, R = 1000000000;
        while (R - L > 1) {
            ll M = (L + R) >> 1;
            if (a[i + 1] * cur[i] <= a[i] * M) {
                R = M;
            } else {
                L = M;
            }
        }
        ans += R;
        cur[i + 1] = R;
    }
    cout << ans;
}
