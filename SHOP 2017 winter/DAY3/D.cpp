#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
//#define pi 3.1415926535897932384626433832795
#define eps 0.000000001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 1000050;

ll dp[NMAX], a[NMAX], c[NMAX], sum[2][NMAX];

int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("maxflow.in", "r", stdin);
//    freopen("subst3.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[0][i] = sum[0][i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[1][i] = sum[1][i - 1] + c[i];
    }

    for (int i = n + 1; i < NMAX; i++) {
        sum[0][i] = 1000000000000000;
        sum[1][i] = sum[1][i - 1];
    }
    for (int i = 1; i < NMAX; i++) {
        int L = 0, R = n + 1;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (a[M] <= i) {
                R = M;
            } else {
                L = M;
            }
        }
        int pos = R;
        if (pos == n + 1) {
            dp[i] = 0;
        } else {
            L = 1, R = n + 1;
            while (R - L > 1) {
                int M = (L + R) >> 1;
                ll s = sum[0][pos + M - 1] - sum[0][pos - 1];
                if (s <= i) {
                    L = M;
                } else {
                    R = M;
                }
            }
            if (i - sum[0][pos + L - 1] + sum[0][pos - 1] > 0 && pos + L - 1 == n) {
                ll ans = dp[sum[0][pos + L - 1] - sum[0][pos - 1]];
                dp[i] = ans;
            } else {
                dp[i] = dp[max(0ll, i - sum[0][pos + L - 1] + sum[0][pos - 1])] + sum[1][pos + L - 1] - sum[1][pos - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << dp[x] << endl;
    }
}