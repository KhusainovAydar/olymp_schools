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

const int NMAX = 3005, MMAX = 105;

ll dp[NMAX][MMAX][MMAX][2];
ll a[NMAX];

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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<ll> b(m + 1);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    b[m] = -INT_MAX;
    sort(all(b));
    ll maxx = 0;
    for (int i = 1; i <= n; i++) {
        for (int L = 0; L <= m; L++) {
            for (int R = m + 1; R > L; R--) {
                dp[i + 1][L][R][0] = max(dp[i + 1][L][R][0], dp[i][L][R][0]); // пропускаем предмет
                dp[i + 1][L][R][1] = max(dp[i + 1][L][R][1], dp[i][L][R][0] + a[i]); // берем предмет и переходим в положение где не можем взять
                //dp[i][L][R][1] -> dp[i + 1][L][R][0] переходим в состояние 0
                dp[i + 1][L][R][0] = max(dp[i + 1][L][R][0], dp[i][L][R][1]);
                // в состоянии 1 мы можем отдать L и перейти в состояние 0
                dp[i][L + 1][R][0] = max(dp[i][L + 1][R][0], dp[i][L][R][1]);
                // в состоянии 0 мы можем взять R и перейти в состояние 1
                dp[i][L][R - 1][1] = max(dp[i][L][R - 1][1], dp[i][L][R][0] + b[R - 1]);
            }
        }
    }
    for (int i = 0; i < NMAX; i++) {
        for (int L = 0; L < MMAX; L++) {
            for (int R = L + 1; R < MMAX; R++) {
                maxx = max(maxx, dp[i][L][R][0]);
                maxx = max(maxx, dp[i][L][R][1]);
            }
        }
    }
    cout << maxx;
}