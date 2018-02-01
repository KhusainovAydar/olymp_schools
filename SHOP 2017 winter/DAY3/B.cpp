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

struct node {
    int p[4];
};

const int NMAX = 128, LOG = 10, INF = 1000000000;
node T[NMAX][NMAX];
int n, m;

int st[4][NMAX][NMAX][LOG][LOG]; // 0 = min(x), 1 = max(x), 2 = min(y), 3 = max(y)

int Log[NMAX];
int val[] = {1, -1, 1, -1};
ll Q, A, B, V[20000150];

int f(int a, int b, int typ) {
    if (typ % 2 == 0) {
        return min(a, b);
    } else {
        return max(a, b);
    }
}

void build() {
    for (int typ = 0; typ < 4; typ++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (typ == 0) {
                    st[typ][i][j][0][0] = T[i][j].p[2];
                } else if (typ == 1) {
                    st[typ][i][j][0][0] = T[i][j].p[0];
                } else if (typ == 2) {
                    st[typ][i][j][0][0] = T[i][j].p[3];
                } else if (typ == 3) {
                    st[typ][i][j][0][0] = T[i][j].p[1];
                }
                for (int log1 = 0; log1 < LOG; log1++) {
                    for (int log2 = 0; log2 < LOG; log2++) {
                        if (log1 == 0 && log2 == 0) {
                            continue;
                        }
                        st[typ][i][j][log1][log2] = INF * val[typ];
                    }
                }
            }
        }
    }

    for (int type = 0; type < 4; type++) {
        for (int i = 0; i < n; i++) {
            for (int lg = 1; lg < LOG; lg++) {
                for (int j = 0; j + (1 << lg) <= m; j++) {
                    st[type][i][j][0][lg] = f(st[type][i][j][0][lg - 1], st[type][i][j + (1 << (lg - 1))][0][lg - 1], type);
                }
            }
        }
    }

    for (int type = 0; type < 4; type++) {
        for (int lg1 = 1; lg1 < LOG; lg1++) {
            for (int i = 0; i + (1 << lg1) <= n; i++) {
                for (int lg2 = 0; lg2 < LOG; lg2++) {
                    for (int j = 0; j + (1 << lg2) <= m; j++) {
                        st[type][i][j][lg1][lg2]= f(st[type][i][j][lg1 - 1][lg2], st[type][i + (1 << (lg1 - 1))][j][lg1 - 1][lg2], type);
                    }
                }
            }
        }
    }

    Log[1] = 0;
    for (int i = 2; i < NMAX; i++) {
        Log[i] = Log[i / 2] + 1;
    }
}

int get(int x1, int y1, int x2, int y2, int type) {
    int k1 = Log[(x2 - x1 + 1)], k2 = Log[(y2 - y1 + 1)];
    int ans1 = st[type][x1][y1][k1][k2],
            ans2 = st[type][x2 - (1 << k1) + 1][y1][k1][k2],
            ans3 = st[type][x1][y2 - (1 << k2) + 1][k1][k2],
            ans4 = st[type][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1][k1][k2];

    return f(f(ans1, ans2, type), f(ans3, ans4, type), type);
}

ll ans(int x1, int y1, int x2, int y2) {
    int X[] = {get(x1, y1, x2, y2, 1), get(x1, y1, x2, y2, 0)},
            Y[] = {get(x1, y1, x2, y2, 3), get(x1, y1, x2, y2, 2)};
//    cerr << "ANS " << X[0] << ' ' << Y[0] << ' ' << X[1] << ' ' << Y[1] << endl;
    if (X[0] > X[1] || Y[0] > Y[1]) return 0;
    return (X[1] - X[0]) * 1ll * (Y[1] - Y[0]);
}

ll ans_slow(int x1, int y1, int x2, int y2) {
    int X[] = {-INF, INF},
            Y[] = {-INF, INF};
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            X[0] = max(X[0], T[i][j].p[0]);
            X[1] = min(X[1], T[i][j].p[2]);
            Y[0] = max(Y[0], T[i][j].p[1]);
            Y[1] = min(Y[1], T[i][j].p[3]);
        }
    }
//    cerr << "ANS_SLOW " << X[0] << ' ' << Y[0] << ' ' << X[1] << ' ' << Y[1] << endl;
    if (X[0] > X[1] || Y[0] > Y[1]) {
        return 0;
    }
    return (X[1] - X[0]) * 1ll * (Y[1] - Y[0]);
}

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
    cin >> n >> m;
//    n = rand() % 4 + 1, m = rand() % 4 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int type = 0; type < 4; type++) {
//                T[i][j].p[type] = rand() % 200 - 100;
                cin >> T[i][j].p[type];
            }
            for (int y = 0; y < 2; y++) {
                if (T[i][j].p[y] > T[i][j].p[y + 2]) {
                    swap(T[i][j].p[y], T[i][j].p[y + 2]);
                }
            }
        }
    }

    build();
//
//    A = rand() % 1000000000, B = rand() % 1000000000, V[0] = rand() % 1000000000;
//    Q = 10000;
    cin >> Q >> A >> B >> V[0];
    for (int i = 1; i < 5000000 * 4 + 40; i++) {
        V[i] = (A * V[i - 1] + B) % 1000000007;
    }

    ll sumans = 0;

    for (int k = 1; k <= Q; k++) {
        int r1 = V[(4 * k - 3)] % n, c1 = V[(4 * k - 2)] % m, r2 = V[(4 * k - 1)] % n, c2 = V[(4 * k)] % m;
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
        sumans = (sumans + ans(r1, c1, r2, c2)) % 1000000007;
    }
    cout << sumans;
}