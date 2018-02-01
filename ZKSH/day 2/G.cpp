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

const int NMAX = 100005;

ll a[NMAX], t[4 * NMAX], d[4 * NMAX], D[NMAX];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm);
        build(2 * v + 2, tm + 1, tr);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

void push(int v) {
    ll val = d[v];
    d[2 * v + 1] += val;
    d[2 * v + 2] += val;
    d[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r || tl > r || l > tr || tl > tr) {
        return;
    }
    if (l == tl && tr == r) {
        d[v] += val;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    upd(2 * v + 1, tl, tm, l, min(r, tm), val);
    upd(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[2 * v + 1] + d[2 * v + 1] * (tm - tl + 1) + t[2 * v + 2] + d[2 * v + 2] * (tr - tm);

}

ll getsum(int v, int tl, int tr, int l, int r) {
    if (l > r || tl > r || l > tr || l > r) {
        return 0;
    }
    if (l == tl && tr == r) {
        ll ans = t[v] + d[v] * (tr - tl + 1);
        return ans;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    ll ans = getsum(2 * v + 1, tl, tm, l, min(r, tm)) +
              getsum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
    t[v] = t[2 * v + 1] + d[2 * v + 1] * (tm - tl + 1) + t[2 * v + 2] + d[2 * v + 2] * (tr - tm);
    return ans;
}

int main() {
//    srand((unsigned int)time(NULL));
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
//    freopen("flow2.in", "r", stdin);
//    freopen("flow2.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            l--, r--;
            upd(0, 0, n - 1, l, r, c);
//            for (int i = l; i <= r; i++) {
//                a[i] += c;
//            }
        } else if (type == 2) {
            ll d, c;
            cin >> d >> c;
            if (d * d >= n) {
                for (ll i = d; i <= n; i += d) {
                    upd(0, 0, n - 1, i - 1, i - 1, c);
                }
            } else {
                D[d] += c;
            }
        } else if (type == 3) {
            ll l, r;
            cin >> l >> r;
            ll sum = 0;
            for (ll i = 1; i * i <= n; i++) {
                sum += (r / i) * D[i] - max(0ll, (l / i) - (l % i == 0)) * D[i];
            }
            l--, r--;
            sum += getsum(0, 0, n - 1, l, r);

//            ll sum1 = 0;
//            for (int i = l; i <= r; i++) {
//                sum1 += a[i];
//            }
            cout << sum << endl;
        }
    }
}