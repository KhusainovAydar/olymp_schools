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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 200050;

int n, q, s, t;
int S[3][NMAX];
int a[NMAX];

int d[3][4 * NMAX];
int tree[3][4 * NMAX];

void build(int v, int tl, int tr, int id) {
    if (tl == tr) {
        tree[id][v] = S[id][tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm, id);
        build(2 * v + 2, tm + 1, tr, id);
        tree[id][v] = tree[id][2 * v + 1] + tree[id][2 * v + 2];
    }
}

void push(int v, int id) {
    d[id][2 * v + 1] += d[id][v];
    d[id][2 * v + 2] += d[id][v];
    d[id][v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int val, int id) {
    if (l > r || tl > r || l > tr) {
        return;
    }
    if (l == tl && tr == r) {
        d[id][v] += val;
        return;
    }
    push(v, id);
    int tm = (tl + tr) >> 1;
    upd(2 * v + 1, tl, tm, l, min(r, tm), val, id);
    upd(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val, id);
    tree[id][v] = tree[id][2 * v + 1] + d[id][2 * v + 1] + tree[id][2 * v + 2] + d[id][2 * v + 2];
}

int getsum(int v, int tl, int tr, int l, int r, int id) {
    if (l > r || tl > r || l > tr) {
        return 0;
    }
    if (l == tl && tr == r) {
        return tree[id][v] + d[id][v];
    }
    push(v, id);
    int tm = (tl + tr) >> 1;
    int ans = getsum(2 * v + 1, tl, tm, l, min(r, tm), id) +
                getsum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, id);
    tree[id][v] = tree[id][2 * v + 1] + d[id][2 * v + 1] + tree[id][2 * v + 2] + d[id][2 * v + 2];
    return ans;
}


int main() {
    srand((unsigned int)time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("substr3.in", "r", stdin);
//    freopen("substr3.out", "w", stdout);
#endif
    cin >> n >> q >> s >> t;
    for (int i = 0; i <= n; i++) {
        cin >> S[0][i];
    }

    // A = 0, S = 1, T = 2
    for (int i = 1; i <= n; i++) {
        if (S[0][i] > S[0][i - 1]) {
            S[1][i] = S[1][i - 1] + S[0][i - 1] - S[0][i];
            S[2][i] = S[2][i - 1];
        } else {
            S[2][i] = S[2][i - 1] + S[0][i - 1] - S[0][i];
            S[1][i] = S[1][i - 1];
        }
    }

//    for (int i = 1; i <= n; i++) {
//        cerr << S[1][i] << ' ';
//    }
//    cerr << endl;
//    for (int i = 1; i <= n; i++) {
//        cerr << S[2][i] << ' ';
//    }
//    cerr << endl;

    for (int i = 0; i < 3; i++) {
        build(0, 0, n, i);
    }

//    cerr << getsum(0, 0, n, n, n, 1) << ' ' << getsum(0, 0, n, n, n, 2) << endl;

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;

        // удаление
        S[0][l - 1] = getsum(0, 0, n, l - 1, l - 1, 0);
        S[0][l] = getsum(0, 0, n, l, l, 0);
        int L = S[0][l - 1], R = S[0][l];
        int val = S[0][l - 1] - S[0][l];

        if (S[0][l - 1] < S[0][l]) {
            upd(0, 0, n, l, n, -val, 1);
        } else {
            upd(0, 0, n, l, n, -val, 2);
        }

        S[0][r] = getsum(0, 0, n, r, r, 0);
        S[0][r + 1] = getsum(0, 0, n, r + 1, r + 1, 0);

        val = S[0][r] - S[0][r + 1];

        if (S[0][r] < S[0][r + 1]) {
            upd(0, 0, n, r + 1, n, -val, 1);
        } else {
            upd(0, 0, n, r + 1, n, -val, 2);
        }

        upd(0, 0, n, l, r, x, 0);

        // добавление

        S[0][l - 1] = getsum(0, 0, n, l - 1, l - 1, 0);
        S[0][l] = getsum(0, 0, n, l, l, 0);
        val = S[0][l - 1] - S[0][l];

        if (S[0][l - 1] < S[0][l]) {
            upd(0, 0, n, l, n, val, 1);
        } else {
            upd(0, 0, n, l, n, val, 2);
        }

        S[0][r] = getsum(0, 0, n, r, r, 0);
        S[0][r + 1] = getsum(0, 0, n, r + 1, r + 1, 0);

        val = S[0][r] - S[0][r + 1];

        if (S[0][r] < S[0][r + 1]) {
            upd(0, 0, n, r + 1, n, val, 1);
        } else {
            upd(0, 0, n, r + 1, n, val, 2);
        }

//        cerr << getsum(0, 0, n, n, n, 1) << ' ' << getsum(0, 0, n, n, n, 2) << endl;

        ll ans = getsum(0, 0, n, n, n, 1) * 1ll * s + getsum(0, 0, n, n, n, 2) * 1ll * t;
        cout << ans << endl;
    }
}