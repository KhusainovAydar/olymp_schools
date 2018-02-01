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

const int NMAX = 2002;

int n, m;

int a[NMAX][NMAX];

ll p = 259, mod = 1000000009;

ll h[4][NMAX][NMAX], step[NMAX];


inline ll getmod(ll x) {
    if (x >= mod) {
        x %= mod;
    }
    return x;
}

ll get_hash(int type, int pos, int l, int r) {
    if (type == 0) {
        ll res = getmod(h[0][pos][r] - getmod(h[0][pos][l - 1] * step[r - l + 1]));
        while (res < 0) res += mod;
        return res;
    } else if (type == 1) {
        ll res = getmod(h[type][r][pos] - getmod(h[type][l - 1][pos] * step[r - l + 1]));
        while (res < 0) res += mod;
        return res;
    } else if (type == 2) {
        ll res = getmod(h[type][pos][l] - getmod(h[type][pos][r + 1] * step[r - l + 1]));
        while (res < 0) res += mod;
        return res;
    } else if (type == 3) {
        ll res = getmod(h[type][l][pos] - getmod(h[type][r + 1][pos] * step[r - l + 1]));
        while (res < 0) res += mod;
        return res;
    }
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int it = 0; it < 4; it++) {
        if (it == 0) {
            for (int i = 1; i <= n; i++) {
                h[it][i][1] = a[i][1];
                for (int j = 2; j <= m; j++) {
                    h[it][i][j] = getmod(h[it][i][j - 1] * p + a[i][j]);
                }
            }
        } else if (it == 1) {
            for (int j = 1; j <= m; j++) {
                h[it][1][j] = a[1][j];
                for (int i = 2; i <= n; i++) {
                    h[it][i][j] = getmod(h[it][i - 1][j] * p + a[i][j]);
                }
            }
        } else if (it == 2) {
            for (int i = 1; i <= n; i++) {
                h[it][i][m] = a[i][m];
                for (int j = m - 1; j >= 1; j--) {
                    h[it][i][j] = getmod(h[it][i][j + 1] * p + a[i][j]);
                }
            }
        } else if (it == 3) {
            for (int j = 1; j <= m; j++) {
                h[it][n][j] = a[n][j];
                for (int i = n - 1; i >= 1; i--) {
                    h[it][i][j] = getmod(h[it][i + 1][j] * p + a[i][j]);
                }
            }
        }
    }
    step[0] = 1;
    for (int i = 1; i <= max(n, m); i++) {
        step[i] = getmod(step[i - 1] * p);
    }
    ll maxx = -1;

    int X, Y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int L = -1, R = max(n, m);
            while (R - L > 1) {
                int M = (L + R) >> 1;
                if (i + M > n || j + M > m || i - M <= 0 || j - M <= 0) {
                    R = M;
                    continue;
                }
                ll res = get_hash(0, i, j, j + M);
                if (res == get_hash(1, j, i, i + M) && res == get_hash(2, i, j - M, j) && res == get_hash(3, j, i - M, i)) {
                    L = M;
                } else {
                    R = M;
                }
            }
            if (L >= 0) {
                if (L >= maxx) {
                    maxx = L;
                    X = i, Y = j;
                }
            }
        }
    }

    cout << maxx << ' ' << X << ' ' << Y << endl;
}